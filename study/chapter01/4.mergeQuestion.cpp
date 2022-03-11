#include <iostream>
#include <vector>
using namespace std;
// С������
// ��һ�������У�ÿһ������߱ȵ�ǰ��С�����ۼ�������������������С�͡���һ�������С�͡�
// ����:[1,3,4,2,5]1��߱�1С������û��;3��߱�3С������1;4��߱�4С������1��3;2��߱�2С������1;5��߱�5С������1��3��4��2;����С��Ϊ1+1+3+1+1+3+4+2=16
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

//�����������һ�������У���ߵ���������ұߵ�������������������һ������ԣ����ӡ��������ԡ�
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