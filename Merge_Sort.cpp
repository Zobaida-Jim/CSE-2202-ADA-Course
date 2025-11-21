/// Recursive way
#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

void Merge(vector<int> &a, int st, int mid, int end) {
    int i = st;
    int j = mid + 1;
    int k = st;
    vector<int> temp;

    while(i <= mid && j <= end) {
        if(a[i] >= a[j]) {
            temp.push_back(a[j++]);
        }
        else{
            temp.push_back(a[i++]);
        }
    }

    while(i <= mid) {
        temp.push_back(a[i++]);
    }
    while(j <= end) {
        temp.push_back(a[j++]);
    }
    for(int i = 0; i < temp.size(); i++) {
        a[st + i] = temp[i];
    }
}

void MergeSort(vector<int> &a, int st, int end) {
    int mid;
    if(st < end) {
        mid = (st + end) / 2;
        MergeSort(a, st, mid);
        MergeSort(a, mid + 1, end);
        Merge(a, st, mid, end);
    }
}

int main() {
    vector<int> a = {98, 23, 14, 6, 67, 33, 42};

    auto start = high_resolution_clock::now();
    MergeSort(a, 0, a.size() - 1);
    auto end = high_resolution_clock::now();

    auto time_rec = duration_cast<nanoseconds>(end - start);
    cout << time_rec.count() << endl;

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}