#include <iostream>
#include <vector>

using namespace std;
//二分法寻找局部最小值
int findLocalMinimum(vector<int> &arr)
{
    int n = arr.size();
    if (arr[0] < arr[1])
        return 0;
    if (arr[n - 1] < arr[n - 2])
        return n - 1;
    int left = 0, right = n - 1, middle;
    while (left < right)
    {

        middle = (left + right) / 2;
        cout << left << ' ' << middle << ' ' << right << endl;
        if (arr[middle] > arr[middle - 1])
        {
            right = middle;
        }
        else if (arr[middle] > arr[middle + 1])
        {
            left = middle;
        }
        else
        {
            return middle;
        }
    }
}
int main(int, char **)
{
    vector<int> arr = {11, 9, 8, 7, 6, 5, 4, 6, 13, 47, 89, 3, 7, 8, 32, 8, 99};
    cout<< findLocalMinimum(arr) <<endl;
    return 0;
}
