#include<iostream>
using namespace std;
class qimpl{
    int start=-1,end=-1;
    int currsize=0;
    static const int qsize=10;
    int q[qsize];
    public:
    void push(int x){
        if(currsize==qsize)
        return;
        if(currsize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%qsize;
        }
        q[end]=x;
        currsize+=1;
    }
    void pop(){
        if(currsize==0)
        return;
        int element=q[start];
        if(currsize==1){
            start=end=-1;
        }
        else{
            start=(start+1)%qsize;
        }
        currsize-=1;
    }
    int top(){
        if(currsize==0)
        return -1;
        return q[start];
    }
    int size(){
        return currsize;
    }
};
int main(){
    qimpl qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    cout<<qu.top()<<endl;
    cout<<qu.size()<<endl;
    qu.pop();
    cout<<qu.top();
}