#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

void printVector(const vector<int> &A)
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

vector<int> generateRandomVector(int size, int delta, bool negative = true)
{
    random_device rd;
    mt19937 gen(rd());
    int rangeL = negative ? -delta : 0;

    uniform_int_distribution<int> distrib(rangeL, delta);
    vector<int> random_res;
    random_res.reserve(size);

    for (int i = 0; i < size; ++i)
    {
        random_res.push_back(distrib(gen));
    }

    return random_res;
}

int maxValueIndex(vector<int> v, int end_pos)
{
    int index = 0;
    int max_val = v[0];
    for (int i = 1; i <= end_pos; ++i)
    {
        if (v[i] > max_val)
        {
            index = i;
            max_val = v[i];
        }
    }

    return index;
}

bool verifySorted(vector<int> v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i - 1] > v[i])
        {
            return false;
        }
    }
    return true;
}

chrono::duration<double, std::milli> funcExecutionTime(void (*func)(vector<int> &), vector<int> &v)
{
    auto start = chrono::high_resolution_clock::now();
    func(v);
    auto end = chrono::high_resolution_clock::now();
    return end - start;
}