// Find the second largest and second minimum element in an array (unique non-negative integers).
// Input : 'N' = 5 , 'A' = [1,2,3,4,5];
// Output :[4,2]

// Brute force => first sort an array then find the second largest and second minimum .In this way time complexity is => O(nlogn).

#include <iostream>
#include <vector>
#include <climits>
// #include <algorithm>
using namespace std;

void sortArray(vector<int> &arr);

vector<int> getSecondOrderElements(vector<int> &arr);

int main(void)
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};

    // sortArray(vec);
    vector<int> vectorOfElement = getSecondOrderElements(vec);
    cout << "Second largest element => " << vectorOfElement.at(0) << endl;
    cout << "Second minimum element => " << vectorOfElement.at(1) << endl;
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

    /*
        ******* Better approach takes O(N) and loop running 2 times
    int largest_element = INT_MIN;
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
        if ((arr[i] != largest_element) && (second_largest_element < arr[i]))
        {
            second_largest_element = arr[i];
        }

        if ((arr[i] != minimum_element) && (arr[i] < second_minimum_element))
        {
            second_minimum_element = arr[i];
        }
    }
    cout << second_largest_element << endl;
    cout << second_minimum_element << endl;

    return {second_largest_element, second_minimum_element};*/

    int largest_element = arr[0], minimum_element = arr[0];
    cout << largest_element << endl;
    cout << minimum_element << endl;
    int second_largest_element, second_minimum_element;
    cout << second_largest_element << endl;
    cout << second_minimum_element << endl;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest_element)
        {
            second_largest_element = largest_element;
            largest_element = arr[i];
        }
        else if ((arr[i] < largest_element) && (arr[i] > second_largest_element))
        {
            second_largest_element = arr[i];
        }

        if (arr[i] < minimum_element)
        {
            second_minimum_element = minimum_element;
            minimum_element = arr[i];
        }
        else if (arr[i] > minimum_element && arr[i] < second_minimum_element)
        {
            second_minimum_element = arr[i];
        }
    }
    cout << second_largest_element << endl;
    cout << second_minimum_element << endl;
    return {second_largest_element, second_minimum_element};
}