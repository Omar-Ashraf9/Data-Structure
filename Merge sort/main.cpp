#include <bits/stdc++.h>
using namespace std;

template <class T>
void merge(T arr[], int left, int mid, int right)
{
    int i, j, k;
    int sz1 = mid - left + 1;
    int sz2 = right - mid;

    T *lSubArray = new T[sz1], *rSubArray = new T[sz2];
    for(i = 0; i < sz1; i++)
        lSubArray[i] = arr[left + i];

    for(j = 0; j < sz2; j++)
        rSubArray[j] = arr[mid + 1 + j];

    i = j = 0;
    k = left;

    while(i < sz1 && j < sz2)
    {
        if(lSubArray[i] <= rSubArray[j])
            arr[k++] = lSubArray[i++];
        else
            arr[k++] = rSubArray[j++];
    }

    while(i < sz1)
        arr[k++] = lSubArray[i++];
    while(j < sz2)
        arr[k++] = rSubArray[j++];

    delete [] lSubArray;
    delete [] rSubArray;
}
template <class T>
void mergeSort(T arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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


    mergeSort(arr, 0, sz - 1);
    cout << "After Merge Sort: \n";
    print(arr, sz);

    delete [] arr;
    return 0;
}
