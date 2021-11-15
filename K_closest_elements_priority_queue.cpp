class Solution {
public:
    struct compare{
      bool operator()(pair<int,int> &a, pair<int,int> &b){
          if(abs(a.first-a.second)<abs(b.first-b.second)) return false;
          if(abs(a.first-a.second)==abs(b.first-b.second) && a.first<b.first) return false;
          return true;
      }  
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare > pq;
        for(auto i:arr){
            pq.push(make_pair(i,x));
        }
        vector<int> answer;
        
        while(k>0){
            answer.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};
