#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                // 去重
                continue;
            }

            for (int m = i + 1; m < nums.size() - 2; ++m) {
                if (m > i + 1 && nums[m] == nums[m-1]) {
                    // 去重
                    continue;
                }

                int l = m + 1;
                int r = nums.size() - 1;

                while (l < r) {
                    if (nums[m] + nums[l] + nums[r] < target - nums[i]) {
                        l++;
                    } else if (nums[m] + nums[l] + nums[r] > target - nums[i]) {
                        r--;
                    } else {
                        res.push_back({nums[i],nums[m],nums[l],nums[r]});
                        while(l < r && nums[l]==nums[l+1]) {
                            l++;
                        }
                        while(l < r && nums[r]==nums[r-1]) {
                            r--;
                        }

                        l++;
                        r--;
                    } 
                }
            }
        }
        return res;
    }
};


int main() {
    Solution sln;
    vector<int> input{0,0,0,0};
    auto res = sln.fourSum(input, 0);
    for (auto v : res) {
        for (auto vv : v) {
            cout << vv << ',';
        }
        cout << '\n';
    }

    return 0;
}