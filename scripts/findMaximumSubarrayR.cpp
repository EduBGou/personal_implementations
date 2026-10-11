#include <iostream>
#include <vector>
#include <chrono>
#include "utils/utils.hpp"

using namespace std;

// Recursive
vector<int> findMaximumCrossedSubarray(int start, int end, vector<int> &A)
{
    if (start == end)
        return vector<int>{start, end, start};

    int q = (start + end) / 2;

    int leftPivot{q};
    int maxLeftSum{A[leftPivot]};
    int currentLeftSum{maxLeftSum};

    int rightPivot{q + 1};
    int maxRightSum = A[rightPivot];
    int currentRightSum = maxRightSum;

    for (int i = 1; i < end - q; ++i)
    {
        currentLeftSum += A[q - i];
        if (currentLeftSum > maxLeftSum)
        {
            leftPivot = q - i;
            maxLeftSum = currentLeftSum;
        }

        if (q + i + 1 > end)
            continue;

        currentRightSum += A[q + i + 1];
        if (currentRightSum > maxRightSum)
        {
            rightPivot = q + i + 1;
            maxRightSum = currentRightSum;
        }
    }

    return vector<int>{leftPivot, rightPivot, maxLeftSum + maxRightSum};
}

vector<int> findMaximumSubarrayR(int start, int end, vector<int> &A)
{
    if (start == end)
        return vector<int>{start, start, A[start]};

    int q = (start + end) / 2;

    vector<int> leftSide = findMaximumSubarrayR(start, q, A);
    vector<int> rightSide = findMaximumSubarrayR(q + 1, end, A);
    vector<int> cross = findMaximumCrossedSubarray(start, end, A);

    if (leftSide[2] >= rightSide[2] && leftSide[2] >= cross[2])
        return leftSide;

    if (rightSide[2] >= leftSide[2] && rightSide[2] >= cross[2])
        return rightSide;

    return cross;
}

int main()
{
    vector<int> ipt = generateRandomVector(20000, 100000);
    auto start = chrono::high_resolution_clock::now();
    vector<int> res = findMaximumSubarrayR(0, ipt.size() - 1, ipt);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exeTime = end - start;
    printVector(ipt);
    cout << "start=" << res[0] << " (" << ipt[res[0]] << ") end=" << res[1] << " (" << ipt[res[1]] << ") sum=" << res[2] << endl;
    cout << "findMaximumSubarayR: " << exeTime << endl;
}