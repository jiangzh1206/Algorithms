#include <string>
#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        auto match = [](char a, char b) ->bool {
            return (a == '(' && b == ')') ||
            (a == '[' && b == ']') ||  
            a == '{' && b == '}';
        };

        stack<char> sk;
        for (auto ch : s) {
            if (sk.empty()) {
                sk.push(ch);
            } else {
                if (match(sk.top(), ch)) {
                    sk.pop();
                } else {
                    sk.push(ch);
                }
            }
        }

        return sk.empty();
    }
};


int main() {
    Solution sln;
    cout << sln.isValid("({})") << endl;
    cout << sln.isValid("({[})") << endl;
    return 0;
}