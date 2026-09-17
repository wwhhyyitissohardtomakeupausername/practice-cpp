#include <iostream>
int max(int,int);
int main() {
    int a=10, b=20;
    std::cout << "Max value is: " << max(a,b) << std::endl;
    return 0;
}
int max(int x, int y) {
    return (x > y) ? x : y;
}