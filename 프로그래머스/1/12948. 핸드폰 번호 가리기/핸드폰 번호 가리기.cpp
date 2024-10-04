#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    return phone_number.replace(phone_number.begin(), phone_number.end()-4, phone_number.size()-4, '*');
}