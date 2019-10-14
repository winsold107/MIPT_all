#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

typedef int s;

struct vosminashka {
    vosminashka() {};
    //vosminashka(vosminashka& state);
    //vosminashka(vector<int>& pos);

    vosminashka up();
    vosminashka down();
    vosminashka left();
    vosminashka right();

    vector<s> current;
    int zeroIndex{};
    char move{};
    vector<s> parent;

};

vosminashka vosminashka::up(){
    //if (zeroIndex >= 3) {
        vosminashka child(*this);
        child.parent = current;
        child.zeroIndex  = zeroIndex - 3;
        child.move = 'U';
        vector<s> temp;
        temp = current;
        swap(temp[zeroIndex], temp[zeroIndex - 3]);
        child.current = temp;
        return child;
    //}
}

vosminashka vosminashka::down(){
    //if (zeroIndex <= 5) {
        vosminashka child(*this);
        child.parent = current;
        child.zeroIndex  = zeroIndex + 3;
        child.move = 'D';
        vector<s> temp;
        temp = current;
        swap(temp[zeroIndex], temp[zeroIndex + 3]);
        child.current = temp;
        return child;
    //}
}

vosminashka vosminashka::left(){
    //if ((zeroIndex != 0) & (zeroIndex != 3) & (zeroIndex != 6)){
        vosminashka child(*this);
        child.parent = current;
        child.zeroIndex  = zeroIndex - 1;
        child.move = 'L';
        vector<s> temp;
        temp = current;
        swap(temp[zeroIndex], temp[zeroIndex - 1]);
        child.current = temp;
    return child;
    //}
}

vosminashka vosminashka::right(){
    //if ((zeroIndex != 2) & (zeroIndex != 5) & (zeroIndex != 8)) {
        vosminashka child(*this);
        child.parent = current;
        child.zeroIndex  = zeroIndex + 1;
        child.move = 'R';
        vector<s> temp;
        temp = current;
        swap(temp[zeroIndex], temp[zeroIndex + 1]);
        child.current = temp;
    return child;
    //}
}

bool end(vector<s>& current){
    int counter = 0;
    for (int i = 0; i<8; i++) {
        if (current[i] == i + 1)
            counter++;
    }
    return counter == 8;
}

bool ifSolved(vector <s>& a){
    int inv = 0;
    for (int i=0; i<9; ++i)
        if (a[i]!=0)
            for (int j=0; j<i; ++j)
                if (a[j]!=0)
                    if (a[j] > a[i])
                        inv++;
    return inv % 2 == 0;
}

void bfs (vosminashka& start, vector<char>& path) {
    //path.clear();
    queue<vector<s>> q;
    // Initialising queue and map of discovered states
    q.emplace(start.current);
    map<vector<s>, vosminashka> NOGraph;
    NOGraph[start.current] = start;

    vector<s> v;
    while (true) {
        v = q.front();
        q.pop();
        if (end(v))
            break;
        vosminashka temp = NOGraph[v];

        if (temp.zeroIndex >= 3)
            if (NOGraph.find(temp.up().current) == NOGraph.end()) {
                NOGraph[temp.up().current] = temp.up();
                q.emplace(temp.up().current);
            }
        if (temp.zeroIndex <= 5)
            if (NOGraph.find(temp.down().current) == NOGraph.end()) {
                NOGraph[temp.down().current] = temp.down();
                q.emplace(temp.down().current);
            }
        if ((temp.zeroIndex != 0) & (temp.zeroIndex != 3) & (temp.zeroIndex != 6))
            if (NOGraph.find(temp.left().current) == NOGraph.end()) {
                NOGraph[temp.left().current] = temp.left();
                q.emplace(temp.left().current);
            }
        if ((temp.zeroIndex != 2) & (temp.zeroIndex != 5) & (temp.zeroIndex != 8))
            if (NOGraph.find(temp.right().current) == NOGraph.end()) {
                NOGraph[temp.right().current] = temp.right();
                q.emplace(temp.right().current);
            }
    }

    while (v != start.current) {
        path.push_back(NOGraph[v].move);
        v = NOGraph[v].parent;
    }
}

int main() {
    ifstream inp("puzzle.in");
    ofstream outp("puzzle.out");

    vector<s> beg(9);
    int x;
    int zero;
    for (int i = 0; i < 9; i++) {
        inp >> x;
    //    cin >> x;
        beg[i] = (s) x;
        if (x == 0)
            zero = i;
    }
    vosminashka start;
    start.current = beg;
    start.zeroIndex = zero;

    vector<char> answer;

    if (ifSolved(beg)) {
        bfs(start, answer);
        //cout << answer.size() << '\n';
        outp << answer.size() << "\n";
        reverse(answer.begin(), answer.end());
        for(int i = 0; i<answer.size(); i++) {
            //cout << answer[i];
            outp << answer[i];
        }
    }

    else outp << -1;
    //else cout << -1;

//    inp.close();
//    outp.close();
    return 0;
}