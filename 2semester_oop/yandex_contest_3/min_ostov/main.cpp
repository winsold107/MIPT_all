//#include <iostream>
//#include <vector>
//#include <set>
//#include <limits>
//
//using namespace std;
//
//static constexpr int INF = numeric_limits<int>::max();
//
//void prima(vector<vector<pair<int,int>>>& graph, const int m, int result) {
//
//    vector<int> min_edge(graph.size(), INF),
//                to_edge(graph.size(), -1);
//    vector<pair<int,int>> min_ostov(graph.size());
//    vector<bool> used(graph.size(), false);
//
//    min_edge[0] = 0;
//    multiset<pair<int, int>> q;
//
//
//    q.insert(make_pair(0, 0));
//
//    for (int i = 0; i < 2*m; ++i) {
//        if ((q.empty()) & (result == 0)) {
//            cout << 0;
//            exit(0);
//        }
//        else if ((q.empty()) & (result != 0)) {
//            cout << result;
//            exit(0);
//        }
//        int v = q.begin()->second;
//        q.erase(q.begin());
//        used[v] = true;
//        int counter = 0;
//        if (to_edge[v] != -1) {
//            for (int l = 0; l<min_ostov.size(); l++) {
//                if ((min_ostov[l].first == to_edge[v]) & (min_ostov[l].second == v)) {
//                    counter++;
//                    break;
//                }
//            }
//            if (counter == 0) {
//               // cout << v + 1 << " " << to_edge[v] + 1 << endl;
//                min_ostov.emplace_back(make_pair(v, to_edge[v]));
//                for (int k = 0; k < graph[v].size(); k++) {
//                    if (graph[v][k].first == to_edge[v]) {
//                        result = result + graph[v][k].second;
//                        break;
//                    }
//                }
//            }
//        }
//        for (int p = 0; p < graph[v].size(); ++p) {
//            int to = graph[v][p].first,
//                    cost = graph[v][p].second;
//            if (cost < min_edge[to] && !used[to]) {
//                q.erase(make_pair(min_edge[to], to));
//                min_edge[to] = cost;
//                to_edge[to] = v;
//                q.insert(make_pair(min_edge[to], to));
//            }
//        }
//    }
//    cout << result;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    int from, to, cost;
//    vector<vector<pair<int,int>>> NOgraph(n);
//
//    for (int i = 0; i<m; i++) {
//        int a = 0;
//
//        cin >> from >> to >> cost;
//        if(!NOgraph[from-1].empty()) {
//            for (int j = 0; j < NOgraph[from - 1].size(); j++) {
//                if (NOgraph[from - 1][j].first == to - 1) {
//                    int ins = NOgraph[from - 1][j].second;
//                    ins = min(ins, cost);
//                    NOgraph[from - 1].erase(NOgraph[from - 1].begin() + j);
//                    NOgraph[from - 1].emplace_back(make_pair(to - 1, ins));
//                    a++;
//                    break;
//                }
//            }
//        }
//
//        if(!NOgraph[to-1].empty()) {
//            for (int j = 0; j < NOgraph[to - 1].size(); j++) {
//                if (NOgraph[to - 1][j].first == from - 1) {
//                    int ins = NOgraph[to - 1][j].second;
//                    ins = min(ins, cost);
//                    NOgraph[to - 1].erase(NOgraph[to - 1].begin() + j);
//                    NOgraph[to - 1].emplace_back(make_pair(from - 1, ins));
//                    a++;
//                    break;
//                }
//            }
//        }
//
//        if (a > 0) {
//            continue;
//        }
//
//        else {
//                NOgraph[to - 1].emplace_back(make_pair(from - 1, cost));
//                NOgraph[from - 1].emplace_back(make_pair(to - 1, cost));
//        }
//    }
//
//    prima(NOgraph, m, 0);
//
//    return 0;
//}
//
//#include <map>
//
//map<int, map<int, int>> graph;
//
//
////4 8
////1 2 1
////1 3 3
////3 1 4
////2 3 3
////2 3 2
////3 2 2
////1 4 3
////3 4 1