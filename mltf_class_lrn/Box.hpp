#pragma once        //这里面如果要写头文件就是因为我要调用具体某些库里面的对象或者函数是吗

class Box{
    private:
        double l{0},w{0},h{0};
    public:
        Box(double l,double w,double h);
        double volume() const;
        bool isbigger(const Box &other) const;      //这些const啊,&啊,都是正常写吗?
};