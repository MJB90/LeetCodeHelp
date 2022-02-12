class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> temp(s.length()+1);
        
        temp[s.length()] = 1;
        
        for(int i=s.length();i>=0;i--){
            for(int j=0;j<wordDict.size();j++){
                if(i+wordDict[j].length()<=s.length() && s.substr(i,wordDict[j].length())
                  == wordDict[j]){
                    temp[i]= temp[i+wordDict[j].length()];
                }
                if(temp[i]) break;
            }
        }
        return temp[0];
    }
};
