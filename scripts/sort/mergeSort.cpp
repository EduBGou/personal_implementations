#include <iostream>
#include <vector>
#include "../utils/utils.hpp"

using namespace std;

void merge(vector<int> &A, int p, int q, int r)
{
    int nl = q - p;
    int nr = r - q;

    vector<int> L(nl);
    vector<int> R(nr);

    for (int i = 0; i < nl; i++)
    {
        L[i] = A[p + i];
    }

    for (int i = 0; i < nr; i++)
    {
        R[i] = A[q + i];
    }

    int j = 0;
    int k = 0;

    for (int i = p; i < r; i++)
    {
        if (j == nl)
        {
            A[i] = R[k];
            k++;
        }
        else if (k == nr || L[j] <= R[k])
        {
            A[i] = L[j];
            j++;
        }
        else
        {
            A[i] = R[k];
            k++;
        }
    }
}

void mergeSortHelper(vector<int> &A, int p, int r)
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;

        mergeSortHelper(A, p, q);
        mergeSortHelper(A, q, r);
        merge(A, p, q, r);
    }
}

void mergeSort(vector<int>& ipt)
{
    mergeSortHelper(ipt, 0, ipt.size());
}

int main()
{
    vector<int> ipt = generateRandomVector(20000, 100000);
    auto exeTime = funcExecutionTime(mergeSort, ipt);
    printVector(ipt);

    cout << "Verification: " << verifySorted(ipt) << endl;
    cout << "Time: " <<  exeTime  << endl;
}