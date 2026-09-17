#include <iostream>
//指针学习
int main() {
    int a = 10;
    int *p = &a;
    std::cout << "a的值为: " << a << std::endl;
    std::cout << "a的地址为: " << &a << std::endl;
    std::cout << "p的值为: " << p << std::endl;
    char c[10] = "hello";
    int *q = (int *)c;
    std::cout << "c的值为: " << c << std::endl;
    std::cout << "c的地址为: " << &c << std::endl;
    std::cout << "q的值为: " << q << std::endl;
    return 0;
}