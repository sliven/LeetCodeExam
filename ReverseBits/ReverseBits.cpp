//
//  main.cpp
//  ReverseBits
//
//  Created by jsl on 15/4/11.
//  Copyright (c) 2015年 jsl. All rights reserved.
//

/*
 
 Reverse bits of a given 32 bits unsigned integer.
 
 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 */

#include <iostream>

using namespace std;


class Solution {
public:
    // 17 ms after leet test
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            if (n >> i & 1) {
                result |= ( 1 << (32 - i - 1));
            }
        }
        return result;
    }
    
    //11ms after leet test
    uint32_t reverseBits2(uint32_t n) {
        uint32_t result = 0;
        if (n & 1) {
            result |= ( 1 << (32 - 1));
        }
        
        for (int i = 1; i < 32; ++i) {
            if ((n >>= 1) & 1) {
                result |= ( 1 << (32 - i - 1));
            }
        }
        return result;
    }
    
    //9ms after leet test
    uint32_t reverseBits3(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; ++i, n >>= 1) {
            result <<= 1;
            if (n & 1) {
                result |= 1;
            }
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    cout << "reverse of 43261596 is: " << s.reverseBits3(43261596) << endl;
    return 0;
}
