#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

pair<int, int> MinPair (pair<int, int>& a, pair<int, int>& b) {
    pair<int, int> ans;
    vector<int> ord {a.first, a.second, b.first, b.second};
    sort(ord.begin(), ord.end());

    ans.first = ord[0];
    ans.second = ord[0];

    for (int i = 1; i < 4; i++) {
        if (ord[i] != ord[0]) {
            ans.second = ord[i];
            break;
        }
    }

    return ans;
}


void SparseTable(int n, vector<vector<pair<int, int>>>& st, vector<int>& arr) {
    st[0].resize(n);
    for (int i = 0; i < n; i++) {
        st[0][i].first = arr[i];
        st[0][i].second = arr[i];
    }

    int log2n = ceil(log2(n));

    for (int i = 1; i < log2n; i++) {
        st[i].resize(n - (1 << i) + 1);
        for (int j = 0; j < n - (1 << i) + 1; j++) {
            pair<int, int> minpair = MinPair(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            st[i][j].first = minpair.first;
            st[i][j].second = minpair.second;
        }
    }
}


int RMQ2(int i, int j, vector<vector<pair<int, int>>>& st, vector<int>& arr)
{
    int k = arr[j - i + 1] - 1;
    return MinPair(st[k][i], st[k][j - (1 << k) + 1]).second;
}


int main()
{
//    fstream cin("input.txt");


    int am, qu;
    int num;
    cin >> am >> qu;

    vector<int> logarythmed_arr(am+1);
    for (int i = 0; i < am+1; i++){
        logarythmed_arr[i] = ceil(log2(i));
    }

    vector<vector<pair<int, int>>> sparse_table(logarythmed_arr[am]);
    vector<int> arr(am);
    for (int i = 0; i < am; i++) {
        cin >> num;
        arr[i] = num;
    }



    SparseTable(am, sparse_table, arr);

    for (int i = 0; i < qu; i++) {
        int x, y;
        cin >> x >> y;
        cout << RMQ2(x-1, y-1, sparse_table, logarythmed_arr) << endl;
    }

    return 0;
}

//10 3
//1 2 3 4 5 6 7 8 9 10
//1 2
//1 10
//2 7

//5 2
//123456789123456789 123456789123456789 1 2 123456789123456789
//1 2
//3 5
