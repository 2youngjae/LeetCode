/*
시간복잡도 O(n)

1.스택에 블록을 넣는다.
2.h[i] 가 h[s.top()] 보다 클때 h[i], h[s.top()], h[s.top()-1] (top 아래 블록) 3개를 비교하면 
s.top()블록을 기준으로 오른쪽이 나보다 크고 왼쪽이 나보다 크거나 같으므로 현재 주어진 상황에서의 TrappingRainWater값을 구할 수 있다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;

        stack<int> s;
        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty()) break;
                int dist = i - s.top() - 1;
                int h = min(height[i], height[s.top()]) - height[top];
                answer += dist * h;
            }
            s.push(i);
        }
        return answer;
    }
};

int main() {
    vector<int> h = { 4,2,0,3,2,5 };
    printf("%d\n", Solution().trap(h));
    return 0;  
}
