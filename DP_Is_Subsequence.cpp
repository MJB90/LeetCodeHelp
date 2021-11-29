class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j =0;
        while(i<t.length() && j<s.length()){
            if(s[j]==t[i]){
                j++;
                i++;
            }
            else{
                i++;
            }
        }
        if(j==s.length()) return true;
            else return false;
    }
};
