#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

int partition(vector<int> &a, int st, int end) {
    int pivot = a[end];
    int i = st - 1;
    for(int j = st; j < end; j++) {
        if(a[j] <= pivot) {
            i = i + 1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[end]);
    return i + 1;
}

void QuickSort(vector<int> &a, int st, int end) {
    if(st < end) {
        int pivot = partition(a, st, end);
        QuickSort(a, st, pivot - 1);
        QuickSort(a, pivot + 1, end);
    }
}

int main() {
    vector<int> a = {2,5,8,3,9,4,1,7,10,6};

    auto start = high_resolution_clock::now();
    QuickSort(a, 0, a.size() - 1);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<nanoseconds>(end - start);
    cout << time.count() << " Nenoseconds" << endl;

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}