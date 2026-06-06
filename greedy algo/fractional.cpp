#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Knap{
    int profit;
    int weight;
};
bool comp(Knap a, Knap b){
    return ((double)a.profit/a.weight)>((double)b.profit/b.weight);
}
int main(){
    vector<Knap> knaps={
        {100,20},
        {60,10},
        {100,50},
        {200,50}
    };
    int n=knaps.size();
    int maxWeight=90,w=0,i=0;
    double total=0;
    sort(knaps.begin(),knaps.end(),comp);
    while(knaps[i].weight<=maxWeight){
          total+=knaps[i].profit;
          maxWeight-=knaps[i].weight;
        i++;
    }
    total+=((double) knaps[i].profit/knaps[i].weight)*maxWeight;
    cout<<total;
}