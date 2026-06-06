#include<iostream>
using namespace std;
bool lemonade(int arr[]){
    int five=0,ten=0;
    for(int i=0;i<5;i++){
        if(arr[i]==5)
        five=five+1;
        else if(arr[i]==10){
            if(five){
            five=five-1;
            ten=ten+1;
            }
            else
            return false;
        }
        else{
            if(five && ten)
            {
                ten-=1;
                five-=1;
            }
            else if(five>=3)
            five-=3;
            else
            return false;
        }
    }
    return true;
}
int main(){
    int arr[5];
    cout<<"Enter values";
    for(int i=0;i<5;i++)
    cin>>arr[i];
    if(lemonade(arr)){
        cout<<"True";
    }
    else
    cout<<"False";
}

//Time complexity- O(n)
//Space complexity- O(1)