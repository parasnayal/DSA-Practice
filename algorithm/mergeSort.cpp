#include <iostream>
#include <cmath>
using namespace std;
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int main(void)
{
    int arr[] = {8, 3, 4, 6, 5, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;
    cout << arr[5] << endl;
    cout << arr[6] << endl;
    mergeSort(arr, 0, n - 1);

    cout << "after sorting" << endl;
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;
    cout << arr[5] << endl;
    cout << arr[6] << endl;
    return 0;
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void merge(int arr[], int low, int mid, int high)
{
    int sizeOfLeftArray = mid - low;
    int sizeOfRightArray = high - low + 1;
    int sizeOftempArray = sizeOfLeftArray + sizeOfRightArray;

    int leftArray[sizeOfLeftArray];
    int rightArray[sizeOfRightArray];
    int temp[sizeOftempArray];

    int m = low, n = mid;

    for (int i = 0; i < sizeOfLeftArray; i++)
    {
        leftArray[i] = arr[m++];
    }

    for (int i = 0; i < sizeOfRightArray; i++)
    {
        rightArray[i] = arr[n++];
    }

    int indexOfLeftSubArray = 0, indexOfRightSubArray = 0, k = low;

    while ((indexOfLeftSubArray < sizeOfLeftArray) && (indexOfRightSubArray < sizeOfRightArray))
    {
        if (leftArray[indexOfLeftSubArray] < rightArray[indexOfRightSubArray])
        {
            arr[k] = leftArray[indexOfLeftSubArray];
            k++;
            indexOfLeftSubArray++;
        }
        else
        {
            arr[k] = rightArray[indexOfRightSubArray];
            k++;
            indexOfRightSubArray++;
        }
    }
    while (indexOfLeftSubArray < sizeOfLeftArray)
    {
        arr[k] = leftArray[indexOfLeftSubArray];
        k++;
        indexOfLeftSubArray++;
    }
    while (indexOfRightSubArray < sizeOfRightArray)
    {
        arr[k] = rightArray[indexOfRightSubArray];
        k++;
        indexOfRightSubArray++;
    }
}