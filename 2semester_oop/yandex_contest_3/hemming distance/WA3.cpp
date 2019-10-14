//#include<iostream>
//#include<vector>
//#include <limits>
//#include <cassert>
//#include <algorithm>
//#include <functional>
//
//using namespace std;
//
//static constexpr int INF = numeric_limits<int>::max();
//
//struct Edge {
//    int from, to, cap, flow;
//};
//
//using Graph = vector<vector<int>>;
//using Edges = vector<Edge>;
//
//inline void updateEdge(int from, int to, int cap, Edge &v1) {
//    v1.from = from;
//    v1.to = to;
//    v1.cap = cap;
//    v1.flow = 0;
//}
//
//
//inline void addEdge(int from, int to, int capacity,
//                    Graph &g,
//                    Edges &edges)
//{
//
//    Edge e1, e2;
//    updateEdge(from, to, capacity, e1);
//    updateEdge(to, from, 0, e2);
//
//    g[from].push_back (edges.size());
//    edges.push_back (e1);
//
//    g[to].push_back (edges.size());
//    edges.push_back (e2);
//}
//
//inline bool bfs(int fin, int n,
//                Graph& g,
//                vector<int>& q,
//                vector<int>& dist,
//                Edges& vert)
//{
//    int qh=0, qt=1;
//    q[qt] = 0;
//    for (int i = 0; i<n; i++)
//        dist[i] = -1;
//    dist[0] = 0;
//    while (qh < qt && dist[fin] == -1) {
//        int v = q[qh++];
//        for (size_t i=0; i<g[v].size(); ++i) {
//            int id = g[v][i], to = vert[id].to;
//            if (dist[to] == -1 && vert[id].flow < vert[id].cap) {
//                q[qt++] = to;
//                dist[to] = dist[v] + 1;
//            }
//        }
//    }
//    return dist[fin] != -1;
//}
//
//inline int dfs(int v, int flow, int fin,
//               Graph& g,
//               vector<int>& d,
//               vector<int>& ptr,
//               Edges& vert)
//{
//    if (!flow)
//        return 0;
//    if (v == fin)
//        return flow;
//    for (; ptr[v]<g[v].size(); ptr[v]++) {
//        int id = g[v][ptr[v]],
//                to = vert[id].to;
//        if (d[to] != d[v] + 1)
//            continue;
//        if (int temp = dfs (to, min(flow, vert[id].cap - vert[id].flow), fin, g, d, ptr, vert)) {
//            vert[id].flow += temp;
//            vert[id xor 1].flow -= temp;
//            return temp;
//        }
//    }
//    return 0;
//}
//
//inline int dinic(int n, int fin,
//                 Graph g,
//                 vector<int>& q,
//                 vector<int>& dist,
//                 Edges& vert)
//{
//    vector<int> vertTemp(n);
//    int flow = 0;
//    while(true) {
//        if (!bfs(fin, n, g, q, dist, vert))
//            break;
//        for (int i = 0; i<n; i++)
//            vertTemp[i] = 0;
//        while (int temp = dfs(0, INF, fin, g, dist, vertTemp, vert))
//            flow += temp;
//    }
//    return flow;
//}
//
//int countQuest(const string& str) {
//    int res = 0;
//    for (const auto& c: str) {
//        res += (c == '?') ? 1 : 0;
//    }
//    return res;
//}
//
//vector<int> qNumToPos;
//int strQNum = -1, patternQnum = -1;
//
//inline void initGraph(Graph& graph, Edges& edges, const string& str, const string& pattern) {
//
//    vector<bool> charVisited(strQNum + patternQnum, false);
//
//    int ip = (strQNum + 2) - 1, is = (2) - 1;
//    for (int i = 0; i<str.length()-pattern.length()+1; i++) {
//        for(int j = 0; j < pattern.length(); j++) {
//            char p = pattern[j], s = str[i+j];
////            int ip = j+2 + str.size(), is = i+j+2;
//            int p_idx = j+str.size(), s_idx = i+j;
//            if ((p == '1') && (s == '0') || (p == '0') && (s == '1')) {
//                addEdge(0, 1, 1, graph, edges);
//            } else if (p == '?') {
//                if (!charVisited[p_idx]) {
//                    ip++;
//                    charVisited[p_idx] = true;
//                }
//                qNumToPos[ip-2] = p_idx;
//                if (s == '0') {
//                    addEdge(0, ip, 1, graph, edges);
//                } else if (s == '1') {
//                    addEdge(ip, 1, 1, graph, edges);
//                } else if (s == '?') {
//                    if (!charVisited[s_idx]) {
//                        is++;
//                        charVisited[s_idx] = true;
//                    }
//                    qNumToPos[is-2] = i+j;
//                    addEdge(ip, is, 1, graph, edges);
//                    addEdge(is, ip, 1, graph, edges);
//                } else {
//                    assert(!"string can contain nothing except '?', '0', '1'");
//                }
//            } else if (s == '?') {
//
//                if (!charVisited[s_idx]) {
//                    is++;
//                    charVisited[s_idx] = true;
//                }
//                qNumToPos[is-2] = i+j;
//                if (p == '0') {
//                    addEdge(0, is, 1, graph, edges);
//                } else if (p == '1') {
//                    addEdge(is, 1, 1, graph, edges);
//                } else { assert(false); }
//            }
//        }
//    }
//}
//
//inline int calcGraphSize(const string& str, const string& pattern) {
////    size_t questionsNum = 0;
////    for_each(str.begin(), str.end(), [&questionsNum](char c) {
////        (c == '?') ? questionsNum++ : questionsNum;
////    });
////
////    return questionsNum + 2;
//
//    strQNum = countQuest(str);
//    patternQnum = countQuest(pattern);
//
//    qNumToPos.resize(strQNum + patternQnum, -1);
//
//    return strQNum + patternQnum + 2;
//}
//
//inline void setQuestion(int graphIdx, char value, string &str, string &pattern) {
//    int qNum = graphIdx-2;
//    assert(qNum >= 0);
//
//
//    int qPos = qNumToPos[qNum];
//    if (qPos < 0) {
//        assert(qPos >= 0);
//    }
//
//    if (qPos >= str.length()) {
//        qPos -= str.length();
//        assert(qPos >= 0);
//        pattern[qPos] = value;
//    } else {
//        assert(qPos >= 0);
//        str[qPos] = value;
//    }
//}
//
//
//
//inline void fillQuestions(const Graph& graph, const Edges& edges, string& str, string& pattern) {
//    using Visited = vector<bool>;
//
//    Visited visited(graph.size(), false);
//
//// https://stackoverflow.com/questions/2067988/recursive-lambda-functions-in-c11
//    function<void(int, const Graph&, const Edges&)> fillZeros;
//
//    fillZeros = [&visited, &str, &pattern, &fillZeros](int v, const Graph& graph, const Edges& edges) {
//        if (v >= 2) {
//            setQuestion(v, '0', str, pattern);
//        }
//        visited[v] = true;
//
//        for(int i = 0; i < graph[v].size(); i++) {
//
//            int ie = graph[v][i],
//                    to = edges[ie].to;
//
//            if (!visited[to] && edges[ie].cap > edges[ie].flow) {
//                fillZeros(to, graph, edges);
//            }
//        }
//    };
//
//    fillZeros(0, graph, edges);
//
//    // Fill ones
//    for (auto& c: str) {
//        c = ((c == '?') ? '1' : c);
//    }
//    for (auto& c: pattern) {
//        c = ((c == '?') ? '1' : c);
//    }
//
//}
//
//inline int hemDist(string& str, string& pattern) {
//
//    int size = calcGraphSize(str, pattern);
//
//    Graph graph(size);
//    Edges edges;
//
//    initGraph(graph, edges, str, pattern);
//
//    vector <int> dist(size), vertTemp(size), q(size);
//
//    int maxFlow = dinic(size, 1, graph, q, dist, edges);
//    fillQuestions(graph, edges, str, pattern);
//
//    return maxFlow;
//}
//
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//
//    string pattern, str;
//    cin >> str >> pattern;
//
//    cout << hemDist(str, pattern) << endl;
//    cout << str << endl;
//    cout << pattern;
//}
