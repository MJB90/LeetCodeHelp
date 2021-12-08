class Solution {
public:
    struct myComparator{
      bool operator()(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
      }  
    };
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),myComparator());
        
        int i=0,j=1,answer=1;
        
        for(j=1;j<pairs.size();j++){
            if(pairs[j][0]>pairs[i][1]){
                i=j;
                answer++;
            }
        }
        return answer;
    }
};
