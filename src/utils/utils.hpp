#pragma once

#include <vector>
#include "chrono"

using namespace std;

void printVec(const vector<int> &A);
vector<int> generateRandVec(int size, int delta, bool negative = true);
bool verifySortedVec(vector<int> v);

chrono::duration<double, milli> sortingFuncExecTime(void (*func)(vector<int> &), vector<int> &v);
