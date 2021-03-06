/*
Approach 2
시간복잡도 (nlogn)
공간복잡도 (3*n)
Runtime: 28 ms, faster than 6.71% of C++ online submissions for Trapping Rain Water.
Memory Usage: 16.1 MB, less than 7.21% of C++ online submissions for Trapping Rain Water.

1번 접근방법에서 pivot을 기준으로 왼쪽 혹은 오른쪽에 대해 가장 큰 블록을 찾을때 매 타이밍마다 O(N)의 시간이 소요되어 결국 전체 코드의 시간복잡도가 O(N^2)이었는데,
가장 큰 블록을 찾을때 우선순위큐를 사용하여 O(logN)의 시간이 소요되도록 구현하였다.
*/

class Solution {
public:
	struct Node {
		int val;
		int idx;
		Node() {}
		Node(int val, int idx) :val(val), idx(idx) {}
	};

	struct CompareFromLeftToRight {
		int operator()(const Node& n1, const Node& n2) {
			if (n1.val == n2.val) {
				return n1.idx < n2.idx;
			}
			return n1.val < n2.val;
		}
	};

	struct CompareFromRightToLeft {
		int operator()(const Node& n1, const Node& n2) {
			if (n1.val == n2.val) {
				return n1.idx > n2.idx;
			}
			return n1.val < n2.val;
		}
	};

	priority_queue<Node, vector<Node>, CompareFromLeftToRight> lrpq;
	priority_queue<Node, vector<Node>, CompareFromRightToLeft> rlpq;
	int answer = 0;
	int d[30000];

	void goLeft(vector<int>& height, int pivot_idx) {
		if (pivot_idx <= 0) return;
		Node node;
		while (true) {
			if (lrpq.empty()) {
				return;
			}

			node = lrpq.top();
			lrpq.pop();

			if (node.idx < pivot_idx) {
				answer += ((min(height[node.idx], height[pivot_idx])) * (pivot_idx - node.idx - 1)) - (d[pivot_idx - 1] - d[node.idx]);
				break;
			}
		}
		goLeft(height, node.idx);
	}

	void goRight(vector<int>& height, int pivot_idx) {
		if (pivot_idx >= height.size() - 1) return;
		
		Node node;
		while (true) {
			if (rlpq.empty()) {
				return;
			}

			node = rlpq.top();
			rlpq.pop();

			if (node.idx > pivot_idx) {
				answer += ((min(height[node.idx], height[pivot_idx])) * (node.idx - pivot_idx - 1)) - (d[node.idx - 1] - d[pivot_idx]);
				break;
			}
		}
		goRight(height, node.idx);
	}

	int trap(vector<int>& height) {
		int pivot = 0;
		int pivot_idx = 0;

		for (int i = 0; i < height.size(); i++) {
			if (i == 0) {
				d[i] = height[i];
			}
			else {
				d[i] = d[i - 1] + height[i];
			}
			lrpq.push(Node(height[i], i));
			rlpq.push(Node(height[i], i));
			if (pivot < height[i]) {
				pivot = height[i];
				pivot_idx = i;
			}
		}

		goLeft(height, pivot_idx);
		goRight(height, pivot_idx);

		return answer;
	}
};
