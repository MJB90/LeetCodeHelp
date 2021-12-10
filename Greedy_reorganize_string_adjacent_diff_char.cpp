class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> myqueue;
        map<char,int> mp;
        
        for(auto c:s)
            mp[c]++;
        
        for(auto it:mp)
            myqueue.push({it.second,it.first});
        
        pair<int,char> p = {-1,'$'};
        string answer = "";
        while(!myqueue.empty()){
            auto tp = myqueue.top();
            myqueue.pop();
            
            answer+=tp.second;
            
            if(p.first>0){
                myqueue.push(p);
            }
            tp.first--;
            p=tp;
        }
        cout<<answer;
        if(answer.length()==s.length()) return answer;
        else return "";
    }
};
