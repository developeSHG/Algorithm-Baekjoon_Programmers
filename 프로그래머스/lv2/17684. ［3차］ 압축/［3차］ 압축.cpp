#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define ALPHABET 64

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;

    for (size_t i = 0; i < msg.size();)
    {
        int j = 2;
        while (m.count(msg.substr(i, j)) && i + j <= msg.size()) ++j;

        if (j == 2) answer.emplace_back(msg[i] - ALPHABET);
        else answer.emplace_back(m[msg.substr(i, j - 1)]);
        
        m.insert(make_pair(msg.substr(i, j), 27 + m.size()));
        i += j - 1;
    }

    return answer;
}