#include <vector>
#include <iostream>
#include <stack>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    //14.10.15
    vector<int> answer;
    for_each(arr.begin(), arr.end(), [&](const auto& lhs) {
        if (answer.empty() || answer.back() != lhs)
            answer.push_back(lhs);
    });
    return answer;
}