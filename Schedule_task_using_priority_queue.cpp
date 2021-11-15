class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for(auto t:tasks){
            if(mp.find(t)==mp.end()) mp[t]=1;
            else mp[t]++;
        }
        //calculate highest frequency
        priority_queue<int> pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int hfreq = pq.top();
        pq.pop();
        int hfreqcount = 1;
        //Calculate number of task with highest frequency
        while(!pq.empty() && pq.top()==hfreq){
            hfreqcount++;
            pq.pop();
        }
        //Formulae
        int panswer = (hfreq-1)*(n+1) + hfreqcount;
        int msize = tasks.size();
        return max(msize,panswer);
    }
};
