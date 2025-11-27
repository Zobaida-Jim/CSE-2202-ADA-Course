#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<float> &bucket) {
    for(int i = 1; i < bucket.size(); i++) {
        float key = bucket[i];
        int j = i - 1;
        while(j >= 0 && key < bucket[j]) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(vector<float> &a, int n) {
    // Create an empty buckets
    vector<float> b[n]; // Works like 2D array

    // Put array elements in Different bucket
    for(int i = 0; i < n; i++) {
        int bi = n * a[i];
        b[bi].push_back(a[i]);
    }

    // Sort each bucket
    for(int i =0; i < n; i++) {
        insertionSort(b[i]);
    }

    // Cancatenate all buckets
    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < b[i].size(); j++) {
            a[idx++] = b[i][j];
        }
    }
}

int main() {
    vector<float> a = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = a.size();

    bucketSort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}