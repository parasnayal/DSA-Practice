// Linear Search
#include <iostream>
#include <vector>
using namespace std;
int linearSearch(int n, int num, vector<int> &arr);
int main(void)
{
    vector<int> nums = {6, 7, 8, 4, 1};
    int num = 4;
    int n = nums.size();
    linearSearch(n, num, nums);
    return 0;
}

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}
