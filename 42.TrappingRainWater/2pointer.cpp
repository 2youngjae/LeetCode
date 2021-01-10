/*
시간복잡도 O(n)
공간복잡도 O(1)
Runtime: 4 ms, faster than 98.86% of C++ online submissions for Trapping Rain Water.
Memory Usage: 14.5 MB, less than 51.93% of C++ online submissions for Trapping Rain Water.

DP를 이용하는 방법을 조금더 효율화시킨 방법이다.
DP를 이용하여 문제를 풀때 i번째 자리에 TrappingRainWater를 계산하기 위해 모든 i번째자리에서 왼쪽 최대값과 오른쪽 최대값을 알기 위해
vector를 만들고 vector에 각각의 i번째 위치에 대한 left_max, right_max값을 구했었다.
이것을 2pointer와 조건식을 이용하여 vector를 사용하지 않고 아래처럼 구현이 가능하다.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        int left = 0, right = height.size() - 1, left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                //left_max값이 height[right]보다 작다는것이 보장됨.
                if (height[left] < left_max) {
                    answer += left_max - height[left];
                }
                else {
                    left_max = height[left];
                }
                ++left;
            }
            else {
                //right_max값이 height[left]보다 작다는것이 보장됨.
                if (height[right] < right_max) {
                    answer += right_max - height[right];
                }
                else {
                    right_max = height[right];
                }
                --right;
            }
        }
        return answer;
    }
};

int main() {
    vector<int> h = { 4,2,0,3,2,5 };
    printf("%d\n", Solution().trap(h));
    return 0;  
}
