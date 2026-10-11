#include <iostream>
#include <vector>
#include "../utils/utils.hpp"

using namespace std;

void quickSortHelper(vector<int> &v, int p, int q)
{
    if (p >= q) return;

    int i = p-1, j = p;

    while (j <= q)
    {
        if (v[j] < v[q])
        {
            int temp = v[++i];
            v[i] = v[j];
            v[j] = temp;
        }
        ++j;
    }

    int temp = v[++i];
    v[i] = v[q];
    v[q] = temp;

    quickSortHelper(v, p, i-1);
    quickSortHelper(v, i+1, q);
}

void quickSort(vector<int> &v)
{
    quickSortHelper(v, 0, v.size() - 1);
}

int main()
{
    vector<int> ipt = generateRandomVector(20000, 100000);
    auto exeTime = funcExecutionTime(quickSort, ipt);

    printVector(ipt);

    cout << "Verification: " << verifySorted(ipt) << endl;
    cout << "Time: " << exeTime << endl;
}
