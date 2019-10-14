#include <exception>
#include <iostream>

static void dumpException(const std::exception* e) {
    std::cout << e->what() << std::endl;
}

class CBase : public std::exception {
public:
    CBase() {dumpException(this);}
    virtual char const* what() const {return "CBase";}
};

class CDerived : public CBase {
public:
    virtual char const* what() const {return "CDerived";}
};


void f() {
    throw new CDerived();
}

void g() noexcept {
    try {
        f();
    } catch (CBase*& e) {
        dumpException (e);
        throw e;
    }
}

int main () {
    try {
        g();
    } catch (std::exception* e) {
        dumpException(e);
        delete e;
    } catch (...) {
        std::cout << "Abnormal exit" << std::endl;
    }
    return 0;
}