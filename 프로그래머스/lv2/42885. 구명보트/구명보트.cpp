#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int leftPointer = 0, rightPointer = people.size() - 1;

    sort(people.begin(), people.end());
    
    while (leftPointer <= rightPointer)
    {
        if (people[leftPointer] + people[rightPointer] <= limit)
            ++leftPointer;

        --rightPointer;
        ++answer;
    }
    return answer;
}
