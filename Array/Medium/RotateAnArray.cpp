// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]

#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> &arr, int k);
int main(void)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    cout << nums[0] << endl;
    cout << nums[1] << endl;
    cout << nums[2] << endl;
    cout << nums[3] << endl;
    cout << nums[4] << endl;
    cout << nums[5] << endl;
    cout << nums[6] << endl;
    return 0;
}
void rotate(vector<int> &arr, int k)
{
    int temp[k];
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i];
    }
    for (int i = n - k; i >= 0; i--)
    {
        arr[k + i - 1] = arr[i - 1];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}