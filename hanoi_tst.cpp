#include <iostream>
using namespace std;
void Hanoi(int num,char start,char helper,char target) {
/*
要把num片从start借助helper移到target上
拆分为先把前num-1片从start移到helper上
再把最下面这一片从start直接移到target上
最后把前num-1片从helper移到target上
*/
    if(num==1) {
        cout<<start<<"->"<<target<<"\n";
        return;
    }
    Hanoi(num-1,start,target,helper);
    Hanoi(1,start,helper,target);
    Hanoi(num-1,helper,start,target);
}
int main() {
    int total=0;
    cin>>total;
    Hanoi(total,'A','B','C');
    return 0;
}