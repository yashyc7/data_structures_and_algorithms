#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int(len1);
    int *second = new int(len2);
    // cppy values
      
    int mainArrayIndex = s; 
        int  k = mid + 1;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }


    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
  
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void mergeSort(int *arr, int s, int e)
{

    // base case
    if (s >= e)
    {
        return;
    } 
    int mid = s + (e - s) / 2;  
    // sorting left part
    mergeSort(arr, s, mid);
    // right part sort
    mergeSort(arr, mid + 1, e);
    // merg e
    merge(arr, s, e);
}

int main()
{
    int arr[5] = {3, 5, 2, 1, 8};
    int n = 5;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}