/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    static bool compare(const Interval &i1,const Interval &i2){
         return i1.start < i2.start;
     }
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        if(intervals.size()<=1) return true;
        sort(intervals.begin(),intervals.end(),compare);

        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i].end>intervals[i+1].start) return false;
        }
        return true;
    }
};
