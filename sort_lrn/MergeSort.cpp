#include <iostream>
#include <vector>
using namespace std;
int len=0;
vector<int> a,tmp;
void fen(int,int,int);
void he(int,int,int);
int main() {
    cin>>len;
    a.push_back(0);
    tmp.push_back(0);
    for(int i=1;i<=len;i++) {
        int data;
        cin>>data;
        a.push_back(data);
        tmp.push_back(data);
    }
    fen(1,(int)(len/2),len);
    for(int i=1;i<=len;i++) cout<<a[i]<<' ';
}
void fen(int st,int mid,int end) { //1 2 3 4;1 2 3;1 2;
    if(st>=end) {
        // cout<<st<<"stop\n";
        return;
    }
    else {
        // cout<<"fen"<<(int)((st+mid)/2)<<"\nfen"<<(int)((mid+1+end)/2)<<'\n';
        fen(st,(int)((st+mid)/2),mid);
        fen(mid+1,(int)((mid+1+end)/2),end);
        he(st,mid,end);
    }
}
void he(int st,int mid,int end) {
    // cout<<st<<"he"<<end<<"\n";
    int ptr=st,ptr1=st,ptr2=mid+1;
    while(ptr1<=mid && ptr2<=end) {
        if(a[ptr1]<=a[ptr2]) tmp[ptr++]=a[ptr1++];
        else tmp[ptr++]=a[ptr2++];
    }
    while(ptr1<=mid) tmp[ptr++]=a[ptr1++];
    while(ptr2<=end) tmp[ptr++]=a[ptr2++];
    for(int i=st;i<=end;i++) a[i]=tmp[i];
}