#include <iostream>
#include <vector>
#include <string>
#include "utils/utils.hpp"

using namespace std;

int concSmaller(int n1, int n2)
{
    auto s1 = to_string(n1);
    auto s2 = to_string(n2);

    return (s1 + s2 < s2 + s1) ? n1 : n2;
}

void merge(vector<int> &A, int p, int q, int r)
{
    int nl = q - p;
    int nr = r - q;

    vector<int> L(nl);
    vector<int> R(nr);

    for (int i = 0; i < nl; i++)
    {
        L[i] = A[p + i];
    }

    for (int i = 0; i < nr; i++)
    {
        R[i] = A[q + i];
    }

    int j = 0;
    int k = 0;

    for (int i = p; i < r; i++)
    {
        if (j == nl)
        {
            A[i] = R[k];
            k++;
        }
        else if (k == nr || concSmaller(L[j], R[k]) == L[j])
        {
            A[i] = L[j];
            j++;
        }
        else
        {
            A[i] = R[k];
            k++;
        }
    }
}


void mergeSortHelper(vector<int> &A, int p, int r)
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;

        mergeSortHelper(A, p, q);
        mergeSortHelper(A, q, r);
        merge(A, p, q, r);
    }
}

void mergeSort(vector<int> &ipt)
{
    mergeSortHelper(ipt, 0, ipt.size());
}

string largeNumConc(const vector<int> &v)
{
    vector<int> u = v;
    mergeSort(u);

    string out = "";
    for (int i = u.size() - 1; i >= 0; --i)
    {
        out += to_string(u[i]);
    }

    return out;
}

int main()
{
    vector<int> ipt = generateRandomVector(20000, 100000, false);
    printVector(ipt);
    cout << largeNumConc(ipt) << endl;
}
