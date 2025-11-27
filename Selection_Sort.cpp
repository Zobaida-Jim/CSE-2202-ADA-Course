#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &a, int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_idx]) {
                min_idx = j;
            }
        }

        if(min_idx != i) {
            swap(a[min_idx], a[i]);
        }
    }
}

int main() {
    vector<int> a = {29, 10, 14, 37, 1};
    int n = a.size();

    selectionSort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}