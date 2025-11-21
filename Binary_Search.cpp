//22-09-2025 MON W-03

#include<iostream>
using namespace std;

int BinarySearch(int a[],int st, int ei, int key) {
    int count = 0;
    while(st <= ei) {
        count++;
        int mid = (st + ei) / 2;
        if(a[mid] == key) {
            break;
        }
        if(key > a[mid]) {
            st = mid + 1;
        }
        else {
            ei = mid - 1;
        }
    }
    return count;
}
int main() {
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int key;
    cout<<"Enter the key : ";
    cin>> key;
    cout<<BinarySearch(a,0,n-1,key)<<endl;
}