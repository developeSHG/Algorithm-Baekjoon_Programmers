#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <stack>
#include <set>


using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for_each(arr.begin(), arr.end(), [&](const auto& w) {
       answer += w; 
    });
    
    return answer / arr.size();
}