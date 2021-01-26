/*
시간복잡도
addNum() : O(n)
findMedian() : O(1)
Runtime: 1352 ms, faster than 5.51% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 47.1 MB, less than 98.52% of C++ online submissions for Find Median from Data Stream.

어떻게 접근해야할지 생각이 잘 안나서 가장 기본적으로 접근해봤다.
addNum(int num) : 숫자가 추가될때마다 순차적으로 가장 알맞은 자리에 넣고 나머지를 뒤로 한칸씩 땡겨준다.
findMedian() : addNum()에서 숫자 추가할때마다 vector는 정렬 되어있으므로 가운데 숫자를 찾아서 리턴해준다.
*/

class MedianFinder {
public:
    vector<int> v;

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void insert(vector<int>& v, int idx, int num) {
        v.push_back(num);
        for (int i = v.size() - 1; i > idx; --i) {
            v[i] = v[i - 1];
        }
        v[idx] = num;
    }

    void addNum(int num) {
        if (v.size() == 0) {
            v.push_back(num);
            return;
        }
        
        for (int i = 0; i < v.size(); i++) {
            if (num <= v[i]) {
                insert(v, i, num);
                return;
            }
        }

        v.push_back(num);
    }

    double findMedian() {
        int size = v.size();
        int idx = size / 2;
        if (size % 2 == 0) {
            return (v[idx] + v[idx - 1]) / 2.0;
        }
        else {
            return (double)v[idx];
        }
    }
};
