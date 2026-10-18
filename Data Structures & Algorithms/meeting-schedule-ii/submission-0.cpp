/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    priority_queue<int, vector<int>, greater<int>> ends;

    for (auto& m : intervals) {
        if (!ends.empty() && ends.top() <= m.start) ends.pop(); // reuse freed room
        ends.push(m.end);
    }
    return ends.size();
}
};
