#include <iostream>
using namespace std;
void heapify(int arr[], int sz, int i)
{
    int lCh = 2 * i + 1;
    int rCh = 2 * i + 2;
    int max = i;

    if(lCh < sz && arr[lCh] > arr[max])
        max = lCh;
    if(rCh < sz && arr[rCh] > arr[max])
        max = rCh;

    if(max != i)
    {
        swap(arr[max], arr[i]);
        heapify(arr, sz, max);
    }
}

void buildHeap(int arr[], int sz)
{
    /* Parent of last node : sz / 2 - 1 */
    for(int i = sz / 2 - 1; i >= 0; i--)
        heapify(arr, sz, i);
}

void heapSort(int arr[], int sz)
{
    buildHeap(arr, sz);

    for(int i = sz - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print(int arr[], int sz)
{
    for(int i = 0; i < sz; i++)
        cout << arr[i] << ' ';
}
int main() {
    int sz;
    cout << "Enter size of array: ";
    cin >> sz;
    int *arr = new int[sz];
    for(int i = 0; i < sz; i++)
        cin >> arr[i];


    heapSort(arr, sz);
    cout << "After Merge Sort: \n";
    print(arr, sz);

    delete [] arr;
    return 0;
}
