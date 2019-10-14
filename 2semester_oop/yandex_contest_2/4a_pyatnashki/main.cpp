#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

typedef int s;

struct pyatnaska {
    pyatnaska() {};
    //pyatnaska(pyatnaska& state);
    //pyatnaska(vector<int>& pos);

    pyatnaska up();
    pyatnaska down();
    pyatnaska left();
    pyatnaska right();

    vector<s> current;
    int zeroIndex{};
    int heuristic{};
    char move{};
    vector<s> parent;

};

pyatnaska pyatnaska::up(){
    //if (zeroIndex >= 3) {
    pyatnaska child(*this);
    child.parent = current;
    child.zeroIndex  = zeroIndex - 4;
    child.move = 'D';
    vector<s> temp;
    temp = current;
    swap(temp[zeroIndex], temp[zeroIndex - 4]);
    child.current = temp;
    return child;
    //}
}

pyatnaska pyatnaska::down(){
    //if (zeroIndex <= 5) {
    pyatnaska child(*this);
    child.parent = current;
    child.zeroIndex  = zeroIndex + 4;
    child.move = 'U';
    vector<s> temp;
    temp = current;
    swap(temp[zeroIndex], temp[zeroIndex + 4]);
    child.current = temp;
    return child;
    //}
}

pyatnaska pyatnaska::left(){
    //if ((zeroIndex != 0) & (zeroIndex != 3) & (zeroIndex != 6)){
    pyatnaska child(*this);
    child.parent = current;
    child.zeroIndex  = zeroIndex - 1;
    child.move = 'R';
    vector<s> temp;
    temp = current;
    swap(temp[zeroIndex], temp[zeroIndex - 1]);
    child.current = temp;
    return child;
    //}
}

pyatnaska pyatnaska::right(){
    //if ((zeroIndex != 2) & (zeroIndex != 5) & (zeroIndex != 8)) {
    pyatnaska child(*this);
    child.parent = current;
    child.zeroIndex  = zeroIndex + 1;
    child.move = 'L';
    vector<s> temp;
    temp = current;
    swap(temp[zeroIndex], temp[zeroIndex + 1]);
    child.current = temp;
    return child;
    //}
}

int pyatnaska::heuristic(vector<s>& current)
{
    int heuristic = 0;
    for (int i = 0; i < 16; i++) {
        if (current[i] == 0)
            continue;
        heuristic += 10 * (abs(i % 4 - (current[i] - 1) % 4)
                           + abs(i / 4 - (current[i] - 1) / 4));
    }
    return heuristic;
}

bool end(vector<s>& current){
    int counter = 0;
    for (int i = 0; i<15; i++) {
        if (current[i] == i + 1)
            counter++;
    }
    return counter == 15;
}

bool ifSolved(vector <s>& a){
    int inv = 0;
    for (int i=0; i<16; ++i)
        if (a[i]!=0)
            for (int j=0; j<i; ++j)
                if (a[j] > a[i])
                    ++inv;
    for (int i=0; i<16; ++i)
        if (a[i] == 0)
            inv += 1 + i / 4;
    return (inv % 2 == 0);
}

void AZvezda (pyatnaska& start, vector<char>& path) {
    // Priority queue for A*, stores pair
    // <f(state) = path(state) + heuristic(state), state>
    // States in queue are not being updated!
    // This algorithm doesn't find shortest solution with admissible heuristic!
    priority_queue q;
    q.emplace(make_pair(0, start));

    // Stores State.data as key and pair
    // <move(char), parent state(State.data)> as value
    unordered_map<ull, pair<char, ull>> parents;
    parents.emplace(from.current, make_pair(0, 0));

    // State to be visited
    State v;
    State state;
    while (true) {
        // Taking state from queue
        v = q.pop().second;
        // Visiting every possible state
        if (v.nullPos >= 4) {
            state = v.up();
            // Checking is state was not visited
            if (parents.find(state.data) == parents.end()) {
                // Inserting it into parents set
                parents.emplace(state.data, make_pair('D', v.data));
                // Stop search if goal is achieved
                if (state.data == GOAL)
                    break;
                // Inserting into queue
                q.emplace(make_pair(state.depth + state.h, state));
            }
        }
        // Same actions
        if (v.nullPos <= 11) {
            state = v.down();
            if (parents.find(state.data) == parents.end()) {
                parents.emplace(state.data, make_pair('U', v.data));
                if (state.data == GOAL)
                    break;
                q.emplace(make_pair(state.depth + state.h, state));
            }
        }
        if (v.nullPos % 4 != 3) {
            state = v.right();
            if (parents.find(state.data) == parents.end()) {
                parents.emplace(state.data, make_pair('L', v.data));
                if (state.data == GOAL)
                    break;
                q.emplace(make_pair(state.depth + state.h, state));
            }
        }
        if (v.nullPos % 4 != 0) {
            state = v.left();
            if (parents.find(state.data) == parents.end()) {
                parents.emplace(state.data, make_pair('R', v.data));
                if (state.data == GOAL)
                    break;
                q.emplace(make_pair(state.depth + state.h, state));
            }
        }
    }
    // Recovering solution
    ull u = GOAL;
    pair<char, ull> curMove;
    while (u != from.data) {
        curMove = parents[u];
        ans.push_front(curMove.first);
        u = curMove.second;
    }
}

int main() {
    vector<s> beg(16);
    int x;
    int zero;
    for (int i = 0; i < 16; i++) {
        cin >> x;
        beg[i] = (s) x;
        if (x == 0)
            zero = i;
    }
    pyatnaska start;
    start.current = beg;
    start.zeroIndex = zero;

    vector<char> answer;

    if (ifSolved(beg)) {
        A*(start, answer);
        cout << answer.size() << '\n';
        reverse(answer.begin(), answer.end());
        for(int i = 0; i<answer.size(); i++) {
            cout << answer[i];
        }
    }

    else cout << -1;
    return 0;
}