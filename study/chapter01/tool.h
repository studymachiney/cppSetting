#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;
vector<int> generateRandomArray(int maxSize, int maxValue)
{
    unsigned int seed = ((int)time(NULL));
    srand(seed);
    vector<int> arr(rand() % maxSize + 1);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = (rand() % maxValue + 1) - (rand() % maxValue + 1);
    }
    return arr;
}
void swap(vector<int> &arr, int i, int j)
{
    if (i == j)
        return;
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}