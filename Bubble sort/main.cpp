#include <iostream>
using namespace std;

template <class T>
void sort(T arr[], int sz)
{
    bool sorted = true;
    for(int i = 0; i < sz - 1; i++)         // N-1 passes to sort the array without need to check on the first element.
    {
        for(int j = 0; j < sz - i - 1; j++) // at the end of each pass, the Max number of that range will be in its correct position.
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
        if(sorted)
            break;
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

    sort(arr, sz);
    cout << "After Selection Sort: \n";
    print(arr, sz);

    delete [] arr;
    return 0;
}
