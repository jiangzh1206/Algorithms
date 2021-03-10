#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
// coins = [1,2,5], amount = 11, 
 选出硬币为: a1 + a2 + ... + ak;
 f(11) = f(k-1) + 1;
 第k个硬币可能为1,2,5
    ak==1: f(11) = f(11-1) + 1;
    ak==2: f(11) = f(11-2) + 1;
    ak==5: f(11) = f(11-5) + 1;

    初始条件: f[0] = 0;
    转移方程: f[x] = min(f[x-1]+1, f[x-2]+1, f[x-5]+1);

1.确定状态  2.转移方程  3.初始条件和边界  4.计算顺序(利用之前计算结果)   
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        auto f = new int[amount+1];
        f[0] = 0;

        for (int x = 1; x <= amount; ++x) {
            f[x] = INT32_MAX;
            for (auto c : coins) {
                if (x >= c && f[x-c] != INT32_MAX) 
                    f[x] = min(f[x], f[x-c] + 1);
            }
        }
        if (f[amount] == INT32_MAX) {
            f[amount] = -1;
        }

        int res = f[amount];
        delete[] f;
        return res;
    }
};


int main() {
    Solution sln;
    vector<int> input{1,2,5};
    cout << sln.coinChange(input, 11);

    cout << endl;

    return 0;
}