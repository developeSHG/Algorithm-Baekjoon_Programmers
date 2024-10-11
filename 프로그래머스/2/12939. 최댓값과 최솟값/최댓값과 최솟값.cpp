#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    istringstream ss(s);
    string subs1;
    vector<int> v;

    while (getline(ss, subs1, ' ')) v.push_back(stoi(subs1));

    answer = to_string(*min_element(v.begin(), v.end())) + " " + to_string(*max_element(v.begin(), v.end()));
    return answer;
}