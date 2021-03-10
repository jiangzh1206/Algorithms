#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> roman_map={
            {"M", 1000},{"CM", 900},{"D", 500},{"CD", 400},{"C", 100},
            {"XC", 90},{"L", 50},{"XL", 40},{"X", 10},{"IX", 9},
            {"V", 5},{"IV", 4},{"I", 1},
        };

        int num = 0;
        for (size_t i = 0 ; i < s.size();){
            auto one = s.substr(i, 1);
            auto two = s.substr(i, 2);
            
            if (roman_map[two]){
                // 两个优先
                num += roman_map[two];
                i += 2;
            } else{
                num += roman_map[one];
                ++i;
            }
        }

        return num;
    }
};


int main(){
    Solution sln;
    // "MCMXCIV" "LVIII"
    cout << "result:" << sln.romanToInt("MCMXCIV") << "\n";
    cout << "result:" << sln.romanToInt("LVIII") << "\n";

    return 0;
}