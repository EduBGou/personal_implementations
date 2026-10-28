#include <iostream>
#include <vector>
#include <chrono>
#include "utils/utils.hpp"

using namespace std;

// Iterative
vector<int> findMaximumSubarrayI(vector<int> &nums)
{
    if (nums.empty())
        return {-1, -1, 0};

    int maxSum = nums[0], acMaxSum = nums[0], acFromLastNegativeSum = 0, lastNegativeIdx = 0;

    vector<int> maxRange = {0, 0};

    for (int i = 1; i < nums.size(); ++i)
    {
        int v = nums[i];

        acMaxSum += v;
        acFromLastNegativeSum += v;

        if (acMaxSum > maxSum)
        {
            maxRange[1] = i;
            maxSum = acMaxSum;
        }

        if (acFromLastNegativeSum > maxSum && acFromLastNegativeSum > acMaxSum)
        {
            maxRange = {lastNegativeIdx + 1, i};
            maxSum = acFromLastNegativeSum;
            acMaxSum = acFromLastNegativeSum;
        }

        if (v < 0 && acFromLastNegativeSum <= 0)
        {
            lastNegativeIdx = i;
            acFromLastNegativeSum = 0;
        }
    }

    return {maxRange[0], maxRange[1], maxSum};
}

int main()
{
    // vector<int> ipt = generateRandomVector(20000, 100000);
    vector<int> ipt = {8, -19, 5, -4, 20};
    
    // returns sum=20 instead of 21 in case [8,-19,5,-4,20]

    auto start = chrono::high_resolution_clock::now();
    vector<int> res = findMaximumSubarrayI(ipt);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exeTime = end - start;
    printVec(ipt);
    cout << "start=" << res[0] << " (" << ipt[res[0]] << ") end=" << res[1] << " (" << ipt[res[1]] << ") sum=" << res[2] << endl;
    cout << "findMaximumSubarayI: " << exeTime << endl;
}