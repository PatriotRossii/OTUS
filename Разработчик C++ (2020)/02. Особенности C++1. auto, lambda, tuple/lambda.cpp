#include <iostream>

struct closure {
    int x;
    int y;
    closure(int x, int y): x(x), y(y) {};

    auto operator()(int a, int b) const {
        return x + y + a + b;
    }
};

struct foo {
    int m;
    foo(int m): m(m) { }
    auto baz() {
        return m; 
    }
    auto bar() {
        return [this]() {
            return m;
        };
    }
};

int main(int, char*[]) {
    int x = 1000;
    int y = 9;
    
//  closure l;
    std::cout << closure(10, x)(10, 20) << std::endl;

    std::cout << [
        y = 100.1, x
    ](int a, int b) /* mutable */ /*-> int*/ {
        return x + y + a + b;
    }(10, 1) << std::endl;

    // auto f = [y=100, x](int a, int b) mutable { return x + y++ + a + b; };
    // std::cout << f(10, 1) << std::endl;

    // auto f = [&](auto a, int b) { return x + y + a + b; };
    // Auto in arguments is template argument

    // std::cout << f(10.5, 1) << std::endl;

    foo* f = new foo(1000);
    auto fl = f->bar();
    std::cout << fl() << std::endl;
    delete f;

    foo* f2 = new foo(1);
    auto f2l = f2->bar();
    std::cout << f2l() << std::endl;
    delete f2;

    std::cout << fl() << std::endl; // UB
}