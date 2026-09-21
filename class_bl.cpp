#include <iostream>
#include <string>
//类的设计思想:只提供接口
/*类的简单使用
1.成员函数可直接访问该类其他成员函数(包括递归)
2.函数可以重载,可使用默认参数(简化使用)
3.类指针用法同结构体指针
4.类成员可以是任意数据类型(类中枚举enum)
5.可以为类的成员指定缺省值
6.类可以创建对象组
7.对象可以作为实参传递给函数,一般传引用
8.可以用new动态创建对象,用delete释放对象
9.在类的外部,一般不直接访问对象的成员,而是用成员函数
10.对象一般不用memset()清空成员变量,可以专门写一个成员函数实现
11.类和对象用sizeof意义不大,一般不用
12.用结构体描述数据,用类描述对象
13.在类的声明中定义的函数都将自动成为内联函数(允许"建议展开(类似宏)"并允许跨翻译单元重复编译);
在类的声明之外定义的函数如果使用了inline,也是内联函数
14.为了区分成员变量和成员函数的形参,把成员变量名加_前后缀
15.调用没有参数的构造函数时不要打括号
16.类的分文件编写*/
class Student{
    private:
        std::string name{""};       //兜底的初始化
        double score{0};
    public:
        Student(std::string name,double score) {        //主构造函数和构造函数的委托
            this->name=name;
            this->score=score;
        }
        Student(std::string name):Student(name,0){}
        Student(double score):Student("",score){}
        Student()=default;      //无参构造函数
        ~Student() {}       //删掉也可
        void display() const{
            std::cout<<"name:"<<this->name<<"\n";
            std::cout<<"score:"<<this->score<<"\n";
        }
        void setScore(double newscore) {this->score=newscore;}
        bool isPass() const{return this->score>=60;}
};
class Box{
    private:
        double length{0},width{0},height{0};
    public:
        Box(double length,double width,double height) {
            this->length=length;
            this->width=width;
            this->height=height;
        }
        double volume() const{return (this->length)*(this->width)*(this->height);}
        bool isbigger(const Box &other) const{return this->volume()>other.volume();}
};
int main() {
    Student tmp("Tommy",58.5);
    tmp.display();
    if(tmp.isPass()) std::cout<<"pass\n";
    else std::cout<<"not pass\n";
    tmp.setScore(61.5);
    tmp.display();
    if(tmp.isPass()) std::cout<<"pass\n";
    else std::cout<<"not pass\n";
}