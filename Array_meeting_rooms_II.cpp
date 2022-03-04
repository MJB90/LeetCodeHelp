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
     * @return: the minimum number of conference rooms required
     */

     static bool compare(Interval &i1,Interval &i2){
         return i1.start < i2.start;
     }
    int minMeetingRooms(vector<Interval> &intervals) {
        if(intervals.size()<=1) return intervals.size();

        vector<int> startTime,endTime;
        for(auto interval:intervals){
            startTime.push_back(interval.start);
            endTime.push_back(interval.end);
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());
        sort(intervals.begin(),intervals.end(),compare);

        int res=0,localres=0;
        int i =0,j=0;
        while(i<startTime.size()){
            if(startTime[i]<endTime[j]){
                i++;
                localres++;
            }
            else{
                j++;
                localres--;
            }
            res = max(res,localres);
        }        
        
        return res;
    }
};
