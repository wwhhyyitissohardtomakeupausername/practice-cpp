#include <iostream>
#include <functional>
int max(int,int);
/*提前函数声明,是为了在main函数中调用max函数时,编译器知道max函数的存在,
并且知道它的参数类型和返回类型,
从而能够正确地进行类型检查和函数调用.*/
void modifyByValue(int num) {       //传值调用
    // 修改的是副本的值
    num = 100; 
    std::cout << "inside:" << num << std::endl;     // 输出 100
}
void modifyByPointer(int* numPtr) {     //传指针调用
    // 修改的是原始地址上的值
    *numPtr = 200; 
    std::cout << "inside (pointer): " << *numPtr << std::endl;      // 输出 200
}
void modifyByReference(int& numRef) {       //传引用调用
    // 直接修改原始变量的值
    numRef = 300; 
    std::cout << "inside (reference): " << numRef << std::endl;     // 输出 300
}
int main() {
    int a=10, b=20;
    std::cout << "Max value is: " << max(a,b) << std::endl;

    int num = 50;
    std::cout << "before:" << num << std::endl;     // 输出 50
    modifyByValue(num);
    std::cout << "after:" << num << std::endl;      // 输出 50

    int num2 = 50;
    std::cout << "before (pointer):" << num2 << std::endl;      // 输出 50
    modifyByPointer(&num2);
    std::cout << "after (pointer):" << num2 << std::endl;       // 输出 200

    int num3 = 50;
    std::cout << "before (reference):" << num3 << std::endl;        // 输出 50
    modifyByReference(num3);
    std::cout << "after (reference):" << num3 << std::endl;     // 输出 300

    //Lambda表达式学习
    // Lambda表达式是C++11引入的一种匿名函数的表示方式,
    // 它允许在函数内部定义一个临时的、没有名字的函数对象。
    // Lambda表达式的基本语法如下:
    // 准备几个外部变量，用于测试“捕获列表 []”的作用
    int a = 10;
    int b = 20;

    // ==========================================
    // 1. 最完整的写法 (不省略)
    // ==========================================
    // 捕获列表 -> 返回值 { 函数体 }
    auto func1 = [](int x, int y) -> int { 
        return x + y; 
    };
    
    // 【调用方式1】：把 Lambda 赋给 auto 变量，像普通函数一样用变量名调用
    std::cout << "func1(3, 4) = " << func1(3, 4) << std::endl; 

    // 【调用方式2】：直接“定义并立即调用” (在定义末尾加括号传入参数)
    int result = [](int x, int y) -> int { return x * y; }(3, 4);
    std::cout << "directly" << result << std::endl;

    // ==========================================
    // 2. 图片中的规则演示 (结合调用)
    // ==========================================
    
    // 规则一：如果编译器能自动推断出返回值，可以省略 `-> int`
    // (编译器看 return x+y; 发现结果是 int，所以自动推断为 int)
    auto func2 = [](int x, int y) { return x + y; }; 
    std::cout << "省略返回值写法: " << func2(10, 20) << std::endl;

    // 规则二：如果没有参数，可以省略 (parameters)
    auto func3 = []() { return 999; };
    std::cout << "无参函数调用: " << func3() << std::endl; // 注意这里调用时是空的 ()

    // 规则三：如果既没参数，又能推断返回值，那就只剩 [] 和 {body}
    // (对应图片中的：[]{ ++global_x; })
    // 注意：这里的 `[]` 是空的，所以它【无法】访问外面的 a 和 b！
    auto func4 = [] { return 100; }; 
    std::cout << "极简写法: " << func4() << std::endl;

    // ==========================================
    // 3. 捕获列表 (核心难点) [] 里到底写什么？
    // ==========================================
    
    // 捕获为空 []：不能访问外面的 a 和 b
    // auto fail_func = [] { return a + b; }; // 【会报错！】因为 [] 是空的

    // 值捕获 [=]：Lambda 内部会“复印”一份 a 和 b 的数据 (默认行为)
    auto func5 = [=] { 
        return a + b; // 使用复印的 a(10) 和 b(20)
    };
    std::cout << "值捕获 [=]: " << func5() << std::endl; // 输出 30

    // 引用捕获 [&]：Lambda 内部直接使用外面真实的 a 和 b 的内存地址
    // (如果外面改了 a，里面的 a 也会变)
    auto func6 = [&] { 
        a = 50; // 直接修改了外面的 a！
        return a + b; 
    };
    std::cout << "引用捕获 [&]: " << func6() << std::endl; // 输出 70
    std::cout << "外部的 a 被改成了: " << a << std::endl; // 输出 50

    // 混合捕获：默认全部值捕获[=]，但特定变量 b 强制引用捕获 [&b]
    a = 10; b = 20; // 恢复初始值
    auto func7 = [=, &b] { 
        return a + b; 
    };
    std::cout << "混合捕获 [=, &b]: " << func7() << std::endl; // 输出 30

    return 0;
}
int max(int x, int y) {
    return (x > y) ? x : y;
}
/*输出结果
Max value is: 20
before:50
inside:100
after:50
before (pointer):50
inside (pointer): 200
after (pointer):200
before (reference):50
inside (reference): 300
after (reference):300
*/