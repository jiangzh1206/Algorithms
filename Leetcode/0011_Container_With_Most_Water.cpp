#include <iostream>
#include <vector>
using namespace std;

// 双指针
class Solution {
public:
    int maxArea(const vector<int>& height) {
        int area = 0;
        int l = 0; 
        int r = height.size() - 1;
        while (l < r)
        {
            int t = min(height[l], height[r]) * (r-l);
            area = max(area, t);
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        
        return area;
    }
};


int main() {
    Solution sln;
    cout << sln.maxArea({1,8,6,2,5,4,8,3,7}) << '\n';
    cout << sln.maxArea({1,1}) << '\n';
    cout << sln.maxArea({4,3,2,1,4}) << '\n';
    cout << sln.maxArea({1,2,1}) << '\n';

    return 0;
}