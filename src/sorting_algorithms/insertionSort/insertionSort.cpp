#include <iostream>
#include <vector>
#include "../../utils/utils.hpp"

int binarySearchHelper(vector<int> &A, int v, int start, int end)
{
    int q = (end + start) / 2;

    if (A[q] <= v && v <= A[q + 1])
        return q + 1;

    if (q == start)
        return start;

    if (A[q] < v)
        return binarySearchHelper(A, v, q, end);
    return binarySearchHelper(A, v, start, q);
}

void insertionSortHelper(vector<int> &A, int p)
{
    if (p >= A.size())
        return;

    int k = A[p];
    int l = binarySearchHelper(A, k, 0, p);

    for (int i = p; i > l; i--)
    {
        A[i] = A[i - 1];
    }

    A[l] = k;
    insertionSortHelper(A, p + 1);
}


void insertionSort(vector<int> &A)
{
    insertionSortHelper(A, 1);
}

int main()
{
    vector<int> ipt = generateRandVec(20000, 100000);
    auto exeTime = sortingFuncExecTime(insertionSort, ipt);
    printVec(ipt);

    cout << "Verification: " << verifySortedVec(ipt) << endl;
    cout << "Time: " <<  exeTime  << endl;
}