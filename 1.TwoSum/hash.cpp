/*
시간복잡도 O(N)
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> answer;
		map<int, int> m;

		for (int i = 0; i < nums.size(); i++) {
			if (m.count(target - nums[i])) {
				answer.push_back(m[target - nums[i]]);
				answer.push_back(i);
				return answer;
			}
			else {
				m[nums[i]];
			}
		}

		return answer;
	}
};
