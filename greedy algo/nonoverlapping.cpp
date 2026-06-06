#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Inter{
    int start;
    int end;
};

bool comp(Inter a, Inter b){

    return a.end<b.end;
}

int main(){
    vector<Inter> intervals={
        {0,5},
        {3,4},
        {1,2},
        {5,9},
        {5,7},
        {7,9}
    };
    int n=intervals.size();
    sort(intervals.begin(),intervals.end(),comp);
    int count = 1;
    int lastEnd = intervals[0].end;
    for(int i = 1; i < n; i++) {
        
        if(intervals[i].start >= lastEnd) {

            count++;
            lastEnd = intervals[i].end;
        }
    }
    cout<<count<<endl;

    return 0;
}

