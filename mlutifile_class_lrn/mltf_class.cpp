#include <iostream>
#include "Box.hpp"

int main() {
    Box tmp1(1.0,1.5,2.0),tmp2(1.0,2.5,2.0);
    std::cout<<"V1="<<tmp1.volume()<<'\n';
    if(tmp1.isbigger(tmp2)) std::cout<<"1 is bigger";
    else std::cout<<"1 is not bigger than 2\n";
}