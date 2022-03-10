#include <iostream>
#include <vector>
using namespace std;
// һ�����飬�����������������Σ�����������ż���Σ��ҵ���������
void printOddTimesNum(const vector<int> &arr)
{
    int eor = 0;
    for (int curNum : arr)
    {
        eor ^= curNum;
    }
    // eor = a^b
    // eor != 0
    // eor��Ȼ��һ��λ������1
    int rightOne = eor & (~eor + 1); // ��ȡ�����ұߵ�1

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
