/*
시간복잡도 O(NlogN)
공간복잡도 O(1*N)

1. input으로 넘어온 nums를 index와 함께 정렬한다.
2. 2 pointer를 이용하여 target number를 찾는다.
*/

#define PII pair<int, int>
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<PII> v;
		vector<int> answer;
		for (int i = 0; i < nums.size(); i++) {
			v.push_back(PII(nums[i], i));
		}

		sort(v.begin(), v.end());

		int i = 0;
		int j = v.size() - 1;
		while (i < j) {
			int sum = v[i].first + v[j].first;
			if (sum == target) {
				answer.push_back(v[i].second);
				answer.push_back(v[j].second);
				break;
			}
			else if (sum < target) ++i;
			else --j;
		}

		return answer;
	}
};
