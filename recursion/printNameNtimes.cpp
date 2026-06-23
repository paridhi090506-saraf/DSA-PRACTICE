#include<iostream>
using namespace std;
void print(int i,int n){
    if(i>n)
    return;
    cout<<"Paridhi"<<endl;
    print(i+1,n);
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    print(1,n);
    return 0;
}