#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool palin(int i,string& s){
    if(i>=(s.size()/2))
    return true;
    if(s[i]!=s[s.size()-i-1])
    return false;
    return palin(i+1,s);
}
int main(){
    string s;
    cout<<"Enter a string";
    cin>>s;
    if(palin(0, s))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

}