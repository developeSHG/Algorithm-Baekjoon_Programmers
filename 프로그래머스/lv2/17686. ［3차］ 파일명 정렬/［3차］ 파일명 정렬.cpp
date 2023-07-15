#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum EType { HEAD, NUMBER };

vector<string> conversion(const string& file)
{
    vector<string> v{ 2, "" }; //  HEAD, NUMBER 만 사용
    for (size_t i = 0; i < file.length(); ++i)
    {
        if (isdigit(file[i]))
        {
            v[NUMBER] += file[i];
            continue;
        }

        if (!v[NUMBER].empty()) break; // NUMBER 칸에 문자가 있다는 것은 file이 NUMBER 구간을 넘어서서 TAIL에 들어섰다는 것
        else v[HEAD] += tolower(file[i]);
    }

    return v;
}

vector<string> solution(vector<string> files) {
    const auto& condition = [](const auto& f1, const auto& f2) {
        const auto& a = conversion(f1);
        const auto& b = conversion(f2);
        return (a[HEAD] != b[HEAD]) ? a[HEAD] < b[HEAD] : stoi(a[NUMBER]) < stoi(b[NUMBER]);
    };
    stable_sort(files.begin(), files.end(), condition);
    
    return files;
}
