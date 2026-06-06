#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int candies(vector<int> &ratings){
int i=1,sum=1;
int n=ratings.size();
while(i<n){
    if(ratings[i]==ratings[i-1]){
        sum=sum+1;
        i++;
        continue;
    }
    int peak=1;
    while(i<n && ratings[i]>ratings[i-1]){
        peak=peak+1;
        sum+=peak;
        i++;
    }
    int down=1;
    while(i<n && ratings[i]<ratings[i-1]){
        
        sum+=down;
        down+=1;
        i++;
    }
    if(down>peak){
        sum+=down-peak;
    }

}
return sum;
}
int main(){
    vector<int> ratings;
    int n;
    for(int i = 0; i < 10; i++){
        cin>>n;
        ratings.push_back(n);
    }
    cout<<candies(ratings);
}

//TC-O(N)
//SC-O(1)