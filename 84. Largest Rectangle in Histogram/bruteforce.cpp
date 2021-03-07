#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<bool> check;
    int search(vector<int>& heights, int idx) {
        int cnt = 0;
        for (int i = idx + 1; i < heights.size(); i++) {
            if (heights[idx] == heights[i]) {
                check[i] = true;
            }
            if (heights[idx] <= heights[i]) {
                cnt++;
            } else {
                break;
            }
        }
        for (int i = idx - 1; i >= 0; i--) {
            if (heights[idx] == heights[i]) {
                check[i] = true;
            }
            if (heights[idx] <= heights[i]) {
                cnt++;
            } else {
                break;
            }
        }
        return cnt + 1;
    }

   public:
    int largestRectangleArea(vector<int>& heights) {
        int answer = 0;
        check.resize(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            if (!check[i]) {
                answer = max(answer, search(heights, i) * heights[i]);
                printf("answer = %d \n" , answer);
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<int> heights = {1,1,1,1,1};
    printf("%d\n", s.largestRectangleArea(heights));
    return 0;
}