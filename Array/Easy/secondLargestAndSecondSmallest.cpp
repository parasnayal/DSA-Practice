// Find the second largest and second minimum element in an array (unique non negative integers)

#include <iostream>
#include <vector>
#include <climits>
// #include <algorithm>
using namespace std;

// void sortArray(vector<int> &arr);

vector<int> getSecondOrderElements(vector<int> &arr);

// Brute force => first sort an array then find the second largest and second minimum .In this way time complexity is => O(nlogn).

int main(void)
{
    vector<int> vec = {3, 4, 5, 1, 2};

    // sortArray(vec);

    vector<int> vector_of_second_ordere_elements = getSecondOrderElements(vec);
    cout << "Second largest element => " << vector_of_second_ordere_elements.at(0) << endl;
    cout << "Second minimum element => " << vector_of_second_ordere_elements.at(1) << endl;
    return 0;
}

// void sortArray(vector<int> &arr)
// {
//     sort(arr.begin(), arr.end());
// }

vector<int> getSecondOrderElements(vector<int> &arr)
{
    /*int second_largest_element = *(arr.end() - 2);
    int second_minimum_element = *(arr.begin() + 1);

    return {second_largest_element, second_minimum_element};*/

    // Better approach => So complexity => O(2N).

    /* int largest_element = INT_MIN;
    int minimum_element = INT_MAX;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (largest_element < arr[i])
        {
            largest_element = arr[i];
        }
        if (minimum_element > arr[i])
        {
            minimum_element = arr[i];
        }
    }
    int second_largest_element = INT_MIN;
    int second_minimum_element = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] < largest_element) && (second_largest_element < arr[i]))
        {
            second_largest_element = arr[i];
        }

        if ((minimum_element < arr[i]) && (second_minimum_element > arr[i]))
        {
            second_minimum_element = arr[i];
        }
    }
    return {second_largest_element, second_minimum_element};*/

    // Optimal approach => O(n)

    int n = arr.size();
    if (n == 2)
    {
        return {-1, -1};
    }

    int largest_element = arr[0];
    int second_largest_element = -1;

    int minimum_element = arr[0];
    int second_minimum_element = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (largest_element < arr[i])
        {
            second_largest_element = largest_element;
            largest_element = arr[i];
        }
        else if (arr[i] < largest_element && second_largest_element < arr[i])
        {
            second_largest_element = arr[i];
        }
        if (minimum_element > arr[i])
        {
            second_minimum_element = minimum_element;
            minimum_element = arr[i];
        }
        else if (minimum_element < arr[i] && second_minimum_element > arr[i])
        {
            second_minimum_element = arr[i];
        }
    }
    return {second_largest_element, second_minimum_element};
}