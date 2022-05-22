#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 1.seen set에 사이클별로 vector를 저장
// 2.어떤 지점에서 이미 이전에 나온 상태를 발견하면 최종 몇일이 걸릴지에 대해서
// 바로 알수 있다.

class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int n) {
    set<vector<int>> seen;

    for (int i = 0; i < n; i++) {
      vector<int> v = getNext(cells);
      // 이전에 나온적이 없는 vector이면 set에 insert
      if (seen.count(v) == 0) {
        seen.insert(v);
        cells = v;
        continue;
      }

      // 이미 나온적이 있는 vector이면 cycle에서 남은 일수만큼만 getNext를
      // 구해서 return.
      for (int j = 0; j < n % i; j++) {
        cells = getNext(cells);
      }
      return cells;
    }
    return cells;
  }

  vector<int> getNext(vector<int>& cells) {
    vector<int> n(cells.size(), 0);
    for (int i = 1; i < n.size() - 1; i++) {
      n[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
    }
    return n;
  }
};