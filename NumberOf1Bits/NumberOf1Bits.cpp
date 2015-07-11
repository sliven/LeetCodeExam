//
//  main.cpp
//  NumberOf1Bits
//
//  Created by jsl on 15/4/11.
//  Copyright (c) 2015年 jsl. All rights reserved.
//

/*
 
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 
 For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3. 
 */

#include <iostream>

using namespace std;

class Solution {
public:
    
    //15 ms
    int hammingWeight(uint32_t n) {
        uint32_t mask = 0x1;
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & mask) {
                ++count;
            }
            mask <<= 1;
        }
        
        return count;
    }
    
    //10 ms
    int hammingWeight2(uint32_t n) {
        int count=0;
        for(int i = 0;i < 32; ++i) {
            if((n >> i & 1) == 1)
                ++count;
        }
        return count;
    }
};


int main(int argc, const char * argv[]) {

    Solution s;
    cout << "test 1 : " << s.hammingWeight(1) << endl;
    cout << "test 5 : " << s.hammingWeight(5) << endl;
    cout << "test 33 : " << s.hammingWeight(33) << endl;
    cout << "test 64 : " << s.hammingWeight(64) << endl;
    return 0;
}
