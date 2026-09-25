#include <iostream>
#include <iomanip>      //put_time(),注意这个函数只能参与流IO
#include <ctime>
//获取时间
void gett1(),gett2();
int main() {
    gett1();
    gett2();
    return 0;
}

void gett1() {      //法一
/*简单，适合快速打印当前时间。
输出格式固定，不能自己控制。
返回的是静态缓冲区指针，不要 delete，也不要 free。
不是线程安全的：下一次调用 std::ctime 或 std::asctime 可能覆盖这块内存。
C++17 起 std::ctime 被标记为弃用，新代码不推荐优先使用。*/
    std::time_t now = std::time(nullptr);       //返回值类型为std::time_t,为读秒数
    if (now == static_cast<std::time_t>(-1)) {      //std::time失败时返回(std::time_t)-1,转换-1类型
        std::cerr<<"time() failed\n";
        return;
    }
    char* s = std::ctime(&now);     //ctime()接受一个指针参数,所以传&now
    if(!s) {        //ctime失败返回空指针
        std::cerr<<"ctime() failed\n";
        return;
    }
    std::cout<<s;
}
void gett2() {      //法二
    std::time_t now = std::time(nullptr);
    if (now == static_cast<std::time_t>(-1)) {      //std::time失败时返回(std::time_t)-1,转换-1类型
        std::cerr<<"time() failed\n";
        return;
    }
    std::tm* ptm = std::localtime(&now);        //它把 time_t 转换成本地时间，结果放在一个 std::tm 结构体里
/*std::tm 里面包含：年（通常是从1900年开始算）、月（0到11）、日、
时、分、秒、星期、一年中的第几天、夏令时标志等字段*/
    if(!ptm) {
        std::cerr<<"localtime() failed\n";
        return;
    }
    std::tm tm = *ptm;
    std::cout<<std::put_time(&tm,"%Y-%m-%d %H:%M:%S")<<'\n';
}