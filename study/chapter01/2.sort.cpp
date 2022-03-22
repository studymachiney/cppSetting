#include <iostream>
#include <algorithm>
#include <vector>
#include <windows.h>
#include "tool.h"
using namespace std;

//插入排序
void insertionSort(vector<int> &arr)
{
    if (arr.size() < 2)
        return;
    for (int i = 1; i < arr.size(); i++)
    { // 0~i 有序
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
        {
            swap(arr, j, j + 1);
        }
    }
}

//归并排序
void merge(vector<int> &arr, int L, int M, int R)
{
    int help[R - L + 1];
    int i = 0, p1 = L, p2 = M + 1;
    while (p1 <= M && p2 <= R)
    {
        help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= M)
    {
        help[i++] = arr[p1++];
    }
    while (p2 <= R)
    {
        help[i++] = arr[p2++];
    }
    for (i = 0; i < R - L + 1; i++)
    {
        arr[L + i] = help[i];
    }
}
void process(vector<int> &arr, int L, int R)
{
    if (L == R)
        return;
    int mid = L + ((R - L) >> 1);
    process(arr, L, mid);
    process(arr, mid + 1, R);
    merge(arr, L, mid, R);
}

int main(int, char **)
{
    vector<int> arr = generateRandomArray(30, 100);
    insertionSort(arr);
    cout << "插入排序" << endl;
    for (int item : arr)
    {
        cout << item << " ";
    }
    Sleep(1000);
    arr = generateRandomArray(30, 100);
    process(arr, 0, arr.size() - 1);
    cout << endl
         << "归并排序" << endl;
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;

    //对数器测试
    int testTime = 1000;
    int maxSize = 1000;
    int maxValue = 1000;
    bool succeed = true;
    for (int i = 0; i < testTime; i++)
    {
        vector<int> arr1 = generateRandomArray(maxSize, maxValue);
        vector<int> arr2(arr1);
        // insertionSort(arr1);
        process(arr1, 0, arr1.size() - 1);
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
