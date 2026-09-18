#include <iostream>
using namespace std;
//案例：双向链表的查找、插入、删除
struct Node {
    int data;
    Node *lft;     //Node类型指针,存放另一个Node类型变量的地址
    Node *rgh;
};
Node *head=nullptr;
int n,m,f,x,y;
void build(int siz) {
    Node *curr=nullptr;
    for(int i=1;i<=siz;i++) {
        Node *newnode = new Node{i,nullptr,nullptr};        //左右指针先为空
        if(!head) {
            head=newnode;
            curr=newnode;
        }
        else {
            curr->rgh=newnode;
            newnode->lft=curr;
            curr=newnode;
        }
    }
}
Node *find(int tgt) {
    Node *curr=head;
    while(curr && curr->data!=tgt) curr=curr->rgh;
    return curr;
}
void kill(int dat) {
    Node *curr=find(dat);       //要删除的节点
    if(!curr) return;
    if(!curr->lft) head=curr->rgh;
    else curr->lft->rgh=curr->rgh;
    if(curr->rgh) curr->rgh->lft=curr->lft;
    delete curr;
    curr=nullptr;
}
void left(int a,int b) {
    Node *curr= find(b);
    if(!curr) return;
    Node *newnode=new Node{a,nullptr,curr};
    if(!curr->lft) head=newnode;
    else {
        curr->lft->rgh=newnode;
        newnode->lft=curr->lft;
    }
    curr->lft=newnode;
}
void right(int a,int b) {
    Node *curr=find(b);
    if(!curr) return;
    Node *newnode=new Node{a,curr,curr->rgh};
    if(curr->rgh) curr->rgh->lft=newnode;
    curr->rgh=newnode;
}
void print() {
    if(!head) cout<<"Empty!";
    else {
        Node *curr=head;
        while(curr) {
            cout<<curr->data<<' ';
            curr=curr->rgh;
        }
    }
}
int main() {
    cin>>n>>m;
    build(n);
    for(int i=0;i<m;i++) {
        cin>>f>>x;
        if(f==3) kill(x);
        else {
            cin>>y;
            if(f==1 && x!=y) left(x,y);
            else if(f==2 && x!=y) right(x,y);
        }
        f=x=y=0;
    }
    print();
    return 0;
}