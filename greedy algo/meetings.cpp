#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Meet{
    int start;
    int end;
    int pos;
};

bool comp(Meet a, Meet b){
     if(a.end == b.end)
        return a.pos < b.pos;

    return a.end<b.end;
}

int main(){
    vector<Meet> meets={
        {0,5,1},
        {3,4,2},
        {1,2,3},
        {5,9,4},
        {5,7,5},
        {8,9,6}
    };
    int n=meets.size();
    sort(meets.begin(),meets.end(),comp);
    int count = 1;
    int lastEnd = meets[0].end;
     cout<<meets[0].pos<<endl;
    for(int i = 1; i < n; i++) {
        
        if(meets[i].start > lastEnd) {

            count++;
            cout<<meets[i].pos<<endl;
            lastEnd = meets[i].end;
        }
    }
    cout<<count<<endl;

    return 0;
}

