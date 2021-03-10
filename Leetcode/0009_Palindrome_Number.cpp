#include <iostream>
using namespace std;

// 回文数字: 反转计算是否与原数字相等
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int tmp = x;
        long long res = 0;
        while(x){
            res = res*10 + x%10;
            x /= 10;
        }
        
        return tmp == res;
    }
};


int main(){
    Solution sln;
    cout << "result:" << sln.isPalindrome(121) << "\n";
    cout << "result:" << sln.isPalindrome(-121) << "\n";
    cout << "result:" << sln.isPalindrome(10) << "\n";

    return 0;
}