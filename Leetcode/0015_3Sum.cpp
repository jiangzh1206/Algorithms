#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1.排序
        sort(nums.begin(), nums.end());
    
        vector<vector<int>> result;

        // -4,  -3,    0,    1,   2,   2
        //  i    l                     r

        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0) {
                return result;
            }

            if (i > 0 && nums[i] == nums[i-1]){
                // i 与 i-1 相等跳过
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum3 = nums[i] + nums[l] + nums[r];
                if (sum3 == 0){
                    result.push_back({nums[i], nums[l], nums[r]});
                    // l r下个元素是否相等
                    while(l < r && nums[l]==nums[l+1]) {
                        l++;
                    }
                    while(l < r && nums[r]==nums[r-1]) {
                        r--;
                    }
                    
                    l++;
                    r--;
                } else if (sum3 < 0) {
                    l++;
                } else if (sum3 > 0) {
                    r--;
                }
            }
        }
    
        return result;
    }
};


int main(){
    Solution sln;
    vector<int> input{-2, 0, 1, 1, 2};
    auto res = sln.threeSum(input);
    for (auto v : res){
        for (auto vv : v){
            std::cout << vv << " ";
        }
        std::cout << '\n';
    }

    return 0;
}