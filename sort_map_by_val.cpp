class Solution {
public:
    static bool cmp( pair<int,int> &a, pair<int,int> &b){
        return a.second<b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()) mp[nums[i]]=1;
            else mp[nums[i]]++;
        }
        vector<pair<int,int>> toSort;
        map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            toSort.push_back(make_pair(it->first,it->second));
        }
        
        sort(toSort.begin(),toSort.end(),cmp);
        
        vector<int> ans;
        int j = toSort.size()-1;
        while(k>0){
            ans.push_back(toSort[j--].first);
            k--;
        }
        return ans;
    }
};
