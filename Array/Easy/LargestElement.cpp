// Given an array 'ARR' of size 'N' find the largest element in the array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int largestElement(vector<int> &arr);
int main(void)
{
    vector<int> vec = {1, 8, 7, 56, 100, 90};
    int element = largestElement(vec);
    cout << "Lagrest element in the array is => " << element << endl;
    return 0;
}

// Time Complexity => O(n)
int largestElement(vector<int> &arr)
{
    int max_element = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (max_element < arr[i])
        {
            max_element = arr[i];
        }
    }
    return max_element;
}

// Time Complexity => O(n)
// int largestElement(vector<int> &arr)
// {
//     int largest_element = *max_element(arr.begin(), arr.end());

//     return largest_element;
// }