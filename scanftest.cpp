#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    for(int i=0;i<5;i++) {
        cin>>a;
        cout<<"Hello World!"<<endl;
        cout<<a;
    }
    char b[100];
    for(int i=0;i<5;i++) {
        cin>>b;
        cout<<"Hello World!"<<endl;
        cout<<b;
    }
    return 0;
}