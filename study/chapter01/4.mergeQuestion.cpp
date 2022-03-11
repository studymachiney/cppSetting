#include <iostream>
#include <vector>
using namespace std;
// 小和问题
// 在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和。
// 例子:[1,3,4,2,5]1左边比1小的数，没有;3左边比3小的数，1;4左边比4小的数，1、3;2左边比2小的数，1;5左边比5小的数，1、3、4、2;所以小和为1+1+3+1+1+3+4+2=16
int merge(vector<int> &arr, int L, int M, int R)
{
    int temp[R - L + 1], p1 = L, p2 = M + 1, i = 0, sum = 0;
    while (p1 <= M && p2 <= R)
    {
        sum += arr[p1] < arr[p2] ? arr[p1] * (R - p2 + 1) : 0;
        temp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= M)
    {
        temp[i++] = arr[p1++];
    }
    while (p2 <= R)
    {
        temp[i++] = arr[p2++];
    }
    for (i = 0; i < R - L + 1; i++)
    {
        arr[L + i] = temp[i];
    }
    return sum;
}
int smallSum(vector<int> &arr, int L, int R)
{
    if (L == R)
        return 0;
    int M = L + ((R - L) >> 1);
    return smallSum(arr, L, M) +
           smallSum(arr, M + 1, R) +
           merge(arr, L, M, R);
}

//逆序对问题在一个数组中，左边的数如果比右边的数大，则这两个数构成一个逆序对，请打印所有逆序对。
void mergePair(vector<int> &arr, int L, int M, int R)
{
    int p1 = L, p2 = M + 1, i = 0, temp[R - L + 1];
    while (p1 <= M && p2 <= R)
    {
        if (arr[p1] > arr[p2])
        {
            for (int j = 0; j < M - p1 + 1; j++)
            {
                cout << arr[p1 + j] << " " << arr[p2] << endl;
            }
            temp[i++] = arr[p2++];
        }
        else
        {
            temp[i++] = arr[p1++];
        }
    }
    while (p1 <= M)
    {
        temp[i++] = arr[p1++];
    }
    while (p2 <= R)
    {
        temp[i++] = arr[p2++];
    }
    for (i = 0; i < R - L + 1; i++)
    {
        arr[L + i] = temp[i];
    }
}
void reversePair(vector<int> &arr, int L, int R)
{
    if (L == R)
        return;
    int M = L + ((R - L) >> 2);
    reversePair(arr, L, M);
    reversePair(arr, M + 1, R);
    mergePair(arr, L, M, R);
}
int main()
{
    vector<int> arr{
        1, 2, 3, 4, 1, 2};
    // cout << smallSum(arr, 0, arr.size() - 1) << endl;
    reversePair(arr, 0, arr.size() - 1);
    return 0;
}