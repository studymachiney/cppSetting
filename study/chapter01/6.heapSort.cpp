#include <iostream>
#include <vector>
using namespace std;
//堆排序
//某个数出现在index位置，往上移动
void heapInsert(vector<int> &arr, int index)
{
    while (arr[index] > arr[(index - 1) / 2])
    {

        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
//某个数在index位置，能否往下移动
void heapify(vector<int> &arr, int index, int heapSize)
{
    int left = 2 * index + 1; //左孩子下标
    while (left < heapSize)
    {
        int largest = (left + 1 < heapSize) && (arr[left + 1] > arr[left]) ? left + 1 : left;
        largest = arr[largest] > arr[index] ? largest : index;
        if (largest == index)
            break;
        swap(arr[largest], arr[index]);
        index = largest;
        left = 2 * index + 1;
    }
}
void heapSort(vector<int> &arr)
{
    if (arr.size() < 2)
        return;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     heapInsert(arr, i);
    // }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        heapify(arr, i, arr.size());
    }
    int heapSize = arr.size() - 1;
    swap(arr[0], arr[heapSize]);
    while (heapSize > 0)
    {
        heapify(arr, 0, heapSize);
        swap(arr[0], arr[--heapSize]);
    }
}
int main()
{
    vector<int> arr{1, 24, 6, 3, 67, 54, 234, 5, 574, 32, 563, 5, 3, 7, 5, 66, 74};
    heapSort(arr);
    for (int item : arr)
    {
        cout << item << " ";
    }
    return 0;
}