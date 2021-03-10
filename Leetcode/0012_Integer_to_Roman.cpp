#include <iostream>
#include <string>
using namespace std;

// 贪心
class Solution {
public:
    string intToRoman(int num) {
        int nums[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string romans[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for (int i = 0; i < 13; ){
            if (num >= nums[i]){
                res.append(romans[i]);
                num -= nums[i];
            } else {
                ++i;
            }
        }

        return res;
    }
};


int main(){
    Solution sln;
    cout << "result:" << sln.intToRoman(9) << "\n";
    cout << "result:" << sln.intToRoman(58) << "\n";
    cout << "result:" << sln.intToRoman(1994) << "\n";

    return 0;
}