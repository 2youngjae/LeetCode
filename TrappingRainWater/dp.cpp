/*
시간복잡도 O(n)

어떤 특정한 지점 i에서 빗물이 얼마나 채워지는지 알수 있는 방법은 min(i의 왼쪽최대값, i의 오른쪽 최대값) - height[i] 이다.
위 조건을 이용하여 answer를 계산할 수 있다.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        int answer = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
           
        left_max[0] = height[0];
        for (int i = 1; i < size; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        for (int i = 0; i < size; i++) {
            answer += (min(left_max[i], right_max[i]) - height[i]);
        }
        return answer;
    }
};

int main() {
    vector<int> height = { };
    printf("%d\n", Solution().trap(height));
}
