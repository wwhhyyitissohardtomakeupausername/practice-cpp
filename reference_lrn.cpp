#include <iostream>
using namespace std;

void SwapR(int& a,int& b);      //使用引用交换
void SwapP(int *a,int *b);      //使用指针交换

int arr[5]={0,1,2,3,4};
//引用、指针、函数以及做左值
int& f1(int i) {
    int& ref=arr[i];
    return ref;     //这里返回的是引用,即arr[i]
}
int *f2() {
    static int ptr=0;
    return &ptr;        //这里返回的是地址,即&ptr
}

int main() {

    int x=1,y=2;
    SwapR(x,y);
    cout<<x<<' '<<y<<'\n';

    int i=3,j=4;
    SwapP(&i,&j);
    cout<<i<<' '<<j<<'\n';

    f1(1)=5;        //修改arr[1]
    for (int i = 0; i < 5; i ++) cout<<arr[i]<<"\n";

    *f2()=10;       //f2()返回的地址&ptr被解引,修改ptr
    cout<<*f2();
    return 0;
}

void SwapR(int& a,int& b) {
    int temp=a;
    a=b;
    b=temp;
}
void SwapP(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}