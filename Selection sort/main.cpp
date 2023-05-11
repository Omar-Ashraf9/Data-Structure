#include <iostream>
using namespace std;

template <class T>
void selectionSort(T *arr, int len)
{
    int targetIdx = 0;
    for(int i = 1; i < len; i++)
    {
        if(arr[i] < arr[targetIdx])
            targetIdx = i;
    }
    swap(arr[0], arr[targetIdx]);
}

template <class T>
void sort(T arr[], int sz)
{
    for(int i = 0; i < sz - 1; i++)
        selectionSort(arr + i, sz - i);
}

template <class T>
void print(T arr[], int sz)
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

    sort(arr, sz);
    cout << "After Selection Sort: \n";
    print(arr, sz);

    delete [] arr;
    return 0;
}
