#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
    int sum=0;
    string str,tmp;
    getline(cin, str);
    istringstream iss(str);
    while(iss >> tmp) {
        cout << tmp << endl;
        sum += stoi(tmp);
        cout << "Current sum: " << sum << endl;
    }
    cout << "Sum: " << sum << endl;
    return 0;
}