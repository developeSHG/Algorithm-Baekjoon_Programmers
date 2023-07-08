#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;
    list<pair<string, string>> li;

    stringstream ss;
    for (const auto& data : record) {
        ss.str(data);
        string command, userID, nickName; ss >> command >> userID >> nickName;
        ss.clear();

        if (command != "Change") li.emplace_back(make_pair(command, userID));
        if (command != "Leave") m[userID] = nickName;
    }

    for (const auto& pair : li) {
        const auto& command = pair.first, userID = pair.second;

        if (command == "Enter") answer.emplace_back(m[userID] + "님이 들어왔습니다.");
        else answer.emplace_back(m[userID] + "님이 나갔습니다.");
    }

    return answer;
}