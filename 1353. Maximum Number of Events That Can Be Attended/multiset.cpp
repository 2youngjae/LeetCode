/**
 * @file multiset.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-02
 * 
 * Runtime: 356 ms, faster than 45.55% of C++ online submissions for Maximum Number of Events That Can Be Attended.
 * Memory Usage: 86.5 MB, less than 31.04% of C++ online submissions for Maximum Number of Events That Can Be Attended.
 * 
 * Time complexity : O(NlogN)
 * Space complexity: O(N)
 * 
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        int max_num = 0;
        for (int i = 0; i < events.size(); i++) {
            max_num = max(max_num, events[i][1]);
        }

        multiset<int> ms;
        int idx = 0;
        int result = 0;
        for (int i = 1; i <= max_num; i++) {
            while (idx < events.size() && events[idx][0] == i) {
                ms.insert(events[idx][1]);
                idx++;
            }

            while (!ms.empty() && *ms.begin() < i) {
                ms.erase(ms.begin());
            }

            if (!ms.empty()) {
                result++;
                ms.erase(ms.begin());
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> events = {{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
    printf("result = %d\n", s.maxEvents(events));
}