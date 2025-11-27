#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int recursiveBinarySearch(int a[], int low, int high, int x) {
    if (low > high) return -1;
    int mid = (low + high)/2;
    if (a[mid] == x) return mid;
    else if (x < a[mid]) return recursiveBinarySearch(a, low, mid-1, x);
    else return recursiveBinarySearch(a, mid+1, high, x);
}

int iterativeBinarySearch(int a[], int n, int x) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(a[mid] == x) return mid;
        else if(x < a[mid]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main() {
    const int n = 1000000;
    int a[n];
    for(int i=0; i<n; i++) a[i] = i+1;
    int x = 999999;

    auto start = high_resolution_clock::now();
    recursiveBinarySearch(a, 0, n-1, x);
    auto end = high_resolution_clock::now();
    auto time_rec = duration_cast<nanoseconds>(end-start);
    cout << "Recursive time: " << time_rec.count() << " nanoseconds\n";

    start = high_resolution_clock::now();
    iterativeBinarySearch(a, n, x);
    end = high_resolution_clock::now();
    auto time_iter = duration_cast<nanoseconds>(end-start);
    cout << "Iterative time: " << time_iter.count() << " nanoseconds\n";

    return 0;
}