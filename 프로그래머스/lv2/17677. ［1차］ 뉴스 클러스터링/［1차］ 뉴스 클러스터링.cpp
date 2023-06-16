#include <string>
#include <vector>
#include <map>
 
#define MULTIPLE 65536
using namespace std;
 
 
int Min(int A, int B) { return A < B ? A : B; }
int Max(int A, int B) { return A > B ? A : B; }
 
int Check_State(char C)
{
    if ('A' <= C && C <= 'Z') return 2;
    if ('a' <= C && C <= 'z') return 1;
    return 0;
}
 
char Invert(char C)
{
    C = C - 'A';
    C = C + 'a';
    return C;
}
 
int solution(string str1, string str2) 
{
    vector<string> Total_Str;
    map<string, int> A, B;
 
    /* str1에 대해서 "올바른 문자열" 추출하기. */
    for (int i = 0; i < str1.length() - 1; i++)
    {
        char First = str1[i];
        char Second = str1[i + 1];
        int First_State = Check_State(First);
        int Second_State = Check_State(Second);
        
        if (First_State == 0 || Second_State == 0) continue;
        if (First_State == 2) First = Invert(First);
        if (Second_State == 2) Second = Invert(Second);
        
        string Temp = "";
        Temp = Temp + First;
        Temp = Temp + Second;
        /* 전체 문자열을 관리할 때는, 중복되지 않게 삽입해야한다. */
        /* 중복을 확인하기 위해서는 map에 이미 값이 있는지 확인하면 된다. */
        if (A[Temp] == 0) Total_Str.push_back(Temp);
        A[Temp]++;
    }
 
    /* str2에 대해서 "올바른 문자열" 추출하기. */
    for (int i = 0; i < str2.length() - 1; i++)
    {
        char First = str2[i];
        char Second = str2[i + 1];
        int First_State = Check_State(First);
        int Second_State = Check_State(Second);
 
        if (First_State == 0 || Second_State == 0) continue;
        if (First_State == 2) First = Invert(First);
        if (Second_State == 2) Second = Invert(Second);
 
        string Temp = "";
        Temp = Temp + First;
        Temp = Temp + Second;
        /* str2에서 발생한 문자열도, 전체 문자열을 관리하는 vector에 값을 삽입해야함. */
        /* 물론, 중복이 되지 않게 하기 위해서, map을 이용해서 판단. */
        if (A[Temp] == 0 && B[Temp] == 0) Total_Str.push_back(Temp);
        B[Temp]++;
    }
    
    if (Total_Str.size() == 0) return MULTIPLE;
 
    int Intersection, Union;
    Intersection = Union = 0;
 
    for(int i = 0; i < Total_Str.size(); i++)
    { 
        /* 교집합은, 두 집합 중 더 적은 갯수. */
        /* 합집합은, 두 집합 중 더 큰 갯수. */
        string Str = Total_Str[i];
        Intersection = Intersection + Min(A[Str], B[Str]);
        Union = Union + Max(A[Str], B[Str]);
    }
    
    double answer = (double)Intersection / Union;
    answer = answer * MULTIPLE;
    return (int)answer;
}
