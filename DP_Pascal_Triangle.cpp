class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        answer.push_back({1});
        if(numRows == 1 ) return answer;
        answer.push_back({1,1});
        if(numRows==2) return answer;
        
        for(int i=2;i<numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=0;j<i-1;j++){
                int newNum = answer[i-1][j]+answer[i-1][j+1];
                temp.push_back(newNum);
            }
            temp.push_back(1);
            answer.push_back(temp);
        }
        return answer;
    }
};
