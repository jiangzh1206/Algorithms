#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;

        size_t pos = str.find_first_not_of(' ');
        if (pos == string::npos){
            return 0;
        }

        bool minus = false;
        if (str.at(pos) == '-' || str.at(pos) == '+'){
            if (str.at(pos) == '-'){
                minus = true;
            }
            pos++;
        }

        long result = 0;
        for (size_t i = pos; i < str.size(); ++i){
            auto ch = str.at(i);
            if (ch < '0' || ch > '9')
                break;

            // 注意越界
            if (result > INT_MAX/10) {
                return minus ? INT32_MIN : INT32_MAX;
            }

            result = result*10 +  (ch - '0');
        }

        if (minus && result){
            result = -result;
        }

        if (result < INT32_MIN)
            return INT32_MIN;
        if (result > INT32_MAX)
            return INT32_MAX;

        return result;
    }
};


int main(){
    Solution sln;
    cout << "result:" << sln.myAtoi("042") << "\n";
    cout << sln.myAtoi("    -42") << "\n";
    cout << sln.myAtoi("4234 widht xxx") << "\n";
    cout << sln.myAtoi(" -1010023630o4") << "\n";
    cout << sln.myAtoi("-91283472332") << "\n";

    return 0;
}