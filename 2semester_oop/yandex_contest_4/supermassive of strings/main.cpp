#include <iostream>
#include <random>
#include <memory>
#include <cassert>
#include <fstream>
#include <vector>

using namespace std;

class _ImplicitTreap_;
using _ImplicitTreapPtr_ = shared_ptr<_ImplicitTreap_>;

int SizeOf(_ImplicitTreapPtr_ treap);
_ImplicitTreapPtr_ _Merge(_ImplicitTreapPtr_ L, _ImplicitTreapPtr_ R);


class _ImplicitTreap_
{
public:

    _ImplicitTreap_(int y, const string& str, _ImplicitTreapPtr_ left = nullptr,
                  _ImplicitTreapPtr_ right = nullptr)
    {
        this->str = str;
        this->y = y;
        Left = left;
        Right = right;
        srand(0);

        Recalc();
    }


    void Recalc()
    {
        Size = SizeOf(Left) + SizeOf(Right) + 1;
    }


    void Split(int x, _ImplicitTreapPtr_ &L, _ImplicitTreapPtr_ &R) {

        _ImplicitTreapPtr_ newTree = nullptr;

        int curIndex = SizeOf(Left) + 1;

        if (curIndex <= x)
        {
            if (Right == nullptr)
                R = nullptr;
            else
                Right->Split(x - curIndex, newTree, R);
            L = make_shared<_ImplicitTreap_>(y, str, Left, newTree);
        }
        else
        {
            if (Left == nullptr)
                L = nullptr;
            else
                Left->Split(x, L, newTree);
            R = make_shared<_ImplicitTreap_>(y, str, newTree, Right);
        }
    }


    _ImplicitTreapPtr_ Left;
    _ImplicitTreapPtr_ Right;

    int y;
    int Size = 1;
    string str;


};

int SizeOf(_ImplicitTreapPtr_ treap)
{
    return treap == nullptr ? 0 : treap->Size;
}

_ImplicitTreapPtr_ _Remove(int pos, _ImplicitTreapPtr_ treap)
{
    _ImplicitTreapPtr_ l, m, r;
    treap->Split(pos, l, r);
    r->Split(1, m, r);
    return _Merge(l, r);
}

_ImplicitTreapPtr_ _Add(int pos, string str, _ImplicitTreapPtr_ treap)
{
    _ImplicitTreapPtr_ l, r;
    treap->Split(pos, l, r);
    _ImplicitTreapPtr_ m = make_shared<_ImplicitTreap_>(abs(rand()), str);
    return _Merge(_Merge(l, m), r);
}

_ImplicitTreapPtr_ _Merge(_ImplicitTreapPtr_ L, _ImplicitTreapPtr_ R)
{
    if (L == nullptr) return R;
    if (R == nullptr) return L;

    if (L->y > R->y)
    {
        _ImplicitTreapPtr_ newR = _Merge(L->Right, R);
        return make_shared<_ImplicitTreap_>(L->y, L->str, L->Left, newR);
    }
    else
    {
        _ImplicitTreapPtr_ newL = _Merge(L, R->Left);
        return make_shared<_ImplicitTreap_>(R->y, R->str, newL, R->Right);
    }
}

const string& _GetAt(int pos, _ImplicitTreapPtr_ tree)
{

    assert(pos >= 0);

    int curIndex = SizeOf(tree->Left);

    if (curIndex == pos)
    {
        return tree->str;
    }
    else if (curIndex > pos)
    {
        return _GetAt(pos, tree->Left);
    }
    else if (curIndex < pos)
    {
        return _GetAt(pos - curIndex, tree->Right);
    }

    assert(false);
}


class ImplicitTreap;
using ImplicitTreapPtr = shared_ptr<ImplicitTreap>;

class ImplicitTreap {
public:
    // Добавление строки в позицию position.\\
    // Все последующие строки сдвигаются на одну позицию вперед.
    void InsertAt( int position, const std::string& value ) {

        if (treap == nullptr) {
            treap = make_shared<_ImplicitTreap_>(abs(rand()), value);
        } else {
            treap = _Add(position, value, treap);
        }
    }

    // Удаление строки из позиции position.\\
    // Все последующие строки сдвигаются на одну позицию назад.
    void DeleteAt( int position ) {
        if (treap == nullptr) {
            return;
        }

        treap = _Remove(position, treap);
    }

    // Получение строки из позиции position.
    std::string GetAt( int position ) {
        return _GetAt(position, treap);
    }

private:
    _ImplicitTreapPtr_ treap;
};

int main() {
    fstream cin("input.txt", ios_base::in);

    ImplicitTreapPtr treap = make_shared<ImplicitTreap>();

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        char cmd; int idx; string str;
        cin >> cmd >> idx;

        if (cmd == '+') {
            cin >> str;
            treap->InsertAt(idx, str);
        } else if (cmd == '-') {
            treap->DeleteAt(idx);
        } else if (cmd == '?') {
            cout << treap->GetAt(idx) << endl;
        }
    }
    return 0;
}