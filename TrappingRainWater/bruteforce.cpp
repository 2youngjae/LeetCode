/*
Approach 1
시간복잡도 O(n ^ 2)
공간복잡도 O(1 * n)

풀이과정:
1. 가장 높은 블록을 찾는다.
2. 가장 높은 블록을 기준으로 왼쪽에서 가장 높은 블록을 찾고 계산한다.
3. 2번에서 찾은 블록을 기준으로 다시 왼쪽에서 가장 높은 블록을 찾고 계산한다.
4. index가 0까지 반복하고 오른쪽도 같은 방법으로 반복한다.

Worst case:
pivot을 기준으로 한쪽방향에 있는 모든 블록을 다 비교하여 max값을 찾으므로 블록이[7, 6, 5, 4, 3, 2, 1] 처럼 순차적으로 낮아지는경우 같은장소에 대하여 중복하여 반복하게 된다.
*/

class Solution {
public:
	int d[30000];
	int answer = 0;

	//pivot 보다 왼쪽에서 가장큰 block을 찾아 계산
	void findLeft(vector<int>& height, int pivot_idx) {
		if (pivot_idx <= 0) return;

		int max_num = 0;
		int max_idx = 0;
		for (int i = 0; i < pivot_idx; ++i) {
			if (max_num < height[i]) {
				max_num = height[i];
				max_idx = i;
			}
		}

		answer += max_num * (pivot_idx - max_idx - 1) - (d[pivot_idx - 1] - d[max_idx]);

		findLeft(height, max_idx);
	}

	//pivot 보다 오른쪽에서 가장큰 block을 찾아 계산
	void findRight(vector<int>& height, int pivot_idx) {
		if (pivot_idx >= height.size() - 1) return;

		int max_num = 0;
		int max_idx = 0;
		for (int i = pivot_idx + 1; i < height.size(); ++i) {
			if (max_num <= height[i]) {
				max_num = height[i];
				max_idx = i;
			}
		}

		if (pivot_idx >= max_idx) return;

		answer += max_num * (max_idx - pivot_idx - 1) - (d[max_idx - 1] - d[pivot_idx]);

		findRight(height, max_idx);
	}

	int trap(vector<int>& height) {
		int pivot = 0;
		int pivot_idx = 0;
		for (int i = 0; i < height.size(); ++i) {
			if (i == 0) {
				d[i] = height[i];
			}
			else {
				d[i] = d[i - 1] + height[i];
			}

			if (pivot < height[i]) {
				pivot = height[i];
				pivot_idx = i;
			}
		}

		findLeft(height, pivot_idx);
		findRight(height, pivot_idx);

		return answer;
	}
};
