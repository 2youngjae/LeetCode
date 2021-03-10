/**
 * @file stack.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-10
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 60 ms, faster than 81.38% of C++ online submissions for Daily Temperatures.
 * Memory Usage: 41.5 MB, less than 52.92% of C++ online submissions for Daily Temperatures. 
 * 
 * Time complexity : O(n)
 * Space complexity : O(n)
 * 
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> answer(T.size(), 0);
        stack<int> s;
        for (int i = 0; i < T.size(); i++) {
            while(!s.empty() && T[s.top()] < T[i]){
                answer[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    s.dailyTemperatures(T);
    return 0;
}