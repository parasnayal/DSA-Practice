// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums);

int main(void)
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    return 0;
}

// Brute force approach => using temp array
// Time Complexity => O(N)
// Space Complexity => O(size of array - number of zeroes) => O(N) in worst case

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0 || n == 1)
    {
        return;
    }

    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            temp.push_back(nums[i]);
        }
    }

    for (int i = temp.size(); i < n; i++)
    {
        temp.push_back(0);
    }

    nums.assign(temp.begin(), temp.end());
}