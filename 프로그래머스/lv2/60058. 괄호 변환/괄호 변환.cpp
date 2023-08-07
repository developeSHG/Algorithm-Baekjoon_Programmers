#include <string>
#include <vector>

using namespace std;

// 문자열을 분리해서 u를 균형잡힌 문자열로, 나머지를 v로 뱉어주는 함수
void Balance(const string& p, string& outputU, string& outputV)
{
    size_t open{ 0 }, close{ 0 };

    for (size_t i = 0; i < p.length(); ++i)
    {
        p[i] == '(' ? ++open : ++close;
        if (close == open)
        {
            outputU = p.substr(0, i + 1);
            outputV = p.substr(i + 1);
            return;
        }
    }

    outputU = p;
    outputV = "";
}

// 올바른 괄호 문자열인지 체크해주는 함수
bool IsCorrect(const string& p)
{
    size_t open{ 0 }, close{ 0 };

    for (size_t i = 0; i < p.length(); ++i)
    {
        p[i] == '(' ? ++open : ++close;
        if (close > open) return false;
    }
    
    return true;
}

// 첫 번째와 마지막 문자를 제외한 괄호를 거꾸로 뒤집어주는 함수
string Reverse(string p)
{
    string res = "";
    for (size_t i = 1; i < p.length() - 1; ++i)
        res += (p[i] == '(') ? ')' : '(';

    return res;
}

string Convert(string p)
{
    if (p.empty()) return "";

    string u, v;
    Balance(p, u, v);

    if (!IsCorrect(u)) return '(' + Convert(v) + ')' + Reverse(u);
    else return u + Convert(v);
}

string solution(string p) {
    return Convert(p);
}