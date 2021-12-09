class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()) mp[s[i]] = 1;
            else mp[s[i]] ++;
        }
        
        int evenCount=0,oddCount=0,numOdds=0;
        
        for(auto it:mp){
            if(it.second%2==0){
                evenCount+=it.second;
            }    
            else{
                oddCount += it.second;
                numOdds++;
            }
        }
        if(oddCount>0)
            return evenCount+oddCount-numOdds+1;
        else return evenCount;
    }
};
