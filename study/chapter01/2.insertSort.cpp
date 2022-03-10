#include <iostream>
#include <vector>
using namespace std;
// i和j是不得为同一个位置
void swap(vector<int> &arr, int i, int j)
{
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}
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
int main(int, char **)
{
    vector<int> arr = {1, 2, 6, 4, 2, 99, 4, 33, 77, 26, 0};
    insertionSort(arr);
    for (int item : arr)
    {
        cout << item << endl;
    }
    return 0;
}
