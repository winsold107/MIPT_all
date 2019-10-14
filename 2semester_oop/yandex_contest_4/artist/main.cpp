#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <cassert>

using namespace std;

class Artist {
    using Colors = vector<int>;
    static constexpr int NoColor = numeric_limits<int>::max();

public:

    static int closest2_n(int n) {
        int n_bit = 0;
        while (n > (1 << n_bit)) {
            n_bit++;
        }
        return 1<<n_bit;
    }

    Artist() {
        input.open("input.txt", ios_base::in);

        int r1, g1, b1;

        input >> segment;
        t.resize(closest2_n(segment)*2-1, Artist::NoColor);
        t[0] = NoColor;

        vector<int> arr(closest2_n(segment)*2-1, NoColor);

        for(int i = 0; i < segment; i++){
            input >> r1 >> g1 >> b1;
            arr[i] = r1 + g1 + b1;
        }

        build(arr, 1, 0, closest2_n(segment)-1);
    }

    void solve() {
        int sum;
        int a, b, c, d;
        pair<int, int> paint, photo;

        int act, r2, g2, b2;

        input >> act;

        for (int i = 0; i < act; i++){
            input >> a >> b >> r2 >> g2 >> b2 >> c >> d;

            paint.first = a;
            paint.second = b;

            photo.first = c;
            photo.second = d;

            sum = r2 + g2 + b2;

            update(1, 0, closest2_n(segment)-1, paint.first, paint.second, sum);
            cout << get_min(1, 0, closest2_n(segment)-1, photo.first, photo.second) << endl;
        }
    }

    void build(const vector<int>& a, int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];

        else {

            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
        }
    }


    void push(int v) {
        if (t[v] != NoColor) {
            t[v*2] = t[v*2+1] = t[v];
            t[v] = NoColor;
        }
    }


    void update(int v, int tl, int tr, int l, int r, int color) {

        if (l > r) {
//            assert(false);
            return;
        }

        if (tl == tr) {
            assert(l == r && tl == l);
            t[v] = color;
            return;
        }

        if (l == tl && tr == r)
            t[v] = color;

        else {
            push(v);

            int tm = (tl + tr) / 2;

            update(v*2, tl, tm, l, min(r,tm), color);
            update(v*2+1, tm+1, tr, max(l,tm+1), r, color);
        }
    }

    int get_min(int v, int tl, int tr, int l, int r) {

//        assert()

        if (l > r) {
            return NoColor;
        }

        if (tl == tr) {
            return t[v];
        }


        if (t[v] != NoColor && l == tl && r == tr)
            return t[v];

        push(v);

        int tm = (tl + tr) / 2;

        int     min_left = get_min(v*2, tl, tm, l, min(r,tm)),
                min_right = get_min(v*2+1, tm+1, tr, max(l,tm+1), r);


        return min(min_left, min_right);
    }

private:
    int segment;
    Colors t;
    fstream input;
};

constexpr int Artist::NoColor;

int main() {
    Artist art;
    art.solve();
    return 0;
}

