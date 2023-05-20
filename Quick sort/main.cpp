#include <iostream>
using namespace std;
template <class T>
int partition(T arr[], int begin, int end)
{
    int i = begin;
    int j = end;
    int pivLoc = i;

    while(i < j)
    {
        /** As long as the elements at the RHS is
            greater than current pivot location, decrement j.**/
        while (arr[pivLoc] <= arr[j] && pivLoc != j) { j--; }
        if(j == pivLoc)
            break;
        else if(arr[pivLoc] > arr[j])
        {
            swap(arr[pivLoc], arr[j]);
            pivLoc = j;
        }
        /** As long as the elements at the LHS is
            less than current pivot location, increment i.**/
        while(arr[pivLoc] >= arr[i] && pivLoc != i) { i++; }
        if(i == pivLoc)
            break;
        else if(arr[pivLoc] < arr[i])
        {
            swap(arr[pivLoc], arr[i]);
            pivLoc = i;
        }
    }
    return pivLoc;
}
template <class T>
void quickSort(T arr[], int l, int r)
{
    if(l < r)
    {
        int piv = partition(arr, l, r);
        quickSort(arr, l, piv - 1);
        quickSort(arr, piv + 1, r);
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


    quickSort(arr, 0, sz - 1);
    cout << "After Quick Sort: \n";
    print(arr, sz);
    delete [] arr;
    return 0;

}
