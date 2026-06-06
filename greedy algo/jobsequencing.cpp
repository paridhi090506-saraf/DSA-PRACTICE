#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

bool comp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {

    vector<Job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), comp);

    // Find maximum deadline
    int maxi = 0;

    for(int i = 0; i < n; i++) {
        maxi = max(maxi, jobs[i].dead);
    }

    // hash array to store occupied slots
    vector<int> hash(maxi + 1, -1);

    int countJobs = 0;
    int totalProfit = 0;

    for(int i = 0; i < n; i++) {

        // check slots from deadline to 1
        for(int j = jobs[i].dead; j > 0; j--) {

            if(hash[j] == -1) {

                hash[j] = jobs[i].id;

                countJobs++;
                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    cout << "Jobs done = " << countJobs << endl;
    cout << "Total profit = " << totalProfit;

    return 0;
}