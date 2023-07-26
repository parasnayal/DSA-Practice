// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k);
void reverse(vector<int> &nums, int start, int end);
void display(vector<int> &nums);

int main(void)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);
    display(nums);

    return 0;
}

// Brute force approach => using temp array
// Time Complexity => O(n)
// Space Complexity => O(K)
// void rotate(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     k = k % n;
//     if (n == 1 || k == 0)
//     {
//         return;
//     }

//     vector<int> temp(k);

//     for (int i = 0; i < k; i++)
//     {
//         temp[i] = nums[n - 1 - i];
//     }

//     for (int i = n - 1; i >= k; i--)
//     {
//         nums[i] = nums[i - k];
//     }

//     for (int i = 0; i < k; i++)
//     {
//         nums[i] = temp[k - 1 - i];
//     }
// }

// Optimal solution => using reversal algorithm
// Time Complexity => O(N)
// Space Complexity => O(1)

void reverse(vector<int> &nums, int start, int end)
{

    while (start <= end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    if (n == 1 || k == 0)
    {
        return;
    }
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - k - 1);
    reverse(nums, 0, n - 1);
}

void display(vector<int> &nums)
{
    for (auto it : nums)
    {
        cout << it << "\t";
    }
    cout << endl;
}