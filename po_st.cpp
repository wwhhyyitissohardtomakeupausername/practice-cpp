#include <iostream>
#include <ctime>
#include <cstdio>   // FILE, stdout, fprintf
#include <cstdlib>  // malloc, free , rand
#include <cstddef>  // NULL，但推荐直接用 nullptr
//指针学习

void BasicUse() {       //基本用法
    //指针是一个变量，它的值是另一个变量的地址
    //指针的声明
    int a = 10;
    int *p = &a;
    //指针的使用,p的值是a的地址,*p的值是a的值
    std::cout << "a's value is:" << *p << std::endl;
    std::cout << "a's address is: " << &a << std::endl;
    std::cout << "p's value is: " << p << std::endl;
    *p=40;      //通过指针修改a的值
    std::cout << "a's value is:" << a << std::endl;
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
    int num=*q;      //将q指向的整数值赋给num
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

void NullPointer() {
/*空指针,作用有以下几点:
1. 用于初始化指针变量,防止野指针
int* p = nullptr;
2. 表示函数返回“失败”或“未找到”
int* find(int* arr, int n, int target) {
    for (int i = 0; i < n; ++i) if (arr[i] == target) return &arr[i];
    return nullptr;   // 表示没找到
}
3. 检查动态内存分配是否成功
int* p = (int*)malloc(sizeof(int) * 100);
if (p == NULL) {// 分配失败，处理错误}
4. 作为可选参数
void log(const char* msg, FILE* out = nullptr) {
    if (out == nullptr) out = stdout;
    fprintf(out, "%s\n", msg);
}
5. 数据结构中的终止标记
struct Node {
    int val;
    Node* next;
};
Node* head = nullptr;   // 空链表
6. 释放后置空，防止悬空指针
delete p;
p = nullptr;
7. 表示无效句柄、空对象、未初始化状态

总之，空指针的核心价值就是：给“没有指向有效对象”提供一个统一、可检查的表示，让程序更安全、更健壮。*/
    int *r = nullptr; //空指针,NULL可以用,但不推荐使用,因为NULL是宏定义,可能会引起歧义
    std::cout << "r's value is: " << r << std::endl;
    if (r == nullptr) std::cout << "r is a null pointer" << std::endl;      //判断指针是否为空
    if (r) std::cout << "r is not a null pointer" << std::endl;     //判断指针是否为空
    else std::cout << "r is a null pointer" << std::endl;
}

void PointerArithmetic() {      //指针运算(++, --, +, -, +=, -=)
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
    std::cout << "p's address:" << p << std::endl;   // 比如 0x...
    std::cout << "q's address:" << q << std::endl;   // 绝对和 p 一模一样
    std::cout << "+p's address:" << +p << std::endl; // 同样一模一样
    std::cout << "p + 1 's address:" << (p + 1) << std::endl; // 地址增加了 4 个字节
}

void PointerVsArray() {        //指针与数组
    //用指针读数组
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;//数组名就是数组首元素的地址
    for (int i=0;i<5;i++) std::cout << "arr[" << i << "] = " << *(p + i) << std::endl;      //法一
    std::cout<<"---------------------\n";
    for (int i=0;i<5;i++) std::cout << "arr[" << i << "] = " << p[i] << std::endl;      //法二
    std::cout<<"---------------------\n";
    for (int i=0;i<5;i++) {     //法三
        std::cout << "arr[" << i << "] = " << *p << std::endl;
        p++;
    }       //使用完后,p指向数组外
    p=arr;
    std::cout<<"---------------------\n";
    for (int val : arr) std::cout << val << std::endl;
}

void getSeconds(unsigned long *par);        //指针与函数
double getAverage(int *arr,int size);       //另一个指针与函数的例子
int *getRand();      //从函数返回指针

int main() {
    BasicUse();

    NullPointer();

    PointerArithmetic();

    PointerVsArray();

    unsigned long sec;
    getSeconds(&sec);
    std::cout<<"seconds:"<<sec<<std::endl;

    int array[5]={1,2,3,4,5};
    double avg;
    avg=getAverage(array,5);
    std::cout<<"average:"<<avg<<std::endl;

    int *p;
    p=getRand();
    for(int i=0;i<10;i++) {
        std::cout<<*p<<std::endl;
        p++;
    }
    return 0;
}

void getSeconds(unsigned long *par) {
    *par=time(NULL);
    return;
}
double getAverage(int *arr,int size) {
    int sum=0;
    for(int i=0;i<size;i++) sum+=arr[i];
    return double(sum)/size;
}
int *getRand() {
    static int  r[10];
    srand( (unsigned)time( NULL ) );        // 设置种子
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        std::cout << r[i] << std::endl;
    }
    return r;
}