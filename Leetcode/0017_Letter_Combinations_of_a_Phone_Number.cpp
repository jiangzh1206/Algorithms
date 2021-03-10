#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// 22. genarate parentheses

class Solution {
public:
    map<char, string> num_map {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"},
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>{};
        }
        vector<string> res;  
        //DFS("", 0, digits, res);
        BFS(digits, res);

        return res;
    }

    void DFS(string str, int pos, const string& digits, vector<string>& res) {
        if (pos + 1 > digits.size()){
            // 超出字串长度，结束递归
            res.push_back(str);
            return;
        }
        auto chs = num_map[digits[pos]];
        for (auto ch : chs) {
            DFS((str + ch), pos+1, digits, res);
        }
    }

    // 广度优先
    void BFS(string digits, vector<string>& res) {
        queue<string> q;
        q.push("");

        for (int i = 0; i < digits.size(); ++i) {
            auto str = num_map[digits[i]];
            int len = q.size();
            // 遍历每一层缓存加上下一层ch
            for (int j = 0; j < len; ++j) {
                auto cache = q.front();
                q.pop();
                for (auto ch : str) {
                    q.push(cache + ch);
                }
            }
        }

        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
    }
};


int main() {
    Solution sln;
    auto res = sln.letterCombinations("23");
    for (auto& str : res) {
        cout << str << ',';
    }
    cout << endl;
    return 0;
}