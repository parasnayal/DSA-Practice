// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Input: nums = [1,1,0,1,1,1]
// Output: 3

#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums);

int main(void)
{
    vector<int> nums{1, 1, 0, 1, 1, 1};
    findMaxConsecutiveOnes(nums);
    return 0;
}

// Time complexity => O(n)

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int finalCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            count++;
        }
        if (i == (n - 1) || nums[i] == 0)
        {
            if (finalCount < count)
            {
                finalCount = count;
                count = 0;
            }
            else
            {
                count = 0;
            }
        }
    }
    return finalCount;
}