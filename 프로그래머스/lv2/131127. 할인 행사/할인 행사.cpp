#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> m;
    for (int i = 0; i < number.size(); ++i)
        m[want[i]] = number[i];

    unordered_map<string, int> bet;
    for (int i = 0; i < discount.size(); ++i)
    {
        if (i >= 10)
        {
            if (m.find(discount[i - 10]) != m.end())
                --bet[discount[i - 10]];
        }
            
        if (m.find(discount[i]) != m.end())
            ++bet[discount[i]];

        if (bet == m)
            ++answer;
    }

    return answer;
}