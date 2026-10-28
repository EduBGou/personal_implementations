#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include "utils.hpp"

void printVec(const vector<int> &A)
{
    cout << "[";
    for (int i = 0; i < A.size(); ++i)
    {
        if (i == A.size() - 1)
        {
            cout << A[i];
            break;
        }
        cout << A[i] << ", ";
    }
    cout << "]" << endl;

    cout << endl;
}

vector<int> generateRandVec(int size, int delta, bool negative)
{
    random_device rd;
    mt19937 gen(rd());
    int rangeL = negative ? -delta : 0;

    uniform_int_distribution<int> distrib(rangeL, delta);
    vector<int> randomRes;
    randomRes.reserve(size);

    for (int i = 0; i < size; ++i)
    {
        randomRes.push_back(distrib(gen));
    }

    return randomRes;
}

bool verifySortedVec(vector<int> v)
{
    for (int i = 1; i < v.size(); ++i)
        if (v[i - 1] > v[i])
            return false;

    return true;
}

chrono::duration<double, milli> sortingFuncExecTime(void (*func)(vector<int> &), vector<int> &v)
{
    auto start = chrono::high_resolution_clock::now();
    func(v);
    auto end = chrono::high_resolution_clock::now();
    return end - start;
}