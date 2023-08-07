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

vector<int> unionOfSortedArrays(vector<int> nums1, vector<int> nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int i = 0;
    int j = 0;

    vector<int> temp;

    while (i < n && j < m)
    {
        cout << "Inside while loop" << endl;
        if (nums1[i] == nums2[j])
        {
            cout << "1" << endl;
            temp.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            cout << "2" << endl;
            temp.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            cout << "3" << endl;
            temp.push_back(nums2[j]);
            j++;
        }
    }

    while (i < n)
    {
        if (temp.back() != nums1[i] && temp.back() < nums1[i])
        {
            cout << "4" << endl;
            temp.push_back(nums1[i]);
            i++;
        }
        else if (temp.back() == nums1[i])
        {
            i++;
            break;
        }
    }
    while (j < m)
    {
        if (temp.back() != nums2[j] && temp.back() < nums2[j])
        {
            cout << "5" << endl;
            temp.push_back(nums2[j]);
            j++;
        }
        else if (temp.back() == nums2[j])
        {
            j++;
            break;
        }
    }
    cout << temp[0] << endl;
    cout << temp[1] << endl;
    cout << temp[2] << endl;
    cout << temp[3] << endl;
    return temp;
}
