class Solution {
public:
    //Sort the intervals by ending time
    struct myComparator{
      bool operator()(const vector<int> &a,const vector<int> &b){
          return a[1]<b[1];
      }  
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),myComparator());
        int answer = 0;
        
        int currIndex = 0;
        
        //For every interval check the previos non overlapping intervals ending time
        //If it does not overlap make the current index as the new non overlapping interval
        //otherwise increment the answer
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[currIndex][1]){
                answer++;
            }
            else currIndex=i;
        }
        return answer;
    }
};
