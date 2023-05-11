#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer;
    
	for (int i = 0; i < s.length(); ++i)
	{
		if (i == 0 || isspace(s[i - 1]) && !isdigit(s[i]))
			answer += toupper(s[i]);
		else
			answer += tolower(s[i]);
	}

	return answer;
}