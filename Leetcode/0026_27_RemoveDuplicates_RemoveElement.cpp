#include <vector>
using namespace std;


class Solution {
public:
    // 双指针
    // 26. Remove Duplicates from Sorted Array
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int j = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j]){
                j++;
            }
            nums[j] = nums[i];
        }

        return j+1;
    }

    // 27. Remove Element
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
