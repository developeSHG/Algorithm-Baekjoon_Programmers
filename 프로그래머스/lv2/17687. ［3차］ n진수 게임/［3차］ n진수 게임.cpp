#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_bit(int num, const int& bit) {
    string ans = "";
    string hex[] = { "A", "B", "C", "D", "E", "F" };

    while (num > 0) {
        const auto& val = num % bit;
        ans += (val >= 10) ? hex[val - 10] : to_string(val);
        num /= bit;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string list = "0";
    
    int j = 1;
    while (list.length() < t * m)
        list += (to_bit(j++, n));

    j = 0;
    while (answer.length() < t)
        answer += list[(p - 1) + (m * j++)];

    return answer;
}