#include <iostream>
#include <vector>

using namespace std;

vector<int> useV(int v, vector<vector<double>>& mtx, vector<int>& used){
    used.clear();
    for (int p = 0; p < mtx.size(); p++)
        if (mtx[p][v] != -1)
            used.push_back(p);
    return used;
}

bool arbFB(vector<vector<double>>& mtx) {
    //vector<int>vis(mtx.size());
    for (int k = 0; k < mtx.size(); k++) {
        vector<double> distance(mtx.size(), -1.0);
        distance[0] = 1.0;
        vector<int> vis(mtx.size());
        for (int i = 0; i < mtx.size() - 1; i++) {
            for (int v = 0; v < mtx.size(); v++) {
//                vis.clear();
//                for (int p = 0; p < mtx.size(); p++)
//                    {if (mtx[p][v] != -1)
//                        {vis.push_back(p);}}
                for (int u = 0; u < useV(v, mtx, vis).size(); u++) {
                    if ((distance[useV(v, mtx, vis)[u]] != -1.0) & (distance[v] < distance[useV(v, mtx, vis)[u]] * mtx[u][v]))
                    {
                        distance[v] = distance[useV(v, mtx, vis)[u]] * mtx[useV(v, mtx, vis)[u]][v];
                    }
                }
            }
        }
        for (int v = 0; v < mtx.size(); v++) {
//            vis.clear();
//            for (int p = 0; p < mtx.size(); p++)
//                if (mtx[p][v] != -1)
//                    vis.push_back(p);
            for (int u = 0; u < useV(v, mtx, vis).size(); u++) {
                if ((distance[useV(v, mtx, vis)[u]] != -1.0) & (distance[v] < distance[useV(v, mtx, vis)[u]] * mtx[useV(v, mtx, vis)[u]][v]))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    double val;
    vector<vector<double>> matrix(n, vector<double>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (i == k) {
                matrix[i][k] = 1;
            } else {
                cin >> val;
                matrix[i][k] = val;
            }
        }
    }
    if (arbFB(matrix))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}




//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <limits>
//using namespace std;
//
//struct ConvCur {
//public:
//    int fCur, tCur;
//    float rel;
//public:
//    void outin();
//};
//
//void outin(ConvCur c) {
//    cout << c.fCur << " " << c.tCur << " " << c.rel << endl;
//}
//
//void vertFill(vector<int>& vertices, vector<ConvCur>& mtx, int v){
//    vertices.clear();
//    for (int k = 0; k < mtx.size(); k++)
//        if (mtx[k].rel != -1)
//            vertices.push_back(k);
//}
//
//bool arbFB(vector<ConvCur>& mtx) {
//    // Launching B.-F. algorithm for every vertex
//    for (int k = 0; k < mtx.size(); k++) {
//        // Initializing vector storing cost of the [i]s currency
//        // in initial currency
//        vector<double> d(mtx.size(), -1.0);
//        // Initial currency
//        d[k] = 1.0;
//        vector<int> vertices(mtx.size());
//        // Relaxing vertices |V| - 1 time
//        for (int i = 0; i < mtx.size() - 1; i++) {
//            for (int v = 0; v < mtx.size(); v++) {
//                vertFill(vertices, mtx);
//                for (int u : vertices)
//                    if (d[u] != -1.0 && d[v] < d[u] * mtx[u].rel)
//                        d[v] = d[u] * mtx[u].rel;
//            }
//        }
//        // Checking for negative cycles
//        for (int v = 0; v < mtx.size(); v++) {
//            vertFill(vertices, mtx);
//            for (int u : vertices)
//                if (d[u] != -1.0 && d[v] < d[u] * mtx[u].rel)
//                    return true; // Return true if found
//        }
//    }
//    // Return false if cycle was not found
//    return false;
//}
//
//bool FordBellman(vector<ConvCur>& mtx, float v, int n)
//{
//    float maximum = numeric_limits<float>::max();
//    vector<float> dist (n, maximum);
//    dist[v] = 1.0;
//    //vector<int> p (n, -1);
//    int x;
//    for (int i=0; i<n; ++i) {
//        x = -1;
//        for (int j=0; j<n; ++j)
//            //if (dist[mtx[j].fCur] < maximum)
//                if (dist[mtx[j].tCur] > dist[mtx[j].fCur] * mtx[j].rel) {
//                    dist[mtx[j].tCur] = max (-maximum, static_cast <float> (dist[mtx[j].fCur]) * mtx[j].rel);
//                    //p[e[j].b] = e[j].a;
//                    x = mtx[j].tCur;
//                }
//    }
//
//    if (x == -1)
//        return false;
//    else {
//        return true;
//    }
//}
//
//
//int main() {
//    int n;
//    cin >> n;
//    float val;
//    vector<ConvCur>matrix;
//    for (int i = 0; i<n; i++) {
//        for (int k = 0; k<n; k++) {
//            ConvCur* ccp = new ConvCur();
//            ConvCur& cc = *ccp;
//            cc.fCur = i;
//            cc.tCur = k;
//            if (i == k) {
//                cc.rel = 1.0;
//            }
//            else {
//                cin >> val;
//                cc.rel = val;
//            }
//            matrix.push_back(cc);
//        }
//    }
//    cout << endl;
//    for (int i = 0; i<matrix.size(); i++) {
//        outin(matrix[i]);
//    }
//    //for (int i = 0; i<matrix.size(); i++) {
//        //if (FordBellman(matrix, matrix[i].fCur, matrix.size())){
//        if (arbFB(matrix))
//            cout << "YES";
//        //    break;
//        else
//        //    if (i!=matrix.size() - 1) {
//        //        continue;
//        //    }
//        //    else {
//                cout << "NO";
//        //}
//    //    else { cout << "NO";}
//   // }
//    return 0;
//}

