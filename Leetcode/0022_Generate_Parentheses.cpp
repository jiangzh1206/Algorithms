#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        dfs(n, n, "", ret);
        return ret;
    }

    void dfs(int left, int right, string cur_str, vector<string>& ret) {
        // 不是左就是右，剪枝
        if (left == 0 && right == 0) {
            ret.push_back(cur_str);
            return;
        }
        if (left > 0) {
            // 加左括号
            dfs(left-1, right, cur_str+"(", ret);
        }
        if (right > left) {
            // 只右剩余大于左才加右括号
            dfs(left, right-1, cur_str+")", ret);
        }
    }
};