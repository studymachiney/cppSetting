#include <iostream>
#include <vector>
#include <queue>
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

//已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数据进行排序。
void sortedArrDistanceLessK(vector<int> &arr, int k)
{
    //优先级队列
    // priority_queue<int, vector<int>, less<int>> heap;//不写第三个参数或者写成less都是大根堆
    priority_queue<int, vector<int>, greater<int>> heap; //greater是小根堆
    int index = 0;
    for (; index <= min((int)(arr.size()), k); index++)
    {
        heap.push(arr[index]);
    }
    int i=0;
    for(;index<arr.size();i++,index++) {
        heap.push(arr[index]);
        arr[i] = heap.top();
        heap.pop();
    }
    while(!heap.empty()) {
        arr[i++] = heap.top();
        heap.pop();
    }
}
int main()
{
    vector<int> arr{1,5,3,2,7,98,77,34,65};
    // heapSort(arr);
    sortedArrDistanceLessK(arr, 4);
    for (int item : arr)
    {
        cout << item << " ";
    }
    return 0;
}