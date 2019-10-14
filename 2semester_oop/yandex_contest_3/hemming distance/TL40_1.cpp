//
// Created by darin on 29.04.18.
//
#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;

class Hamming {
public:

    struct Edge {
        int to, cap, flow;
    };

    using Graph = vector<vector<int>>;
    using Edges = vector<Edge>;
    using Visited = vector<bool>;
    using cstring = char*;

public:
    static constexpr int INF = numeric_limits<int>::max();
    static constexpr int DRAIN = 1, MAX_LEN = 1001;

public:
    Hamming(cstring str, cstring pattern) :
            _pattern(pattern), _str(str),
            _patternLen(strlen(_pattern)), _strLen(strlen(_str)),
            _vNum(calcVertexCount()),
            _graph(_vNum), _edgesLen(0)/*, _dist(_vNum), _queue(_vNum)*/
    {
        _init();
    }

    size_t calcQNum() {
        if (_strQNum == -1 || _patternQNum == -1) {

            _strQNum = 0; _patternQNum = 0;


            int qCounter = 0;
            for (int i = 0; i < _strLen; ++i) {
                if (_str[i] == '?') {
                    _strQNum++;

                    _qIdxToNumer[i] = qCounter;
                    _qNumerToIdx[qCounter++] = i;
                }
            }

            for (int i = 0; i < _patternLen; ++i) {
                if (_pattern[i] == '?') {
                    _patternQNum++;

                    _qIdxToNumer[_strLen + i] = qCounter;
                    _qNumerToIdx[qCounter++] = _strLen + i;
                }
            }
        }

        return static_cast<size_t>(_strQNum + _patternQNum);
    }

    size_t calcVertexCount() {
        return calcQNum() + 2;

    }

    int calcHammingDistance() {
        int maxFlow = _dinic();
        return maxFlow;
    }

    int fillQuestions() {
        _fillQuestions();
    }

    void printResult() {
        printf("%s\n", _str);
        printf("%s", _pattern);
    }

private:

    void _init() {
        _initGraph();
    }

    void _initGraph() {

        for (int i = 0; i<_strLen-_patternLen+1; i++) {
            for(int j = 0; j < _patternLen; j++) {

                // Символы в оригинальных строках
                char p = _pattern[j], s = _str[i+j];

                // (Индексы симоволов в склейке оригинальных строк) + 2
                int ip = 2+j+_strLen, is = 2+i+j;

                // Indices in graph counters
                int igs = _qIdxToNumer[is-2]+2, igp = _qIdxToNumer[ip-2]+2;

                if ((p == '1') && (s == '0') || (p == '0') && (s == '1')) {
                    _addEdge(0, 1, 1);
                } else if (p == '?') {
//                    assert(_qIdxToNumer[ip-2] != -1);
                    if (s == '0') {
                        _addEdge(0, igp, 1);
                    } else if (s == '1') {
                        _addEdge(igp, 1, 1);
                    } else if (s == '?') {
//                        assert(_qIdxToNumer[is-2] != -1);
                        _addEdge(igp, igs, 1);
                        _addEdge(igs, igp, 1);
                    } else {
//                        assert(!"string can contain nothing except '?', '0', '1'");
                    }
                } else if (s == '?') {
//                    assert(_qIdxToNumer[is-2] != -1);
                    if (p == '0') {
                        _addEdge(0, igs, 1);
                    } else if (p == '1') {
                        _addEdge(igs, 1, 1);
                    }
//                    else {
////                        assert(false);
//                    }
                }
            }
        }
    }

    int _dinic() {
        vector<int> ptr(_vNum, 0);

        int flow = 0;
        while(true) {
            if (!_bfs())
                break;
            for (int i = 0; i<_vNum; i++)
                ptr[i] = 0;
            int lastV = 0;
            while (int temp = _dfs(lastV, INF, ptr, lastV))
                flow += temp;
        }
        return flow;
    }

    int _dfs(int v, int flow, vector<int> &ptr, int& lastv) {
        if (flow == 0 || v == DRAIN) {
            lastv = v;
            return flow;
        }

        for (; ptr[v]<_graph[v].size(); ptr[v]++) {

            int id = _graph[v][ptr[v]],
                    to = _edges[id].to;

            if (_dist[to] != _dist[v] + 1)
                continue;

            if (int temp = _dfs(to, min(flow, _edges[id].cap - _edges[id].flow), ptr, lastv)) {
                _edges[id].flow += temp;
                _edges[id xor 1].flow -= temp;
                lastv = v;
                return temp;
            }
        }
        return 0;
    }

    bool _bfs() {
        int qh=0, qt=1;
        _queue[qt] = 0;

        for (int i = 0; i<_vNum; i++)
            _dist[i] = -1;
        _dist[0] = 0;

        while (qh < qt && _dist[DRAIN] == -1) {
            int v = _queue[qh++];
            for (size_t i=0; i<_graph[v].size(); ++i) {
                int id = _graph[v][i], to = _edges[id].to;
                if (_dist[to] == -1 && _edges[id].flow < _edges[id].cap) {
                    _queue[qt++] = to;
                    _dist[to] = _dist[v] + 1;
                }
            }
        }
        return _dist[DRAIN] != -1;
    }

    void _addEdge(int from, int to, int capacity) {

        Edge e1 = {to, capacity, 0},
                e2 = {from, 0, 0};

        _graph[from].push_back(_edgesLen);
        _edges[_edgesLen++] = e1;

        _graph[to].push_back(_edgesLen);
        _edges[_edgesLen++] = e2;
    }

    void _setQuestion(int graphIdx, char value, cstring str, cstring pattern) {
        int idx = _qNumerToIdx[graphIdx-2];
//        assert(idx >= 0);

        if (idx >= _strLen) {
            idx -= _strLen;
            pattern[idx] = value;
        } else {
            str[idx] = value;
        }
    }

    void _fillZerosDFS(int v, vector<bool> &visited) {
        if (v >= 2) {
            _setQuestion(v, '0', _str, _pattern);
        }
        visited[v] = true;

        for(int i = 0; i < _graph[v].size(); i++) {

            int ie = _graph[v][i],
                    to = _edges[ie].to;

            if (!visited[to] && _edges[ie].cap > _edges[ie].flow) {
                _fillZerosDFS(to, visited);
            }
        }
    }

    void _fillQuestions() {
        Visited visited(_graph.size(), false);

        _fillZerosDFS(0, visited);

        // Fill '?' with ones
        for (int i = 0; i < _strLen; ++i) {
            if (_str[i] == '?') {
                _str[i] = '1';
            }
        }

        for (int i = 0; i < _patternLen; ++i) {
            if (_pattern[i] == '?') {
                _pattern[i] = '1';
            }
        }

    }

private:

    cstring _str, _pattern;
    size_t _strLen, _patternLen;
    int _qIdxToNumer[MAX_LEN*2], _qNumerToIdx[MAX_LEN*2];

    int _strQNum = -1, _patternQNum = -1;

    size_t _vNum;

    Graph _graph;
    Edge _edges[MAX_LEN*MAX_LEN];
    size_t _edgesLen;

    int _dist[MAX_LEN*2], _queue[MAX_LEN*2];
};

int main() {
    ios_base::sync_with_stdio(false);

    char pattern[Hamming::MAX_LEN], str[Hamming::MAX_LEN];
    scanf("%s", str); scanf("%s", pattern);

    Hamming hamming(str, pattern);

    printf("%d\n", hamming.calcHammingDistance());
    hamming.fillQuestions();
    hamming.printResult();
}
