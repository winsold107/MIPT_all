#include<iostream>
#include<vector>
using namespace std;

int timer;

void dfs (int v, int p, vector<int>& in_vec, vector<vector<int>>& up, vector<vector<int>>& g, vector<int>& out_vec, int l) {
    in_vec[v] = ++timer;
    up[v][0] = p;
    
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v, in_vec, up, g, out_vec, l);
    }
    
    out_vec[v] = ++timer;
}

bool secLift (int a, int b, vector<int>& in_vec, vector<int>& out_vec) {
    return in_vec[a] <= in_vec[b] && out_vec[a] >= out_vec[b];
}

long long lca (long long a, long long b, vector<vector<int>>& up, int l, vector<int>& in_vec, vector<int>& out_vec) {
    if (secLift (a, b, in_vec, out_vec))
        return a;
    if (secLift (b, a, in_vec, out_vec))
        return b;
    for (int i=l; i >= 0; --i)
        if (! secLift (up[a][i], b, in_vec, out_vec))
            a = up[a][i];
    return up[a][0];
}

int main() {
    int n, l, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in_vec(n), out_vec(n);
    vector<vector<int>> up(n);

    for (int i = 0; i < n-1; i++){
        int val;
        cin >> val;
        g[val].push_back(i+1);
    }

    l = 1;
    while ((1 << l) <= n)
        ++l;
    for (int i=0; i<n; ++i)
        up[i].resize (l+1);
    dfs (0, 0, in_vec, up, g, out_vec, l);

    long long x, y, z, v;
    long long a1, a2, r, s;
    cin >> r >> s;
    cin >> x >> y >> z;
    long long answer = 0;
    a1 = r;
    a2 = s;
    for (int i = 0; i < m; i++) {
        v = lca (r, s, up, l, in_vec, out_vec);
        answer += v;
        a1 = (x*a1 + y*a2 + z) % n;
        a2 = (x*a2 + y*a1 + z) % n;
        r = (a1 + v) % n;
        s = a2;
    }
    cout << answer;
    return 0;
}

//3 2
//0 1
//2 1
//1 1 0

//5 2
//0 0 1 1
//3 4
//1 1 1

//10 3
//6 0 0 7 9 2 9 0 1
//8 7
//1 1 0