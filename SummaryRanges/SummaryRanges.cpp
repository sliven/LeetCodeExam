#include <iostream>
#include <vector>

using namespace std;

/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> vecResult;
        if (nums.size() == 0)
        {
            return vecResult;
        }
        else if (nums.size() == 1)
        {
            vecResult.push_back(to_string(nums[0]));
            return vecResult;
        }

        for (int i = 0; i < nums.size();)
        {
            int beginVal = nums[i];
            int tmp = beginVal;
            int j = 0;
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == tmp + 1)
                {
                    tmp = nums[j];
                    continue;
                }
                else
                {
                    break;
                }
            }

            if (j == i + 1)
            {
                vecResult.push_back(to_string(nums[i]));
            }
            else
            {
                string rangeStr = to_string(beginVal) + "->" + to_string(nums[j - 1]);
                vecResult.push_back(rangeStr);
            }

            i = j;
        }

        return vecResult;
    }
};


int main()
{
    vector<int> nums = {0,1,2,5,6,8,10};
    Solution s;
    vector<string> results = s.summaryRanges(nums);
    for (string& s : results)
    {
        cout << s << "  " << endl;
    }
    return 0;
}