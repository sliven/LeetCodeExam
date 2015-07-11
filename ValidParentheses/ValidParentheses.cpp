//
//  main.cpp
//  ValidParentheses
//
//  Created by jsl on 15/4/11.
//  Copyright (c) 2015年 jsl. All rights reserved.
//

#include <iostream>

#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        
        stack<char> checkBuf;
        for (int i = 0; i < s.length(); ++i) {
            if (checkBuf.size() == 0) {
                checkBuf.push(s[i]);
                continue;
            }
            
            char checkChar = s[i];
            if (checkChar == ')') {
                if (checkBuf.top() != '(') {
                    return false;
                } else {
                    checkBuf.pop();
                }
            } else if (checkChar == '}') {
                if (checkBuf.top() != '{') {
                    return false;
                } else {
                    checkBuf.pop();
                }
            } else if (checkChar == ']') {
                if (checkBuf.top() != '[') {
                    return false;
                } else {
                    checkBuf.pop();
                }
            } else {
                checkBuf.push(checkChar);
            }
        }
        return checkBuf.size() == 0;
    }
};



int main(int argc, const char * argv[]) {
    
    Solution s;
    
    cout << "([])" << (s.isValid("([])") ? " is valid" : " is not valid" )<< endl;
    
    cout << "([])}" << (s.isValid("([])}") ? " is valid" : " is not valid" )<< endl;
    
    cout << "{([])" << (s.isValid("{([])") ? " is valid" : " is not valid" )<< endl;
    
    cout << "([])[]" << (s.isValid("([])[]") ? " is valid" : " is not valid" )<< endl;
    
    return 0;
}
