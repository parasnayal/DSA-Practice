// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// Input: nums = [4,1,2,1,2]
// Output: 4

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums);

int main(void)
{
    vector<int> nums{4, 1, 2, 1, 2};
    singleNumber(nums);
    return 0;
}

// Brute force approach
// Time Complexity => O(n^2)

// int singleNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     int uniqueNumber;
//     for (int i = 0; i < n; i++)
//     {
//         int flag = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (nums[i] == nums[j])
//             {
//                 flag++;
//             }
//         }
//         if (flag == 1)
//         {
//             uniqueNumber = nums[i];
//         }
//     }
//     return uniqueNumber;
// }

// Optimal approach
// Time complexity => o(n)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= nums[i];
    }
    return xor1;
}