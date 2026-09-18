#include <iostream>
using namespace std;
class box {
    public:
        double lng,brd,hgh;
        double v() {
            return lng*brd*hgh;
        }
};
int main() {
    box b;

    b.lng=2.0;
    b.brd=3.0;
    b.hgh=1.5;

    cout<<"v="<<b.v()<<endl;
    return 0;
}