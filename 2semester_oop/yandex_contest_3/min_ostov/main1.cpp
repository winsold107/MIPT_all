//#include <iostream>
//#include <vector>
//#include <set>
//#include <limits>
//#include <unordered_map>
//#include <map>
//#include <cassert>
//
//using namespace std;
//
//static constexpr int INF = numeric_limits<int>::max();
//
//using WeightedGraph = map<int, map<int, int>>;
//using Graph = map<int, int>;
//
//bool hasEdge(const WeightedGraph& graph, int v1, int v2) {
//    return
//            (graph.find(v1) != graph.end() && graph.at(v1).find(v2) != graph.at(v1).end()) ||
//            (graph.find(v2) != graph.end() && graph.at(v2).find(v1) != graph.at(v2).end());
//};
//
//int getEdge(const WeightedGraph& graph, int v1, int v2) {
//    try {
//        return graph.at(v1).at(v2);
//    } catch (out_of_range&) {
//        return graph.at(v2).at(v1);
//    }
//};
//
//void prima(const WeightedGraph& weightedGraph, const int m, const int n, int result) {
//
//    vector<int> min_edge(n, INF),
//                to_edge(n, -1);
//
//    Graph min_ostov;
//    vector<bool> used(n, false);
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
//
//            for (const auto& edge: min_ostov) {
//                if (edge.first == to_edge[v] && edge.second == v) {
//                    counter++;
//                    break;
//                }
//            }
//
//            if (counter == 0) {
//
//                min_ostov[v] = to_edge[v];
//                for (const auto& it: weightedGraph.at(v)) {
//                    if (it.first == to_edge[v]) {
//                        result += it.second;
//                        break;
//                    }
//                }
//
//            }
//        }
//
//
//        for (const auto& it: weightedGraph.at(v)) {
//            int to = it.first, cost = it.second;
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
//template <typename MapType, typename Key>
//bool hasKey(const MapType& givenMap, const Key& key) {
//    return givenMap.find(key) != givenMap.end();
//};
//
//
//void addEdge(WeightedGraph& graph, int from, int to, int cost) {
//    if (!hasKey(graph, from)) {
//        graph[from] = map<int, int>();
//    }
//
//    int oldCost = INF;
//    if (hasKey(graph[from], to)) { oldCost = graph[from][to]; }
//
//    graph[from][to] = min(oldCost, cost);
//
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    int from, to, cost;
//    WeightedGraph NOgraph;
//
//    for (int i = 0; i < m; i++) {
//        cin >> from >> to >> cost;
//        addEdge(NOgraph, from-1, to-1, cost);
//        addEdge(NOgraph, to-1, from-1, cost);
//
//    }
//
//    prima(NOgraph, m, n, 0);
//
//    return 0;
//}
