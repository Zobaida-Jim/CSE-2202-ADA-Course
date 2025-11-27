#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &a, int n, int i) {
    // Initializa Largest root
    int largest = i;
    int l = 2 * i + 1; // Left
    int r = 2 * i + 2; // Right

    // If left child is larger than root
    if(l < n && a[l] > a[largest]) {
        largest = l;
    }

    // If right child is larger than root
    if(r < n && a[r] > a[largest]) {
        largest = r;
    }

    // If largest is not root
    if(largest != i) {
        swap(a[i], a[largest]);

        // recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

void heapSort(vector<int> &a) {
    int n = a.size();

    // Build heap, rearrange vector
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    for(int i = n - 1; i > 0; i--) {
        // move current root to end
        swap(a[0], a[i]);

        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}

int main() {
    vector<int> a = {9, 4, 3, 8, 10, 2, 5};

    heapSort(a);

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}