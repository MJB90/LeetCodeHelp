class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> it(matrix.size(),0);
        
        int mx;
        int smpos,smnum;
        
        //Its like sorting r number of sorted arrays
        while(k>0){
            smpos = 0;
            smnum = INT_MAX;
            for(int i=0;i<matrix.size();i++){
                if(it[i]<matrix.size() && smnum>matrix[i][it[i]]){
                    smnum = matrix[i][it[i]];
                    smpos = i;
                }
            }
            it[smpos]++;
            k--;
        }
        return smnum;
    }
};
