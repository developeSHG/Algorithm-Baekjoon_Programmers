#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void strtok(vector<long long>& v_num, vector<char>& v_op, const char* s) 
{
    string temp = "";

    while (*s != '\0') 
    {
        if (*s == '*' || *s == '+' || *s == '-') 
        {
            v_op.emplace_back(*s);
            v_num.emplace_back(stoll(temp));
            temp = "";
        }
        else temp += *s;
        ++s;
    }

    v_num.emplace_back(stoll(temp));
}

long long calc(char op, long long num1, long long num2) 
{
    switch (op) 
    {
    case '*':
        return num1 * num2;

    case '+':
        return num1 + num2;

    case '-':
        return num1 - num2;
    }
}

long long solution(string expression) 
{
    long long answer = 0;
    vector<long long> s_num;
    vector<char> s_op;
    strtok(s_num, s_op, expression.c_str());

    string op = "+-*";
    sort(op.begin(), op.end()); 

    do 
    {
        vector<long long> temp_num = s_num;
        vector<char> temp_op = s_op;

        for (size_t i = 0; i < op.size(); i++) 
        {
            char C = op[i];

            for (size_t j = 0; j < temp_op.size(); j++) 
            {
                if (temp_op[j] == C)
                {
                    long long sum = calc(C, temp_num[j], temp_num[j + 1]);
                    temp_num[j] = sum;

                    // J번 Index는 결과값으로 바꿔버리고, J + 1번 Index는 삭제를 시켜버리는 것
                    temp_num.erase(temp_num.begin() + j + 1);
                    temp_op.erase(temp_op.begin() + j);
                    j--; // 모든 데이터의 Index값이 하나씩 땡겨지기 때문에 포인터를 한 칸 감소시켜 줘야 한다는 과정
                }
            }
        }
        answer = max(answer, abs(temp_num[0]));
    } while (next_permutation(op.begin(), op.end()));

    return answer;
}