#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const bool IsPrime(int n)
{
    for (size_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true && n > 1;
}

void expression(const string& numbers, unordered_set<int>& set, vector<int> idxList, string num)
{
    set.insert(stoi(num));

    for (int i = 0; i < numbers.length(); ++i)
    {
        if (find(idxList.begin(), idxList.end(), i) != idxList.end()) continue;

        idxList.push_back(i); num += numbers[i];
        expression(numbers, set, idxList, num);
        idxList.pop_back(); num.pop_back();
    }
}

int solution(string numbers) {
    //24.10.21
    int answer = 0;
    unordered_set<int> set;
    
    for (int i = 0; i < numbers.length(); ++i)
    {
        vector<int> idxList{i};
        string num;
        num += numbers[i];
        expression(numbers, set, idxList, num);
    }

    for (const auto& n : set)
        answer += IsPrime(n) ? 1 : 0;

    return answer;
}