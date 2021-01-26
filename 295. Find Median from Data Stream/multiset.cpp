/**
 * @brief 
 * Runtime: 104 ms, faster than 95.80% of C++ online submissions for Find Median from Data Stream.
 * Memory Usage: 49.3 MB, less than 11.94% of C++ online submissions for Find Median from Data Stream.
 * 
 * 시간복잡도
 * addNum() : O(logn)
 * findMedian() : O(1)
 * 공간복잡도 : O(N)
 * 
 * idea : addNum()이 호출될때 마다 Balanced BST를 유지할 수 있다면 중간값을 쉽게 찾을 수 있다.
 * C++에서 set이 Balanced BST 형태로 구현되어있고, value가 중복될수 있으므로 multiset을 이용하여 Median을 찾는다.
 */

class MedianFinder
{
public:
    multiset<int> ms;
    multiset<int>::iterator mid;

    void addNum(int num)
    {
        if (ms.size() == 0)
        {
            ms.insert(num);
            mid = ms.begin();
            return;
        }

        ms.insert(num);
        const int size = ms.size();
        if (size & 1)
            mid = (*mid <= num) ? next(mid) : mid;
        else
            mid = (*mid > num) ? prev(mid) : mid;
    }

    double findMedian()
    {
        const int size = ms.size();
        if (size & 1)
            return (double)(*mid);
        else
            return (*mid + *next(mid)) / 2.0;
    }
};
