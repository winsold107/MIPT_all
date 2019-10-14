////
//// Created by darin on 29.04.18.
////
//
//#include <iostream>
//
//template <unsigned long long n>
//struct Factorial {
//    static constexpr unsigned long long fact = Factorial<n-1>::fact * n;
//};
//
//template <>
//struct Factorial<0> {
//    static constexpr int fact = 1;
//};
//
//
//int main() {
//
//    std::cout << Factorial<1>::fact << std::endl;
//    std::cout << Factorial<2>::fact << std::endl;
//    std::cout << Factorial<3>::fact << std::endl;
//    std::cout << Factorial<4>::fact << std::endl;
//    std::cout << Factorial<5>::fact << std::endl;
//    std::cout << Factorial<6>::fact << std::endl;
//    std::cout << Factorial<7>::fact << std::endl;
//    std::cout << Factorial<8>::fact << std::endl;
//    std::cout << Factorial<9>::fact << std::endl;
//    std::cout << Factorial<10>::fact << std::endl;
//
//    return 0;
//}