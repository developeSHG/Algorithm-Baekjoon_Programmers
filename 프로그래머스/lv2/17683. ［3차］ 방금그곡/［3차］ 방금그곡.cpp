#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

enum MusicInfo
{
    S,
    E,
    TITLE,
    MELODY,
};

void revertM(string& m)
{
    // # 먼저 체크하기 위해 역으로 체크
    for (auto rit = m.rbegin(); rit != m.rend(); rit++) {
        if (*rit == '#')
        {
            m.erase(m.rend() - rit - 1, 1); // # 삭제
            *rit = tolower(*(++rit)); // 대문자를 소문자로. G -> g
        }
    }
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    size_t longTime = 0;

    revertM(m);

    ::for_each(musicinfos.begin(), musicinfos.end(), [&](const auto& music) {
        istringstream ss(music);
        string subs; // temp 역할하는 substr 변수
        vector<string> v;

        while (getline(ss, subs, ','))
            v.push_back(subs); // ',' 을 기준으로 인덱스가 증가하며 string 저장

        const auto s = stoi(v[S].substr(0, 2)) * 60 + stoi(v[S].substr(3)); // start 시간
        const auto e = stoi(v[E].substr(0, 2)) * 60 + stoi(v[E].substr(3)); // end 시간
        const size_t time = e - s;

        revertM(v[MELODY]);

        string melody;
        for (size_t i = 0; i < time / v[MELODY].length(); ++i) melody += v[MELODY];
        for (size_t i = 0; i < time % v[MELODY].length(); ++i) melody += v[MELODY][i];

        if (melody.find(m) != string::npos && longTime < time)
            longTime = time, answer = v[TITLE];
    });

    return answer;
}