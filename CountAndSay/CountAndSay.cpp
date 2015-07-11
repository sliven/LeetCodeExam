//
//  main.cpp
//  CountAndSay
//
//  Created by jsl on 15/4/11.
//  Copyright (c) 2015年 jsl. All rights reserved.
//


/*
 
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...
 
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 
 Note: The sequence of integers will be represented as a string.
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    // speed: 7 ms
    string countAndSay(int n) {
        if (n < 1) {
            return string();
        }
        
        string retString = "1";
        
        for (int i = 1; i < n; ++i) {
            const string& preCount = retString;
            if (preCount.length() == 1) {
                retString = "11";
                continue;
            }
            
            int dupCount = 1;
            char curCheckNumber = preCount[0];
            string curCount = "";
            for (int j = 1; j < preCount.length(); ++j) {
                if (preCount[j] == curCheckNumber) {
                    ++dupCount;
                    if ( j == preCount.length() -1) {
                        curCount += (to_string(dupCount) + curCheckNumber);
                    }
                } else {
                    curCount += (to_string(dupCount) + curCheckNumber);
                    dupCount = 1;
                    curCheckNumber = preCount[j];
                    if ( j == preCount.length() -1) {
                        curCount += (to_string(dupCount) + curCheckNumber);
                    }
                }
                
            }
            retString = curCount;
        }
        
        return retString;
    }
    
    string countAndSay2(int n) {
        if (0 == n) return "";
        if (1 == n) return "1";
        
        std::string res="1";
        std::string s;
        
        for (int i = 1; i < n; i++){    // run from starting to generate second string
            
            unsigned long len = res.size();
            
            //cheack all digits in the string
            for (int j = 0; j < len; j++){
                
                int count=1; // we have at least 1 occourence of each digit
                
                // get the number of times same digit occurred (be carefull with the end of the string)
                while ((j + 1 < len) && (res[j] == res[j + 1])){
                    count++;
                    j++;        // we need to keep increasing the index inside of the string
                }
                
                // add to new string "count"+"digit itself"
                s += std::to_string(count) + res[j];
            }
            
            // save temporary result
            res = s;
            
            // clean our string-helper
            s.clear();
            
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    for (int i = 1; i <= 6; i++) {
        cout << "count and say " << i << ": " << s.countAndSay(i) << endl;
    }
       return 0;
}
