#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    vector<int> rooms;

    std::sort(book_time.begin(), book_time.end());
    std::for_each(book_time.begin(), book_time.end(), [&](const auto& v) {
        stringstream ss1(v.front());
        stringstream ss2(v.back());
        string buffer;
        vector<int> temp;

        while (getline(ss1, buffer, ':')) temp.emplace_back(stoi(buffer));
        int s_time = temp[0] * 60 + temp[1];
        
        temp.clear();
        while (getline(ss2, buffer, ':')) temp.emplace_back(stoi(buffer));
        int e_time = temp[0] * 60 + temp[1];
        
        for (size_t i = 0; i < rooms.size(); ++i)
        {
            if (rooms[i] <= s_time)
            {
                rooms[i] = e_time + 10;
                return;
            }
        }

        rooms.emplace_back(e_time + 10);
    });

    return rooms.size();
}