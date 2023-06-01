#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int loop = 1;

    // 첫번째 원소를 기준으로 최소공배수를 구함.
    // 다른 원소가 (첫번째 원소 * loop)를 나눈 나머지 값이 있으면 공배수가 아닌 것으로 판단.
    while (::any_of(arr.begin(), arr.end(), [=](const auto& el) { return ((loop * arr[0]) % el); }))
        ++loop;

    return loop * arr[0];
}