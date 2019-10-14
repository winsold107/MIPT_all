#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void FloydWallsher (vector<vector<int>>& mtx, int n){
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                mtx[i][j] = min (mtx[i][j], mtx[i][k] + mtx[k][j]);

}

int main() {
    ifstream fin("floyd.in");
    ofstream fout("floyd.out");
    int n;
    fin >> n;
    int val;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            fin >> val;
            matrix[k][i] = val;
        }
    }
    FloydWallsher(matrix, n);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            fout << matrix[k][i] << " ";
        }
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
//    int n;
//    cin >> n;
//    int val;
//    vector<vector<int>> matrix(n, vector<int>(n));
//    for (int k = 0; k < n; k++) {
//        for (int i = 0; i<n; i++) {
//            cin >> val;
//            matrix [k][i] = val;
//        }
//    }
//    FloydWallsher(matrix, n);
//
//    for (int k = 0; k < n; k++) {
//        for (int i = 0; i<n; i++) {
//            cout << matrix[k][i] << " ";
//        }
//        cout << "\n";
//    }
//    return 0;
//}