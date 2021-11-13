class Solution {
public:
    struct compare{
      bool operator()(pair<int,char> &a, pair<int,char> &b){
          return a.first<b.first;
      }  
    };
    string frequencySort(string s) {
        map<char,int> mp;
        string answer = "";
        
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=1;
            }
            else mp[s[i]]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,compare> pq;
        map<char,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        while(!pq.empty()){
            pair<int,char> currPair = pq.top();
            pq.pop();
            
            while(currPair.first>0){
                answer+=currPair.second;
                currPair.first--;
            }
        }
        return answer;
    }
};
