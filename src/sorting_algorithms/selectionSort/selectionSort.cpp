#include <iostream>
#include <vector>
#include "../../utils/utils.hpp"


void selectionSort(vector<int>& v)
{
    for (int i = v.size() - 1; i >= 0; --i)
    {
        int temp = v[i];
        int max_idx = VecMaxValueIdx(v, i);
        v[i] = v[max_idx];
        v[max_idx] = temp;
    }
}

int main()
{
    vector<int> ipt = generateRandVec(20000, 100000);
    auto exeTime = sortingFuncExecTime(selectionSort, ipt);

    printVec(ipt);

    cout << "Verification: " << verifySortedVec(ipt) << endl;
    cout << "Time: " << exeTime << endl;
}