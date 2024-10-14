#include <string>
#include <vector>

using namespace std;

vector<int> vec(100001, 0);

int fibonacci(int n)
{
    if (vec[n] != 0) return vec[n];
    if (n <= 1) return n;

    vec[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1234567;
    return vec[n];
};

int solution(int n) {
    // 24.10.15
    return fibonacci(n);
}