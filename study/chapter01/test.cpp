#include <iostream>
#include <algorithm>
#include <vector>
#include "tool.h"
using namespace std;
void insertionSort(vector<int> &arr)
{
    if (arr.size() < 2)
        return;
    for (int i = 1; i < arr.size(); i++)
    { // 0~i 排序
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
        {
            swap(arr, j, j + 1);
        }
    }
}
//对数器
int main(int, char **)
{
    int testTime = 1000;
    int maxSize = 1000;
    int maxValue = 1000;
    bool succeed = true;
    for (int i = 0; i < testTime; i++)
    {
        vector<int> arr1 = generateRandomArray(maxSize, maxValue);
        vector<int> arr2(arr1);
        insertionSort(arr1);
        sort(arr2.begin(), arr2.end());
        if (arr1 != arr2)
        {
            succeed = false;
            break;
        }
    }
    cout << (succeed ? "successful" : "fail") << endl;
    return 0;
}
