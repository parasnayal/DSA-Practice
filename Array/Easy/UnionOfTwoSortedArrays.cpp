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
    vector<int> nums1 = {4, 3};
    vector<int> nums2 = {1, 2, 3, 3};
    unionOfSortedArrays(nums1, nums2);
    return 0;
}

// Brute force approach => using set
// Time Complexity => O(n*logn + m*logm) => m , n size of the arrays
// Space Complexity => O(m+n)
// vector<int> unionOfSortedArrays(vector<int> nums1, vector<int> nums2)
// {
//     set<int> st;
//     int n1 = nums1.size();
//     int n2 = nums2.size();
//     for (int i = 0; i < n1; i++)
//     {
//         st.insert(nums1[i]);
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         st.insert(nums2[i]);
//     }
//     vector<int> temp(st.begin(), st.end());
//     return temp;
// }

// Time complexity => O(n)

vector<int> unionOfSortedArrays(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    int i = 0;
    int j = 0;

    vector<int> temp;

    while (i < n && j < m)
    {
        if (a[i] == b[j] && (i == 0 || temp.back() != a[i]))
        {

            temp.push_back(a[i]);
            i++;
            j++;
        }
        else
        {
            if (i != 0 && temp.back() == a[i])
            {
                i++;
            }
            else if (i != 0 && temp.back() == b[j])
            {
                j++;
            }
            else if (a[i] > b[j])
            {
                temp.push_back(b[j]);
                j++;
            }
            else
            {
                temp.push_back(a[i]);
                i++;
            }
        }
    }

    while (i < n)
    {
        if (temp.back() != a[i])
        {
            temp.push_back(a[i]);
        }

        i++;
    }

    while (j < m)
    {
        if (temp.back() != b[j])
        {
            temp.push_back(b[j]);
        }

        j++;
    }

    return temp;
}