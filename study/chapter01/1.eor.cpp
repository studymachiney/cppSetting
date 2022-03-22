#include <iostream>
#include <vector>
using namespace std;
// 一个数组，有两种数出现奇数次，其他数出现偶数次，找到这两种数
void printOddTimesNum(const vector<int> &arr)
{
    int eor = 0;
    for (int curNum : arr)
    {
        eor ^= curNum;
    }
    // eor = a^b
    // eor != 0
    // eor必然有一个位置上是1
    int rightOne = eor & (~eor + 1); // 提取出最右边的1

    int onlyOne = 0;
    for (int cur : arr)
    {
        if ((cur & rightOne) == 1)
        {
            onlyOne ^= cur;
        }
    }

    cout << onlyOne << " " << (eor ^ onlyOne) << endl;
}
int main(int, char **)
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5};
    printOddTimesNum(arr);
    return 0;
}
