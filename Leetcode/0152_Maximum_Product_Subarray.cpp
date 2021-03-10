#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) 
            return 0;

        int ret_max = nums[0];
        vector<int> vec_max(nums.size());
        // 当i<0 时 与负值相乘会是最大值
        vector<int> vec_min(nums.size());


        for (int i = 1; i < nums.size(); ++i) {
            vec_max[i] = max({nums[i], vec_max[i-1]*nums[i], vec_min[i-1]*nums[i]});
            vec_min[i] = min({nums[i], vec_max[i-1]*nums[i], vec_min[i-1]*nums[i]});
        
            ret_max = max(ret_max, vec_max[i]);
        }

        return ret_max;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    vector<int> input{2,3,-2,4};
    cout << sln.maxProduct(input) << '\n';

    return 0;
}