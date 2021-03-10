#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
1.如果 p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]；
2.如果 p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1]；
3.如果 p.charAt(j) == '*'：
  1).如果 p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2] //in this case, a* only counts as empty
  2).如果 p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.'：
        dp[i][j] = dp[i-1][j] //in this case, a* counts as multiple a
        or dp[i][j] = dp[i][j-1] // in this case, a* counts as single a
        or dp[i][j] = dp[i][j-2] // in this case, a* counts as empty
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();
        if(p.empty()) return s.empty();
        
        vector<vector<bool>> dp(ns+1, vector<bool>(np+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= np; i++){
            if(i-2 >= 0 && p[i-1] == '*' && p[i-2]){
                dp[0][i] = dp[0][i-2];
            }
        }
        
        for(int i = 1; i <= ns; i++){
            for(int j = 1; j <= np; j++){
                if(p[j-1] == s[i-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                if(p[j-1] == '*'){
                    bool zero, one;
                    if(j-2 >= 0){
                        zero = dp[i][j-2];
                        one = (p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j];
                        dp[i][j] = zero || one;
                    }
                }
            }
        }
        return dp[ns][np];
    }
};