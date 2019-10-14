//#include <iostream>
//#include <vector>
//#include <set>
//#include <limits>
//#include <map>
//#include <cassert>
//
//using namespace std;
//
//static constexpr int INF = numeric_limits<int>::max();
//
//struct To {
//    int to, cost;
//    To(int _t, int _w) : to(_t), cost(_w) {};
//};
//
//
//using WeightedGraph = vector<vector<To>>;
//using Graph = map<int, int>;
//
//int getEdge(const WeightedGraph& graph, int v1, int v2) {
//    try {
//        auto beg = graph.at(v1).begin(),
//             end = graph.at(v1).end();
//        for (auto it = beg; it != end; ++it) {
//            if (it->to == v2) {
//                return it->cost;
//            }
//        }
//    } catch (out_of_range&) {
//        auto beg = graph.at(v2).begin(),
//             end = graph.at(v2).end();
//        for (auto it = beg; it != end; ++it) {
//            if (it->to == v1) {
//                return it->cost;
//            }
//        }
//    }
//    assert(!"something went wrong");
//};
//
//void prima(WeightedGraph& graph, const int m, const int n, int result) {
//
//    vector<int> min_edge(graph.size(), INF),
//                to_edge(graph.size(), -1);
//    vector<pair<int,int>> min_ostov(graph.size());
//    vector<bool> used(graph.size(), false);
//
//    min_edge[0] = 0;
//    set<pair<int, int>> q;
//
//
//    q.insert(make_pair(0, 0));
//
//    for (int i = 0; i < n; ++i) {
//        if ((q.empty()) && (result == 0)) {
//            cout << 0;
//            return;
//        }
//
//        else if ((q.empty()) && (result != 0)) {
//            cout << result;
//            return;
//        }
//
//        int v = q.begin()->second;
//        q.erase(q.begin());
//
//        used[v] = true;
//        int counter = 0;
//        if (to_edge[v] != -1) {
////            cout << v << " " << to_edge[v] << endl;
////            for (int l = 0; l < min_ostov.size(); l++) {
////                if ((min_ostov[l].first == to_edge[v]) & (min_ostov[l].second == v)) {
////                    counter++;
////                    break;
////                }
////            }
////            if (counter == 0) {
////                // cout << v + 1 << " " << to_edge[v] + 1 << endl;
////                min_ostov.emplace_back(make_pair(v, to_edge[v]));
////                for (int k = 0; k < graph[v].size(); k++) {
////                    if (graph[v][k].to == to_edge[v]) {
////                        result = result + graph[v][k].cost;
////                        break;
////                    }
////                }
////            }
//            result += getEdge(graph, v, to_edge[v]);
//        }
//        for (int p = 0; p < graph[v].size(); ++p) {
//            int to = graph[v][p].to,
//                    cost = graph[v][p].cost;
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
//
//void addEdge(WeightedGraph& graph, int from, int to, int cost) {
//    bool found = false;
//    for (auto &it : graph[from]) {
//        if (it.to == to) {
//            it.cost = min(it.cost, cost);
//            found = true;
//        }
//    }
//
//    if (!found) {
//        graph[from].emplace_back(To(to, cost));
//    }
//
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//
//    int n, m;
//    cin >> n >> m;
//    int from, to, cost;
//    WeightedGraph NOgraph(n);
//
//    for (int i = 0; i < m; i++) {
//        cin >> from >> to >> cost;
//        addEdge(NOgraph, from-1, to-1, cost);
//        addEdge(NOgraph, to-1, from-1, cost);
//    }
//
//    prima(NOgraph, m, n, 0);
//
//    return 0;
//}
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