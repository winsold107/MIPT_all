#include <iostream>
using namespace std;

struct A {
    virtual ~A() {}
};

struct B : virtual A {
    double FieldB = 0.0;
};

struct C : virtual A {
    double FieldC = 0.0;
};

struct D : B, C {
    double FieldD = 0.0;
};

void const_increment(const D* d) {
    D* nonConstD = const_cast<D*> (d);
    nonConstD->FieldD += 1;
}

int main() {
    D objectD;
    const D constObjectD;
    C objectC;
    const C constObjectC;
    B objectB;
    A objectA;

    A* objectDA = static_cast<A*> (&objectD); ////1
    C* objectDC = static_cast<C*> (&objectD); ////2
    B* objectDCB = static_cast<B*> (&objectDC); ////3
    D* objectAD = static_cast<D*> (&objectA); ////4
    B* objectDB = static_cast<B*> (&objectD); ////5


    D& objectBDref = static_cast<D&>(objectB); ////6
    A& objectDAref = static_cast<A&>(objectD); ////7
    B& objectCBref = static_cast<B&>(objectC); ////8

    ////предполагаем, что sizeof(D*) == 8, sizeof(int) == 4, sizeof(doble) == 8

    int* dInt1 = reinterpret_cast<int*> (objectD); ////9
    int* dInt2 = reinterpret_cast<int*> (&objectD); ////10
    double dDouble1 = reinterpret_cast<double> (objectD); ////11
    double dDouble1 = *reinterpret_cast<double*> (&objectD); ////12

    return 0;
}

#include <iostream>
using namespace std;

struct A {
    virtual ~A() {}
};

struct B : virtual A {};

struct C : virtual A {
    C() {};
    mutable int FieldC = 0;
};

struct D : B, C {
    D() {};
    int FieldD = 0;
};

void const_increment(const D* d) {
    D* nonConstD = const_cast<D*> (d);
    nonConstD->FieldD += 1;
}

int main() {
    D objectD;
    const D constObjectD;
    C objectC;
    const C constObjectC;
    B objectB;
    A objectA;

    A* objectDA = dynamic_cast<A*> (&objectD); ////1
    C* objectDC = dynamic_cast<C*> (&objectD); ////2
    //B* objectDCB = dynamic_cast<B*> (&objectDC); ////3
    D* objectAD = dynamic_cast<D*> (&objectA); ////4
    B* objectDB = dynamic_cast<B*> (&objectD); ////5


//    D& objectBDref = dynamic_cast<D&>(objectB); ////6
    A& objectDAref = dynamic_cast<A&>(objectD); ////7
    //   B& objectCBref = dynamic_cast<B&>(objectC); ////8

    //constObjectD.FieldD += 1; ////9
    constObjectC.FieldC += 1; ////10
    const_increment(&objectD); ////11
    const_increment(&constObjectD); ////12

    return 0;
}