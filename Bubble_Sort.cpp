// Optimized
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &a, int n) {
    for(int i = 0; i < n; i++) {
        bool is_swap = false;
        for(int j = 0; j < n - i -1; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                is_swap = true;
            }
        }
        if(!is_swap) {
            break;
        }
    }
}

int main() {
    vector<int> a = {64, 34, 25, 12, 22, 11, 9};
    int n = a.size();

    bubbleSort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}