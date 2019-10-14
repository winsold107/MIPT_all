#include<iostream>
#include<vector>
#include<limits>

using namespace std;

const int infinity = numeric_limits<int>::max();

struct vertice {
    int from, to, cap, flow;
};

void vertCreate (int from, int to, int cap, vertice& v1){
    v1.from = from;
    v1.to = to;
    v1.cap = cap;
    v1.flow = 0;
}

void addVertice (int from, int to, vector<vector<int>>& g, vector<vertice>& vert, vertice& e1, vertice& e2) {
    g[from].push_back (vert.size());
    vert.push_back (e1);
    g[to].push_back (vert.size());
    vert.push_back (e2);
}

bool bfs(int fin, int n, vector<vector<int>>& g, vector<int>& q, vector<int>& dist, vector<vertice>& vert) {
    int qh=0, qt=1;
    q[qt] = 0;
    for (int i = 0; i<n; i++)
        dist[i] = -1;
    dist[0] = 0;
    while (qh < qt && dist[fin] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i], to = vert[id].to;
            if (dist[to] == -1 && vert[id].flow < vert[id].cap) {
                q[qt++] = to;
                dist[to] = dist[v] + 1;
            }
        }
    }
    return dist[fin] != -1;
}

int dfs (int v, int flow, int fin, vector<vector<int>>& g, vector<int>& d, vector<int>& ptr, vector<vertice>& vert) {
    if (!flow)
        return 0;
    if (v == fin)
        return flow;
    for (; ptr[v]<g[v].size(); ptr[v]++) {
        int id = g[v][ptr[v]],
                to = vert[id].to;
        if (d[to] != d[v] + 1)
            continue;
        if (int temp = dfs (to, min (flow, vert[id].cap - vert[id].flow), fin, g, d, ptr, vert)) {
            vert[id].flow += temp;
            vert[id xor 1].flow -= temp;
            return temp;
        }
    }
    return 0;
}

int dinic(int n, int fin, vector<vector<int>> g, vector<int>& q, vector<int>& dist, vector<vertice>& vert, vector<int>& vertTemp) {
    int flow = 0;
    while(true) {
        if (!bfs(fin, n, g, q, dist, vert))
            break;
        for (int i = 0; i<n; i++)
            vertTemp[i] = 0;
        while (int temp = dfs (0, infinity, fin, g, dist, vertTemp, vert))
            flow += temp;
    }
    return flow;
}

int main(){
    int n, m, from, to, cap;
    cin >> n >> m;
    vector<vector<int>> vertices(n);
    vector <int> dist(n), vertTemp(n), q(n);// vertTemp запоминает на каком ребре остановились для v вершины,
                                            // q имитация очереди (но не очередь)
    vector<vertice> vert;
    int finish = n-1;
    for (int i = 0; i < m; i++){    
        cin >> from >> to >> cap;
        int a = 0;
        vertice e1, e2;
        vertCreate(from - 1, to - 1, cap, e1);
        vertCreate(to - 1, from - 1, 0, e2);
        addVertice(from - 1, to - 1, vertices, vert, e1, e2);
        a = 0;
    }
    cout << dinic(n, finish, vertices, q, dist, vert, vertTemp);
}

