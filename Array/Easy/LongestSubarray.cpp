// Find the length of the longest subarray of 'a' whose sum is equal to 'k'.
// Input : 'n' = 7 , 'k' = 3
// 'A' = [1,2,3,1,1,1,1]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longestSubarrayWithSumK(vector<int> &nums, long long k);

int main(void)
{
    vector<int> nums{1, 2, 3, 1, 1, 1, 1};
    long long sum = 3;
    longestSubarrayWithSumK(nums, sum);
    return 0;
}

// Brute force approach
// Time Complexity => O(n^2)
// int longestSubarrayWithSumK(vector<int> &nums, long long k)
// {
//     int n = nums.size();
//     int length = 0;
//     for (int i = 0; i < n; i++)
//     {
//         long long sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += nums[j];
//             if (sum == k)
//             {
//                 length = max(length, j - i + 1);
//             }
//         }
//     }
//     return length;
// }

// Optimal approach
// Time Complexity => O(2n) => O(n)

int longestSubarrayWithSumK(vector<int> &nums, long long k)
{
    int n = nums.size();
    int length = 0;
    int left = 0;
    int right = 0;
    long long sum = 0;

    while (right < n)
    {
        sum += nums[right];
        while (left <= right && sum > k)
        {
            sum -= nums[left];
            left++;
        }

        if (sum == k)
        {
            length = max(length, right - left + 1);
        }
        right++;
    }
    return length;
}