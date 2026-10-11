#include <iostream>
#include <vector>
#include "../utils/utils.hpp"

using namespace std;

void selectionSort(vector<int>& v)
{
    for (int i = v.size() - 1; i >= 0; --i)
    {
        int temp = v[i];
        int max_idx = maxValueIndex(v, i);
        v[i] = v[max_idx];
        v[max_idx] = temp;
    }
}

int main()
{
    vector<int> ipt = generateRandomVector(20000, 100000);
    auto exeTime = funcExecutionTime(selectionSort, ipt);

    printVector(ipt);

    cout << "Verification: " << verifySorted(ipt) << endl;
    cout << "Time: " << exeTime << endl;
}