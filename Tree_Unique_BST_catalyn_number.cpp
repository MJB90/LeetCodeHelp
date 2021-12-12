class Solution {
public:
    int numTrees(int n) {
        vector<int> t(n+1,0);
        
        //with 0 nodes on left/right side unique trees is 1 
        t[0]=1;
        
        //with 0 nodes on left/right side unique trees is 1
        t[1]=1;
        
        //Loop through number of nodes 
        for(int i=2;i<=n;i++){
            
            //For every i take j as the root and calculate unique trees on left and right
            //Answer at i is number of trees on left * number of trees on right
            for(int j=0;j<i;j++){
                t[i] += t[j]*t[i-j-1];
            }
        }
        return t[n];
    }
};
