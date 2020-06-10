// namespace std have been included for this problem.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Interval {
    public:
        int start;
        int end;
        Interval(){}
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
};

bool compare(const Interval &a, const Interval &b)
{
    return (a.start < b.start ||
    (a.start == b.start && a.end < b.end ));
}


// Add any helper functions(if needed) above.
vector<Interval> merge_intervals(vector<Interval> intervals_list)
{
    cout << "Begin" << endl;
    vector<Interval> merged;

    sort(intervals_list.begin(), intervals_list.end(), compare);

    for (int i = 0; i < intervals_list.size(); i++) {
      int start = intervals_list[i].start;
      int end = intervals_list[i].end;
      cout << "[" << start << "," << end << "]" << endl;
    }



    for (int i = 0; i < intervals_list.size(); i++) {
        int j = i + 1;

        int start = intervals_list[i].start;
        int end = intervals_list[i].end;
        cout << "i:" << i << " start:" << start << " end:" << end << endl;
        for (j; j < intervals_list.size(); j++) {
            if (intervals_list[j].start <= end) {
                end = intervals_list[j].end;
                cout << "(Update) end:" << end << endl;
            } else {
              cout << "(Break) j:" << j << " i:" << i << endl;
                break;
            }
        }
        i = j-1;
        Interval overlap(start, end);
        merged.push_back(overlap);
    }
    cout << "Complete" << endl;
    return merged;
}

int main() {
  vector<Interval> intervalList= {Interval(-1,3), Interval(1,2), Interval(2,4)};


  vector<Interval> result = merge_intervals(intervalList);

  cout << "RESULT:" << endl;

  for (int i = 0; i < result.size(); i++) {
    int start = result[i].start;
    int end = result[i].end;
    cout << "[" << start << "," << end << "]" << endl;
  }

  return 0;
}
