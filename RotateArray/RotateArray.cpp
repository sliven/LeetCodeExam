//
//  main.cpp
//  RotateArray
//
//  Created by jsl on 15/4/14.
//  Copyright (c) 2015年 jsl. All rights reserved.
//

/*
 Rotate an array of n elements to the right by k steps.
 
 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 
 */

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    //28ms after leet test cases
    void rotate(int nums[], int n, int k) {
        k = k % n;
        
        int *tmpNums = new int[k];
        for (int i = 1; i <= k; ++i) {
            tmpNums[k - i] = nums[n - i];
        }
        for (int i = n - k - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = tmpNums[i];
        }
        delete[] tmpNums;
    }
    
    //25ms after leet test cases
    void rotate2(int nums[], int n, int k) {
        //1, 2, 3, 4, 5
        reverse(nums,nums+n);  // 5, 4, 3, 2, 1
        reverse(nums,nums+k%n);// 4, 5, 3, 2, 1
        reverse(nums+k%n,nums+n);//4, 5, 1, 2, 3
    }
};


int main(int argc, const char * argv[]) {
    
    int nums[] = {1, 2, 3, 4, 5};
    Solution s;
    s.rotate2(nums, 5, 2);
    
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i) {
        cout << nums[i] << ",";
    }
    
    cout << endl;
    
    return 0;
}
