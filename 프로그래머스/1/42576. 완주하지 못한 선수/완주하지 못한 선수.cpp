#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for (const auto& str : participant)
        ++m[str];
    for (const auto& str : completion)
        --m[str];
    for (const auto& pair : m)
    {
        if (pair.second > 0) return pair.first;
    }
    
    return answer;
}