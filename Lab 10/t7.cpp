#include <iostream>
using namespace std;

int findLargestIndex(int arr[], int size, int index, int maxIndex)
{
    if (index == size)
        return maxIndex;

    if (arr[index] > arr[maxIndex])
        maxIndex = index;

    return findLargestIndex(arr, size, index + 1, maxIndex);
}

bool subsetSum(int arr[], int size, int index, int target)
{
    if (target == 0)
        return true;

    if (index == size || target < 0)
        return false;

    return subsetSum(arr, size, index + 1, target - arr[index]) ||
        subsetSum(arr, size, index + 1, target);
}

void removeElement(int arr[], int& size, int index)
{
    if (index == size - 1)
    {
        size--;
        return;
    }

    arr[index] = arr[index + 1];

    removeElement(arr, size, index + 1);
}

void copyRecursive(int arr[], int temp[], int size, int largestIndex, int i, int& j)
{
    if (i == size)
        return;

    if (i != largestIndex)
    {
        temp[j] = arr[i];
        j++;
    }

    copyRecursive(arr, temp, size, largestIndex, i + 1, j);
}

int findMagicNumber(int arr[], int size)
{
    if (size == 0)
        return -1;

    int largestIndex = findLargestIndex(arr, size, 0, 0);
    int largest = arr[largestIndex];

    int temp[100];
    int j = 0;

    copyRecursive(arr, temp, size, largestIndex, 0, j);

    if (subsetSum(temp, j, 0, largest))
        return largest;

    removeElement(arr, size, largestIndex);

    return findMagicNumber(arr, size);
}

int main()
{
    int arr[] = { 2, 3, 5, 8, 13 };
    int size = 5;

    int result = findMagicNumber(arr, size);

    cout << result << endl;

    return 0;
}