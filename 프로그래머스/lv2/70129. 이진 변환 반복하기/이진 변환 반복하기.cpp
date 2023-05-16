#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    int count{0}, erase{0};

    while (s != "1")
    {
        while (find(s.begin(), s.end(), '0') != s.end())
        {
            s.erase(find(s.begin(), s.end(), '0'));
            ++erase;
        }

        s = bitset<100>(s.length()).to_string();
        s = s.substr(s.find('1'));
        ++count;
    }

    return vector<int>{ count, erase };
}