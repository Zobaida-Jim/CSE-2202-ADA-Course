#include<iostream>
#include<list>
#include<vector>
using namespace std;

bool compare(pair<pair<int, int>,int> p1, pair<pair<int, int>, int> p2) {
    return p1.first.second < p2.first.second;
}

int activity(vector<pair<pair<int, int>, int>>&a, int n, vector<int>&act) {
    sort(a.begin(), a.end(), compare);

    int count = 1;
    int curr_end_time = a[0].first.second;
    act.push_back(a[0].second);
    for(int i = 1; i < a.size(); i++) {
        if(curr_end_time <= a[i].first.first) {
            count++;
            act.push_back(a[i].second);
            curr_end_time = a[i].first.second;
        }
    }
    
    return count;
}

int main() {
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> a(n); // start time, end time, index of job
    for(int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    vector<int> act;
    cout << activity(a, n, act) << endl;
    for(int i = 0; i < act.size(); i++) {
        cout << act[i] + 1 << " ";
    }
    cout << endl;
}