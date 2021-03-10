#include <string>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> sk;
        sk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                sk.push(i);
            } else {
                sk.pop();
                if (sk.empty()) {
                    sk.push(i);
                } else {
                    maxans = max(maxans, i - sk.top());
                }
            }
        }
        return maxans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    int ret = sln.longestValidParentheses(")()())");
    return 0;
}
