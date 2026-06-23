#include<iostream>
using namespace std;
int f(int n){
    if(n==1)
    return 1;
    return n * f(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    cout<<f(n);
    return 0;
}

//parametrized
/*#include<iostream>
using namespace std;
int f(int i,int prod){
    if(i<1)
    return prod;
    f(i-1,prod*i);
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    cout<<f(n,1);
    return 0;
}*/