// Find the union of two sorted Arrays

// Input1 => [1,2,3,4,6]
// Input2 => [2,3,5]

#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> unionOfSortedArrays(vector<int> nums1, vector<int> nums2);
int main(void)
{
    vector<int> nums1 = {1, 2, 3, 4, 6};
    vector<int> nums2 = {2, 3, 5};
    unionOfSortedArrays(nums1, nums2);
    return 0;
}

// Brute force approach => using set
// Time Complexity => O(n*logn + m*logm) => m , n size of the arrays
// Space Complexity => O(m+n)
vector<int> unionOfSortedArrays(vector<int> nums1, vector<int> nums2)
{
    set<int> st;
    int n1 = nums1.size();
    int n2 = nums2.size();
    for (int i = 0; i < n1; i++)
    {
        st.insert(nums1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        st.insert(nums2[i]);
    }
    vector<int> temp(st.begin(), st.end());
    return temp;
}
