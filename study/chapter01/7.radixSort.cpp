#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#include <math.h>

int maxbits(vector<int> &arr)
{
    int maxNum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxNum = max(maxNum, arr[i]);
    }
    int res = 0;
    while (maxNum != 0)
    {
        res++;
        maxNum /= 10;
    }
    return res;
}
int getDigit(int num, int d)
{
    return ((num / ((int)pow(10, d - 1))) % 10);
}
void radixSort(vector<int> &arr, int L, int R, int digit)
{
    int radix = 10;
    int i = 0, j = 0;
    //准备辅助空间
    int bucket[R - L + 1];
    for (int d = 1; d <= digit; d++)
    {
        vector<int> count(radix);
        for (i = L; i <= R; i++)
        {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for (i = 1; i < radix; i++)
        {
            count[i] = count[i] + count[i - 1];
        }
        for (i = R; i >= L; i--)
        {
            j = getDigit(arr[i], d);
            bucket[--count[j]] = arr[i];
        }
        for (i = L, j = 0; i <= R; i++, j++)
        {
            arr[i] = bucket[j];
        }
    }
}
int main()
{
    vector<int> arr{1, 5, 3, 2, 7, 98, 77, 34, 65};
    radixSort(arr, 0, arr.size() - 1, 2);
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << maxbits(arr) << endl;
    return 0;
}