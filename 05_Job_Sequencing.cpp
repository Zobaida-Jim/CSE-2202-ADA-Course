#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

int job_sequencing(vector<pair<int, int>> &job) {
    sort(job.begin(), job.end(), compare);
    int n = job.size();
    int maxD = 0;
    for(int i = 0; i < n; i++) {
        maxD = max(maxD + 1, job[i].second);
    }
    int total_profit = 0;
    vector<int> slot(n, -1);
    for(int i = 0; i < n; i++) {
        int p = job[i].first;
        int d = job[i].second;
        for(int t = d; t > 0; t--) {
            if(slot[t] == -1) {
                total_profit += p;
                slot[t] = p;
                break;
            }
        }
    }
    return total_profit;
}

int main() {
    int n = 5;
    vector<int> profit = {10, 5, 20, 1, 15};
    vector<int> deadline = {1, 3, 2, 3, 2};
    vector<pair<int, int>> job(n, make_pair(0,0)); // Profit + Deadline
    for(int i = 0; i < n; i++) {
        job[i] = make_pair(profit[i], deadline[i]);
    }
    cout << job_sequencing(job) << endl;
}