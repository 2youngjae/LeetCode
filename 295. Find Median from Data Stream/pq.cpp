/**
 * @brief 
 * Runtime: 104 ms, faster than 96.44% of C++ online submissions for Find Median from Data Stream.
 * Memory Usage: 46.8 MB, less than 96.67% of C++ online submissions for Find Median from Data Stream.
 * 
 * 1. PQ 두개를 이용하여 중간값을 기준으로 중간값보다 작은건 maxHeap에 넣고 중간값보다 큰것은 minHeap에 넣는다.
 * 2. maxHeap과 minHeap의 밸런스를 맞춰준다 (size를 맞춰준다.)
 * 3. 전체 갯수가 홀수일때 중간값은 maxHeap.top()이 되고, 전체 갯수가 짝수일때 중간값은 (maxHeap.top()+minHeap.top())/2 가 된다.
 */

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int num)
    {
        if (maxHeap.size() == 0)
        {
            maxHeap.push(num);
            return;
        }

        if (maxHeap.top() > num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if ((maxHeap.size() + minHeap.size()) & 1)
        {
            if (maxHeap.size() < minHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else
        {
            if (maxHeap.size() > minHeap.size() + 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }

    double findMedian()
    {
        return ((maxHeap.size() + minHeap.size()) & 1) ? (double)maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
