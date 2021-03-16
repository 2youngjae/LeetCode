/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-16
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 4 ms, faster than 76.64% of C++ online submissions for Generate Parentheses.
 * Memory Usage: 15.8 MB, less than 17.50% of C++ online submissions for Generate Parentheses.
 * 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<string> answer;
    void dfs(int open_cnt, int close_cnt, int n, string s) {
        if (open_cnt < close_cnt) {
            return;
        }
        if (close_cnt == n) {
            answer.push_back(s);
            return;
        }

        if (open_cnt == n) {
            int m = n - close_cnt;
            for(int i = 0 ; i < m ; i++){
                s += ')';
            }
            dfs(open_cnt, close_cnt + m, n, s);
            return;
        }
        dfs(open_cnt + 1, close_cnt, n, s + '(');
        dfs(open_cnt, close_cnt + 1, n, s + ')');
    }

   public:
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, "");
        return answer;
    }
};

int main() {
    Solution s;
    s.generateParenthesis(4);
    return 0;
}