// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int missingNumber(vector<int> &nums);
int main(void)
{
    vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
    missingNumber(nums);
    return 0;
}

// Brute force aprroach
// Time complexity => O(n ^2)

// int missingNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     int missingNumber;
//     for (int i = 0; i <= n; i++)
//     {
//         int flag = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (i == nums[j])
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0)
//         {
//             missingNumber = i;
//             break;
//         }
//     }
//     return missingNumber;
// }

// Optimal Approach
// Time Complexity => O(n)

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum_of_n_element = n * (n + 1) / 2;
    int sum_of_array_element = accumulate(nums.begin(), nums.end(), 0);
    int missingNumber = sum_of_n_element - sum_of_array_element;
    return missingNumber;
}