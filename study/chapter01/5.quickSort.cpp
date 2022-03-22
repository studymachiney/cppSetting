#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;
// 荷兰国旗问题
// 给定一个数组arr，和一个数num，请把小于num的数放在数组的左边，等于num的数放在数组的中问，大于num的数放在数组的 右边。要求额外空间复杂度O(1)，时间复杂度O(N)
void setAreaArr(vector<int>& arr, int num)
{
    int n = arr.size(), left = 0, i = 0, right = n - 1;
    while (i < right)
    {
        if (arr[i] < num)
        {
            swap(arr[i++], arr[left++]);
        }
        else if (arr[i] > num)
        {
            swap(arr[i], arr[right--]);
        }
        else
        {
            i++;
        }
    }
}
//快速排序
vector<int> partition(vector<int>& arr, int L, int R)
{
    vector<int> result;
    int less = L - 1; //小于区右边界
    int more = R;     //大于区左边界
    while (L < more)
    { // L表示当前数位置
        if (arr[L] < arr[R])
        {
            swap(arr[++less], arr[L++]);
        }
        else if (arr[L] > arr[R])
        {
            swap(arr[L], arr[--more]);
        }
        else
        {
            L++;
        }
    }
    swap(arr[more],arr[R]);
    result.push_back(less+1);
    result.push_back(more);
    return result;
}
void quickSort(vector<int> &arr, int L, int R)
{
    if (L < R)
    {
        unsigned int seed = ((int)time(NULL));
        srand(seed);
        swap(arr[L + rand() % (R - L + 1)], arr[R]);
        vector<int> p = partition(arr, L, R);
        quickSort(arr, L, p[0] - 1);
        quickSort(arr, p[1] + 1, R);
    }
}
int main()
{
    vector<int> arr{1, 2, 7, 4, 5, 3, 2, 9, 6, 5, 4, 3, 6, 5, 5, 2, 4, 6, 5};
    // setAreaArr(arr, 5);
    quickSort(arr, 0, arr.size() - 1);
    for (int item : arr)
    {
        cout << item << " ";
    }
    return 0;
}