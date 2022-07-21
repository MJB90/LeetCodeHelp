#include<bits/stdc++.h>
using namespace std;

long long bfs(vector<vector<int> > arr,int r,int c,long long l,int N,int M,vector<vector<int> > visited){
    queue<pair<int,int> > mq;
    vector< vector<long long> > distance(N+1,vector<long long>(M+1,INT_MAX));
    mq.push(make_pair(r,c));
    distance[r][c] = 0;
    int i,j;
    while(!mq.empty()){
        pair<int,int> p1 = mq.front();
        mq.pop();
        visited[p1.first][p1.second] = 1;
        i = p1.first;
        j = p1.second;

        long long poss = distance[i][j] + 1;
        if(j<M && !visited[i][j+1] && arr[i][j+1]==0){
            distance[i][j+1] = min(distance[i][j+1],poss);
            mq.push(make_pair(i,j+1));
         } 

    if(j>1 && !visited[i][j-1] && arr[i][j-1]==0){
        distance[i][j-1] = min(distance[i][j-1],poss);
            mq.push(make_pair(i,j-1));
    }

     if(i<N && !visited[i+1][j] && arr[i+1][j]==0){
        distance[i+1][j] = min(distance[i+1][j],poss);
            mq.push(make_pair(i+1,j));
    }

     if(i>1 && !visited[i-1][j] && arr[i-1][j]==0){
        distance[i-1][j] = min(distance[i-1][j],poss);
            mq.push(make_pair(i-1,j));
    }

    }
    return distance[N][M];
}
long long minLength (int N, int M, int Q, vector<vector<int> > query, int r, int c) {
   //Write your code here
   vector< vector<int> > arr(N+1,vector<int>(M+1,0));
   vector< vector<int> > visited(N+1,vector<int>(M+1,0));
   int j;
   for(int i=0;i<query.size();i++){
       if(query[i][0]==0){
        j=1;
        while(j<=query[i][2]){
            arr[query[i][1]][j]=1;
            j++;
        }
       }
       else{
           j = query[i][2];
           while(j<=M){
               arr[query[i][1]][j]=1;
               j++;
           }
       }
   }
   return bfs(arr,r,c,0,N,M,visited);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        int Q;
        cin >> Q;
        vector<vector<int> > query(Q, vector<int>(3));
        for (int i_query = 0; i_query < Q; i_query++)
        {
        	for(int j_query = 0; j_query < 3; j_query++)
        	{
        		cin >> query[i_query][j_query];
        	}
        }
        int r;
        cin >> r;
        int c;
        cin >> c;

        long long out_;
        out_ = minLength(N, M, Q, query, r, c);
        cout << out_;
        cout << "\n";
    }
}
