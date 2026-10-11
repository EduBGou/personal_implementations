#include <iostream>
#include <vector>
#include <algorithm>
#include "utils/utils.hpp"

using namespace std;

int binarySearchHelper(vector<int> &v, int n, int start, int end)
{
    int p = (end + start) / 2;

    if (v[p] == n)
        return p;

    if (p == start)
    {
        int difL = abs(v[p] - n);
        int difR = abs(v[p + 1] - n);
        return difL <= difR ? p : p + 1;
    }

    if (v[p] < n)
        return binarySearchHelper(v, n, p, end);

    return binarySearchHelper(v, n, start, p);
}

int closestBinarySearch(vector<int> &v, int n)
{
    return binarySearchHelper(v, n, 0, v.size());
}

int main()
{
    int val = 50000;
    vector<int> ipt = generateRandomVector(20000, 100000);
    sort(ipt.begin(), ipt.end());

    int index = closestBinarySearch(ipt, val);
    printVector(ipt);
    cout << "The index (p) of the nearest element in the sorted vector of val=" << val << " is p=" << index << ", since v[p]=" << ipt[index] << endl;
}