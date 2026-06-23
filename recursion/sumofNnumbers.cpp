#include<iostream>
using namespace std;
int f(int i,int sum){
    if(i<1)
    return sum;
    f(i-1,sum+i);
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    cout<<f(n,0);
    return 0;
}

//functional
/*#include<iostream>
using namespace std;
int f(int n){
    if(n==0)
    return 0;
    return n + f(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    cout<<f(n);
    return 0;
}*/