#include <bits/stdc++.h>

using namespace std;

// 731. 我的日程安排表 II

// 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。

// MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end 时间内增加一个日程安排。
// 注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。

// 当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生三重预订。

// 每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。

// 请按照以下步骤调用MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

// 暴力
class MyCalendarTwo {
    typedef pair<int,int> interval;
private:
    vector<interval> onceIntervals;
    vector<interval> twiceIntervals;
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        for(auto& time : twiceIntervals){
            // 若和重叠区间重合
            if(start<time.second&&end>time.first){
                return false;
            }
        }
        for(auto& time : onceIntervals){
            // 若和正常区间重合
            if(start<time.second&&end>time.first){
                twiceIntervals.push_back(make_pair(max(time.first,start),min(time.second,end)));
            }
        }
        onceIntervals.push_back(make_pair(start,end));
        return true;
    }
};

// 线段树
// class MyCalendarTwo {
// public:
//     MyCalendarTwo() {

//     }

//     void update(int start, int end, int val, int l, int r, int idx) {
//         if (r < start || end < l) {
//             return;
//         } 
//         if (start <= l && r <= end) {
//             tree[idx].first += val;
//             tree[idx].second += val;
//         } else {
//             int mid = (l + r) >> 1;
//             update(start, end, val, l, mid, 2 * idx);
//             update(start, end, val, mid + 1, r, 2 * idx + 1);
//             tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
//         }
//     }

//     bool book(int start, int end) {            
//         update(start, end - 1, 1, 0, 1e9, 1);
//         if (tree[1].first > 2) {
//             update(start, end - 1, -1, 0, 1e9, 1);
//             return false;
//         }
//         return true;
//     }
// private:
//     unordered_map<int, pair<int, int>> tree;
// };
