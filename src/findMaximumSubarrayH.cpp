#include <iostream>
#include <vector>
#include <chrono>
#include "utils/utils.hpp"

using namespace std;

// Brute Force
vector<int> findMaximumSubarrayH(vector<int> &V)
{
    int maxSum = V[0], left = 0, right = 0;
    for (int i = 0; i < V.size(); ++i)
    {
        int s = V[i];
        for (int j = i; j < V.size(); ++j)
        {
            s += V[j];
            if (s > maxSum)
            {
                maxSum = s;
                left = i;
                right = j;
            }
        }
    }
    return {left, right, maxSum};
}

int main()
{
    vector<int> ipt = generateRandVec(20000, 100000);
    auto start = chrono::high_resolution_clock::now();
    vector<int> res = findMaximumSubarrayH(ipt);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exeTime = end - start;
    printVec(ipt);
    cout << "start=" << res[0] << " (" << ipt[res[0]] << ") end=" << res[1] << " (" << ipt[res[1]] << ") sum=" << res[2] << endl;
    cout << "findMaximumSubarayH: " << exeTime << std::endl;
}