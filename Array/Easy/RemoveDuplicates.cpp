// Remove duplicate from the sorted Array
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

// Brute Force approach
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicate(vector<int> &nums);

int main(void)
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    removeDuplicate(nums);
    return 0;
}


// Brute force approach
// Time Complexity => O(N)
// Space Complexity => O(N)

int removeDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int previousElement;
    if (n == 0 || n == 1)
    {
        return n;
    }
    int j = 0;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            temp.push_back(nums[i]);
            previousElement = nums[i];
            j++;
        }
        else
        {
            if (nums[i] != previousElement)
            {
                temp.push_back(nums[i]);
                previousElement = nums[i];
                j++;
            }
        }
    }
    nums.assign(temp.begin(), temp.end());
    return j;
}