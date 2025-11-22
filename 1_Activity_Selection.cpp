// To sort the values on end time with start time
#include<iostream>
#include<vector>
#include<list>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<pair<int, int>> act(3, make_pair(0, 0)); // size 3, with values zero

    for(int i = 0; i < end.size(); i++) {
        act[i] = make_pair(start[i], end[i]);
    }

    sort(act.begin(), act.end(), compare);

    for(int i = 0; i < act.size(); i++) {
        cout << act[i].first << " , " << act[i].second << endl;
    }
}