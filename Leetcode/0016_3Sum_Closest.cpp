#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 1.排序
        sort(nums.begin(), nums.end());
    
        // -4,  -3,    0,    1,   2,   2
        //  i    l                     r
        int sum3 = INT_MAX;
        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i-1]){
                // i 与 i-1 相等跳过
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                long temp_sum3 = nums[i] + nums[l] + nums[r];
                if (temp_sum3 == target) {
                    return target;
                } 
                
                // 更新sum3
                if (abs(temp_sum3 - target) < abs(sum3 - target)){
                    sum3 = temp_sum3;
                }

                if (temp_sum3 < target) {
                    // 移动到下个大于当前nums[l]的位置
                    int ln = l + 1;
                    while(ln < r && nums[l]==nums[ln]) {
                        ln++;
                    }
                    l = ln;
                } else {
                    int rn = r - 1;
                    while(l < rn && nums[r]==nums[rn]) {
                        rn--;
                    }
                    r = rn;
                }
            }
        }

        return sum3;
    }
};


int main(){
    Solution sln;
    vector<int> input{1,2,4,8,16,32,64,128};
    auto res = sln.threeSumClosest(input, 82);
    std::cout << res << "\n";


    return 0;
}