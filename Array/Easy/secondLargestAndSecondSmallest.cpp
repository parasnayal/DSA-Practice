// Find Second Smallest and Second Largest Element in an array(unique non-negative integers)
// Input : 'N' = 5 , 'A' = [1,2,3,4,5];
// Output :[4,2]

// Brute force => My brute force approach is => first sort an array then find the second largest and second minimum .In this way time complexity is => O(nlogn)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void sortArray(vector<int> &arr);
vector<int> findSecondLargestAndMinimum(vector<int> &arr);
int main(void)
{
    vector<int> vec = {3,4,5,2};

    // sortArray(vec);
    vector<int> result = findSecondLargestAndMinimum(vec);
    cout << "Second minimum element of the array =>  " << result.at(0) << endl;
    cout << "Second largest element of the array => " << result.at(1) << endl;
    return 0;
}
void sortArray(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}
vector<int> findSecondLargestAndMinimum(vector<int> &arr)
{

    // ***** Brute force approach ********
    // int second_minimum = *(arr.begin() + 1);
    // int second_largest = *(arr.end() - 2);
    // return {second_minimum, second_largest};

    // ****** Better Approach
    int n = arr.size();
    int largest_index = 0;
    int minimum_index = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[largest_index] < arr[i])
        {
            largest_index = i;
        }
        if (arr[minimum_index] > arr[i])
        {
            minimum_index = i;
        }
    }

    int second_largest_index = 0;
    int second_minimum_index = 0;
    cout << "Minimum index => " << minimum_index << endl;
    cout << "Minimum element => " << arr[minimum_index] << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[largest_index] && arr[second_largest_index] < arr[i])
        {
            second_largest_index = i;
        }
        if (i == 0 && arr[i] == arr[minimum_index])
        {
            second_minimum_index = 1;
        }
        else if ((arr[minimum_index] != arr[i] && (arr[second_minimum_index] > arr[minimum_index]) && (arr[second_minimum_index] > arr[i])))
        {
            cout << i << endl;
            second_minimum_index = i;
        }
    }
    return {arr[second_minimum_index], arr[second_largest_index]};
}