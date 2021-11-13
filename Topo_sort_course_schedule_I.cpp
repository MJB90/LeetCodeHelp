class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> indegree(numCourses,0);
      vector<int> adjList[numCourses];
        
        //Adjacency List
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adjList[u].push_back(v);
        }
        
        //Calculate indegree
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adjList[i].size();j++){
                indegree[adjList[i][j]]++;
            }
        }
        
        queue<int> myqueue;
        
        //Push all nodes with indegree 0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) myqueue.push(i);
        }
        
        vector<int> result;
        
        //for every node in queue decrement adjacent node's indegree 
        //if indegree of adjacent node is 0 then push it to queue
        while(!myqueue.empty()){
            int currNode = myqueue.front();
            myqueue.pop();
            result.push_back(currNode);
            for(int i=0;i<adjList[currNode].size();i++){
                indegree[adjList[currNode][i]]--;
                if(indegree[adjList[currNode][i]]==0) myqueue.push(adjList[currNode][i]);
            }
        }
        return result.size()==numCourses;
    
    }
};
