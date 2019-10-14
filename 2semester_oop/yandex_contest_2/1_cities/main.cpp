#include<iostream>
#include<vector>
#include<limits>
#include<set>
using namespace std;

int Dijkstra(int start, int end, vector<vector<pair<int, int>>>cityRoads, int cityAmount){
    int maximum = numeric_limits<int>::max();
    vector<int> distances (cityAmount, maximum);
    distances[start] = 0;
    set < pair<int,int> > citySet;
    citySet.insert (make_pair (distances[start], start));
    while (!citySet.empty()) {
        int v = citySet.begin()->second;
        citySet.erase (citySet.begin());

        for (size_t j=0; j<cityRoads[v].size(); ++j) {
            int to = cityRoads[v][j].first,
                    len = cityRoads[v][j].second;
            if (distances[v] + len < distances[to]) {
                citySet.erase (make_pair (distances[to], to));
                distances[to] = distances[v] + len;
                citySet.insert (make_pair (distances[to], to));
            }
        }
    }
    return distances[end];
}

int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    int from, to, val;
    vector<vector<pair<int,int>>> NOGraph (n);
    for (int i = 0; i<m; i++){
        cin>> from >> to >> val;
        NOGraph[from].emplace_back(make_pair(to, val));
        NOGraph[to].emplace_back(make_pair(from, val));
    }
    int start;
    int end;
    cin >> start;
    cin >> end;

    cout << Dijkstra(start, end, NOGraph, n);
    return 0;
}


//#include <iostream>
//#include <vector>
//#include <limits>
//#include <map>
//
//using namespace std;
//
//
//void Dijkstra(int st, int n, int en, map<int, map<int, int>>& NOGraph, vector<bool>& visited, vector<int>& minDist) {
//    int maximum = numeric_limits<int>::max();
//
//    for (int i = 0; i < n; i++) {
//        if (NOGraph[st].find(i) != NOGraph[st].end())
//            minDist[i] = NOGraph[st][i];
//
//        visited[i] = false;
//    }
//
//    if (NOGraph[st].find(st) != NOGraph[st].end())
//        minDist[st] = NOGraph[st][st];
////    else
////        minDist[st] = 0;
//
//    int index = 0, u = 0;
//
//    for (int i = 0; i < n; i++) {
//        int minimum = maximum;
////        for (int j = 0; j < n; j++) {
//        auto b = NOGraph[i].begin();
//        auto e = NOGraph[i].end();
//
//        for(auto j = b; j != e; ++j) {
//            int t = j->first;
//            if (!visited[t] && minDist[t] < minimum) {
//                minimum = minDist[t];
//                index = t;
//            }
//        }
//
//        u = index;
//        visited[u] = true;
//
//        b = NOGraph[u].begin();
//        e = NOGraph[u].end();
//
//        for(auto j = b; j != e; ++j) {
//            int q = j->first;
//
//            if (!visited[q] &&
//                    NOGraph[u][q] != maximum &&
//                NOGraph[u].find(q) != NOGraph[u].end() &&
//                    minDist[u] != maximum &&
//                    (minDist[u] + NOGraph[u][q] < minDist[q]))
//            {
//
//                minDist[q] = minDist[u] + NOGraph[u][q];
//            }
//        }
//
////        for (int j = 0; j < n; j++) {
////            if (!visited[j] && NOGraph[u][j] != max && minDist[u] != max && (minDist[u] + NOGraph[u][j] < minDist[j])) {
////                minDist[j] = minDist[u] + NOGraph[u][j];
////            }
////        }
//    }
//
////    for (int i = 0; i < n; i++) {
////        if (minDist[i] != max) {
////            if (i == en) {
////                cout << minDist[i] << endl;
////            }
////            else continue;
////        }
////        else
////            cout << "-1" << endl;
////    }
//
//    if (minDist[en] != maximum)
//        cout << minDist[en] << endl;
//    else
//        cout << "-1" << endl;
//}
//
//
//int main() {
//    int maximum = numeric_limits<int>::max();
//    int n, m;
//    cin >> n;
//    cin >> m;
//    int from, to, val;
//    //vector<vector<int>> matrix(n, vector<int>(n, max));
//    map<int, map<int, int>> mtx;
//    for (int i = 0; i < n; ++i) {
//        mtx[i] = map<int, int>();
//    }
//
//    for (int k = 0; k < m; k++) {
//        cin >> from >> to >> val;
////            matrix[from][to] = min(val, matrix[from][to]);
////            matrix[to][from] = min(val, matrix[to][from]);
////        if (mtx.find(from) == mtx.end()) {
////            mtx[from] = map<int, int>();
////        }
////        matrix[from].push_back(to);
////        matrix[to].push_back(from);
//
//        int v = (mtx[from].find(to) == mtx[from].end()) ? maximum : mtx[from][to];
//        mtx[from][to] = min(val, v);
//       //// mtx[from][to] = val;
//       //// mtx[to][from] = val;
//
////        if (mtx.find(to) == mtx.end()) {
////            mtx[to] = map<int, int>();
////        }
////        matrix[from].push_back(to);
////        matrix[to].push_back(from);
//       v = (mtx[to].find(from) == mtx[to].end()) ? maximum : mtx[to][from];
//       mtx[to][from] = min(val, v);
//    }
//
//    int start, end;
//    cin >> start >> end;
//    vector<bool> used(n);
//    vector<int> dists(n, maximum);
//    Dijkstra(start, n, end, mtx, used, dists);
//    return 0;
//}

