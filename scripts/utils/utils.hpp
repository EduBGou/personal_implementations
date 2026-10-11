#include <vector>
#include "chrono"

using namespace std;

void printVector(const std::vector<int>& A);
vector<int> generateRandomVector(int size, int max_val);
int maxValueIndex(vector<int> v, int end_pos);
bool verifySorted(vector<int> v);

chrono::duration<double, std::milli> funcExecutionTime(void (*func)(vector<int>&), vector<int>& v);
