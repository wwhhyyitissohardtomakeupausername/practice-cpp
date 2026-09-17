#include <iostream>
//指针学习
void BasicUse() {       //基本用法
    //指针是一个变量，它的值是另一个变量的地址
    //指针的声明
    int a = 10;
    int *p = &a;
    //指针的使用
    std::cout << "a's value is:" << *p << std::endl;
    std::cout << "a's address is: " << &a << std::endl;
    std::cout << "p's value is: " << p << std::endl;
/*指针的类型转换,实际使用中不建议使用类型转换,因为可能会导致不可预知的行为.
此处能正常运行是因为c的地址是4的倍数(某些系统),且c的长度大于4.
若c的长度小于4,或者c的地址不是4的倍数,则会出现段错误.*/
    char c[10] = "hello";
    int *q = (int *)c;      //将char*类型的指针转换为int*类型的指针
    std::cout << "c's value is: " << c << std::endl;
    std::cout << "c's address is: " << &c << std::endl;
    std::cout << "q's value is: " << q << std::endl;
    std::cout << "q's value is: " << *q << std::endl;      //输出的是c的前4个字节的值(hell对应的数字拼一起)
    char *r = (char *)q;      //将int*类型的指针转换为char*类型的指针
    std::cout << "r's value is: " << r << std::endl;
    int num=*q;      //将q指向的g值赋给num
    char ch1,ch2,ch3,ch4;       //小端序将num的第1个字节放在ch1中,以此类推
    ch1=(num>>0)&0xff;      //取出num的第1个字节
    ch2=(num>>8)&0xff;      //取出num的第2个字节
    ch3=(num>>16)&0xff;      //取出num的第3个字节
    ch4=(num>>24)&0xff;      //取出num的第4个字节
    std::cout << "ch1's value is: " << ch1 << std::endl;
    std::cout << "ch2's value is: " << ch2 << std::endl;
    std::cout << "ch3's value is: " << ch3 << std::endl;
    std::cout << "ch4's value is: " << ch4 << std::endl;
}
void NullPointer() {        //空指针
    int *r = nullptr; //空指针
    std::cout << "r's value is: " << r << std::endl;
    if (r == nullptr) std::cout << "r is a null pointer" << std::endl;      //判断指针是否为空
    if (r) std::cout << "r is not a null pointer" << std::endl;     //判断指针是否为空
    else std::cout << "r is a null pointer" << std::endl;
}
void PointerArithmetic() {      //指针运算
    int arr[5] = {1, 2, 3, 4, 5};
    int *s = arr; //数组名就是数组首元素的地址
    std::cout << "arr's value is: " << arr << std::endl;
    std::cout << "s's value is: " << s << std::endl;
    s++; //指针加1，指向下一个元素
    std::cout << "arr's value is: " << arr << std::endl;
    std::cout << "s's value is: " << s << std::endl;
    s--; //指针减1，指向上一个元素
    std::cout << "arr's value is: " << arr << std::endl;
    std::cout << "s's value is: " << s << std::endl;

    int a = 10;
    int *p = &a;
    int *q = +p;  // 一元加号
    std::cout << "p 的地址: " << p << std::endl;   // 比如 0x...
    std::cout << "q 的地址: " << q << std::endl;   // 绝对和 p 一模一样
    std::cout << "+p 的地址: " << +p << std::endl; // 同样一模一样
    std::cout << "p + 1 的地址: " << (p + 1) << std::endl; // 地址增加了 4 个字节！
}
void PointerAndArray() {        //指针与数组
    
}
int main() {
    BasicUse();
    NullPointer();
    PointerArithmetic();
    PointerAndArray();
    return 0;
}