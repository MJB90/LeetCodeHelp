class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //transpose
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        //reverse
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
