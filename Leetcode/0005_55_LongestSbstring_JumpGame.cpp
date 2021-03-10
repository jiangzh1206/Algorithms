#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int expand_center(string s, int left, int right) {

        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R])
        {
            // 以中心向左右扩散
            L--;
            R++;
        }

        // R - L + 1 - 2 不包括RL的长度
        return R - L - 1;
    }
    // 中心扩散法
    string Solution::longestPalindrome1(string s)
    {
        if (s.length() < 1) {
            return string();
        }

        int start = 0, end = 0;
        for (int i = 0; i < s.length(); ++i) {
            int len1 = expand_center(s, i, i);      // 一个元素为中心‘a’
            int len2 = expand_center(s, i, i + 1);  // 两个元素为中心”aa“
            int len = max(len1, len2);

            if (len > end - start)
            {
                start = i - (len - 1) / 2;  // 举例求证
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

    // 5. Longest Palindromic Substring
    /* 
    f(i, j) = f(i+1,j-1) And si==sj
    s(i...j)子串长度
    */
    string longestPalindrome(string s)
    {
        int len = s.length();
        if (len < 2) return s;

        vector<vector<int>>dp(len, vector<int>(len, 0));
        // 初始条件(对角线）
        for (int i = 0; i < len; i++)
        {
            // 单个字符一定是回文
            dp[i][i] = 1;
        }

        int begin = 0;
        int max = 0;

        // 遍历 s[i...j]
        for (int j = 1; j < len; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;    
                } else {
                    // s[i+1...j-1]为单字符或空
                    if ((j-1)-(i+1)+1 < 2) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                // 记录开始位置和长度
                if (dp[i][j] && j-i+1 > max){
                    max = j-i+1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, max);
    }

    // 55. Jump Game
    /*
    F[j] = (0<=i<j) => (F[i] && i+ai >= j)
    枚举i->j, F[i]可达并且从i可以跳到j
    F[0]=true
    */
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool* F = new bool[n];

        F[0] = true;
        for (int j = 1; j < n; ++j) {
            F[j] = false;
            for (int i = 0; i < j; ++i) {
                if (F[i] && i + nums[i] >= j) {
                    F[j] = true;
                    break;
                }
            }
        }

        bool res = F[n - 1];
        delete [] F;
        return res;
    }
};