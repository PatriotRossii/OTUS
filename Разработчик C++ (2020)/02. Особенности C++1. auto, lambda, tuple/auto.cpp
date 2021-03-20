#include <string>
#include <vector>

auto foo(int a, float b) {
    // if (a < b)
    //  return a;
    // return b;
    return (a < b) ? a : b; // it's okay. expression have deductable type
}

// auto bar(int a, int b); // error. can't deduce type
auto baz(int a, int b) -> int;
auto boo(int a, int b) -> decltype(a);

int main() {
    int i = 0;
    auto ai = 0; // identical

    float f = 1 + 2;
    auto af = static_cast<float>(1 + 2); // identical

    int j = 0, k = 0.0;
    // auto aj = 0, ak = 0.0; // error: inconsistent deduction for auto

    std::string s = "hello";
    auto as = "hello"; // auto => const char*

    std::vector<bool> v;
    std::vector<bool>::iterator vi = v.begin(); // lot of letters
    auto avi = v.begin(); // less letters

    // auto a. error: cannot deduce type of auto

    auto z1 = foo(1, 2); // auto -> float
//  auto z2 = bar(1, 2); // error: use of fun before deduct. of auto
    auto z3 = baz(1, 2); // identical to next fn
    auto z4 = boo(1, 2);

    return 0;
}