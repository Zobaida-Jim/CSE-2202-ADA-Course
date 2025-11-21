#include<iostream>
using namespace std;

void recursiveMaxMin(int a[], int i, int j, int &max, int &min) {
    if(i == j) {
        max = min = a[i];
    }
    else if(i == (j - 1)) {
        if(a[i] < a[j]) {
            max = a[j];
            min = a[i];
        }
        else {
            min = a[j];
            max = a[i];
        }
    }
    else {
        int mid = (i + j) / 2;
        int max1, min1;
        recursiveMaxMin(a, i, mid, max, min);
        recursiveMaxMin(a, mid + 1, j, max1, min1);

        if(max < max1) max = max1;
        if(min > min1) min = min1;
    }
}

int main() {
    int a[] = {3, 8, 1, 5, 9};
    int n = 5;
    int max, min;
    recursiveMaxMin(a, 0, n - 1, max, min);
    cout << max << " " << min << endl;
}

/* Number of comparisons: T(n) = 2T(n/2) + 2
Solving gives T(n) = 3n/2 − 2 (for n = power of 2)
Time Complexity: O(n)
Space Complexity: O(log n) (due to recursion)
Comparison with StraightMaxMin: Fewer comparisons but uses recursion stack. */