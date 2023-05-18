#include <iostream>
using namespace std;

template <class T>
void insertionSort(T arr[], int sz)
{
    // start from 1, as first element is ordered already!
    for(int i = 1; i < sz; i++)
    {
        T cpy = arr[i];
        int j = i - 1;

        for(; j >= 0; j--)
        {
            // The suitable position found.
            if(arr[j] < cpy)
                break;
            // Do the shift
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = cpy;
    }
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

    insertionSort(arr, sz);
    cout << "After Insertion Sort: \n";
    print(arr, sz);

    delete [] arr;

    return 0;
}
