class Solution {
public:
    struct pointHelp{
        int point1,point2;
        float distance;
        pointHelp(int p1,int p2,float d):point1(p1),point2(p2),distance(d){
        }
    };
    
    struct less_than_key
{
    inline bool operator() (const pointHelp& struct1, const pointHelp& struct2)
    {
        return (struct1.distance < struct2.distance);
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pointHelp> mp;
        
        for(int i=0;i<points.size();i++){
            vector<int> point = points[i];
            float distance = sqrt(point[0]*point[0]+point[1]*point[1]);
            mp.push_back(pointHelp(point[0],point[1],distance));
        }
        sort(mp.begin(),mp.end(),less_than_key());
        
        vector<vector<int>> ans;
        int j=0;
        while(j<k){
            vector<int> temp;
            temp.push_back(mp[j].point1);
            temp.push_back(mp[j].point2);
            ans.push_back(temp);
            j++;
        }
        return ans;
        
    }
};
