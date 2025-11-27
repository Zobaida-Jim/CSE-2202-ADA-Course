/*15-09-2025 
MON 
W-02*/

#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
    int count = 0;
    int j, key;
    for (int i = 1; i < n; i++)
    {
        count++;
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
            count++;
        }
        a[j + 1] = key;
    }
    cout<<"The number of comparison : ";
    cout<<count<<endl;
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Enter the size of Array : ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Before Sorting : ";
    print(a, n);
    InsertionSort(a, n);
    cout << "After Sorting : ";
    print(a, n);
    return 0;
}