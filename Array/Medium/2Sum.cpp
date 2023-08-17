// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> nums, int target);

int main(void)
{
    vector<int> nums{3, 2, 4};
    int target = 6;
    twoSum(nums, target);
    return 0;
}

// Brute force approach
// Time complexity => O(n)

vector<int> twoSum(vector<int> nums, int target)
{
    int n = nums.size();
    vector<int> indexes;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                indexes.push_back(i);
                indexes.push_back(j);
                return indexes;
            }
        }
    }
    return {-1, -1};
}