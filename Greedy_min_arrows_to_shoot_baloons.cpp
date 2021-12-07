class Solution {
public:
    
    struct myComparator{
      bool operator()(const vector<int> &a,const vector<int> &b){
          return a[1]<b[1];
      }  
    };
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), myComparator()); // sort on the basis of ending points
        int arrow = 1, end = points[0][1];   
        
        for(int i = 1; i<points.size(); i++)
        {
            int start = points[i][0];
            if(start > end) // Non-Overlapping
            {
                arrow++; 
                end = points[i][1];
            }
        }
        return arrow;
    }
};
