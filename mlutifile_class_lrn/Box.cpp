#include "Box.hpp"
#include <iostream>
//这个文件是怎么起作用的?
Box::Box(double l,double w,double h) {      //这种::类似命名空间?这个::到底是什么?
    this->l=l;
    this->w=w;
    this->h=h;
}
double Box::volume() const{return l*w*h;}
bool Box::isbigger(const Box &other) const{     //这些const啊,&啊,都是正常些吗？
    return this->volume()>other.volume();
}