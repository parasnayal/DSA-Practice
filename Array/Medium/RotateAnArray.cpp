// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k);
void display(vector<int> &nums);

int main(void)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    display(nums);
    return 0;
}

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    if (n == 1 || k == 0)
    {
        return;
    }

    vector<int> temp(k);

    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[n -  k + i];
    }

    for (int i = n; i > k; i--)
    {
        nums[i - 1] = nums[i - 1 - k];
    }

    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
}
void display(vector<int> &nums)
{
    for (auto it : nums)
    {
        cout << it << "\t";
    }
}