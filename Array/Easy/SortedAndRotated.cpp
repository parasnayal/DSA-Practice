// Check if Array Is Sorted and Rotated

// Input: nums = [3,4,5,1,2]
// Output: true

// Time Complexity => O(n)

#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> &nums);
int main(void)
{
    vector<int> nums = {3, 4, 5, 1, 2};
    check(nums);
    return 0;
}

bool check(vector<int> &nums)
{

    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
    }
    return count > 1 ? false : true;
}