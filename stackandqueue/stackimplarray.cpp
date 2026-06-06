#include<iostream>
using namespace std;
class stimpl{
    int topIndex=-1;
    int st[10];
    public:
    void push(int x){
        if(topIndex>=9)
        return;
        topIndex++;
        st[topIndex]=x;
    }
    int top(){
        if(topIndex==-1)
        return -1;
        return st[topIndex];
    }
    void pop(){
        if(topIndex==-1)
        return;
        topIndex--;
    }
    int size(){
        return topIndex+1;
    }
};
int main(){
stimpl s;
s.push(10);
s.push(20);
cout<<s.top()<<endl;
cout<<s.size()<<endl;
s.pop();
cout<<s.top()<<endl;
cout<<s.size()<<endl;
}