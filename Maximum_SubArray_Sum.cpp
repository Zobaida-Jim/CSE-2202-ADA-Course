/* 09-11-2025
W - 09
SUN */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int cross_sum(vector<int> &a, int st, int mid, int end) {
    int lss = INT_MIN;
    int sum = 0;

    for(int i = mid; i >= st; i--) {
        sum += a[i];
        if(sum > lss) {
            lss = sum;
        }
    }

    int rss = INT_MIN;
    sum = 0;
    for(int j = mid + 1; j <= end; j++) {
        sum += a[j];
        if(sum > rss) {
            rss = sum;
        }
    }
    return (lss + rss);
}

int max_array(vector<int> &a, int st, int end) {
    if(st == end) {
        return a[st];
    }
    else {
        int mid = (st + end) / 2;
        int lss;
        lss = max_array(a, st, mid); // Left

        int rss;
        rss = max_array(a, mid + 1, end); // Right

        int css;
        css = cross_sum(a, st, mid, end);

        if(lss >= rss && lss >= css) {
            return lss;
        }
        else if(rss >= lss && rss >= css) {
            return rss;
        }
        else {
            return css;
        }
    }
}

int main() {
    vector<int> a = {3, -1, -7, 8, 2, 9, -2, 6};

    cout << max_array(a, 0, a.size() - 1) << endl;
}