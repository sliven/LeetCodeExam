/*
 *
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Solve it without division and in O(n).
 * For example, given [1,2,3,4], return [24,12,8,6].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /*
     * Solution input : [2, 3, 4, 5]
     * After first loop: [5*4*3, 5*4, 5, 1]
     * After second loop:[5*4*3, 5*4*2, 5*2*3, 2*3*4]
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        if (nums.size() == 2) {
            vector<int> result(nums.size());
            result[0] = nums[1];
            result[1] = nums[0];
            return result;
        }

        vector<int> right(nums.size(), 1);
        for (int i = nums.size()-2; i >= 0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }

        int left = 1;
        for (int i = 0; i < nums.size(); i++) {
            right[i] = right[i]*left;
            left = left * nums[i];
        }
        return right;
    }
};


int main(int argc, char* argv[]) {
    return 0;
}
