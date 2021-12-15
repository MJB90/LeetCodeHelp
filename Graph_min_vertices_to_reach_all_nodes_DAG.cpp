class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> answer;
        map<int,int> indegree;
        
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree.find(i)==indegree.end())
                answer.push_back(i);
        }
     return answer;   
    }
};
