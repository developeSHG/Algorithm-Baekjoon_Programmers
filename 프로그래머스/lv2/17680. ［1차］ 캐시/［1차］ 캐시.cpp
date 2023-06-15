#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

#define CACHE_HIT 1
#define CACHE_MISS 5;

class LRU
{
public:
    explicit LRU(int n)
    {
        LRUMaxSize = n;
        LRUTime = 0;
    }

    void refer(string n)
    {
        // 캐시 내에 없을 경우
        if (LRUMap.find(n) == LRUMap.end())
        {
            // 캐시가 꽉 찼을 경우
            if (LRUList.size() >= LRUMaxSize)
            {
                // 리스트에서 가장 오래 사용되지 않은 요소 pop
                LRUMap.erase(LRUList.front());
                // 참조도 함께 삭제
                LRUList.pop_front();
            }

            LRUTime += CACHE_MISS;
        }
        // 캐시 내에 있을 경우 해당 요소 삭제
        else
        {
            LRUList.erase(LRUMap[n]);
            LRUTime += CACHE_HIT;
        }

        // 새로운 요소 x를 push, 참조도 updqte
        LRUList.push_back(n);
        LRUMap[n] = --LRUList.end();
    }

    int GetTime() noexcept { return LRUTime; }

private:
    list<string> LRUList; // 데이터를 저장할 list
    unordered_map<string, list<string>::iterator> LRUMap; // 참조를 저장할 map
    int LRUMaxSize; // 최대 용량
    int LRUTime; // 실행시간
};

int solution(int cacheSize, vector<string> cities) {
    if (!cacheSize) return cities.size() * CACHE_MISS;
    
    LRU lru(cacheSize);

    for_each(cities.begin(), cities.end(), [&](auto& str) 
    { 
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        lru.refer(str); 
    });

    return lru.GetTime();
}