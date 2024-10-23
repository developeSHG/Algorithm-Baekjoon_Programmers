#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
 //24.10.22
 int answer = 0;

 sort(dungeons.begin(), dungeons.end());
 do {
     int nk = k;
     int ch = 0;
     for (auto it = dungeons.begin(); it != dungeons.end(); ++it)
     {
         if (nk >= (*it)[0])
         {
             nk -= (*it)[1];
             ++ch;
         }
     }
     answer = max(answer, ch);
 } while (next_permutation(dungeons.begin(), dungeons.end()));

 return answer;
}