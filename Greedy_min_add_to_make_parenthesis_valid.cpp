class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int i=0,answer=0;
        while(i<s.length()){
            if(s[i]=='('){
                stk.push('(');
            }
            else{
                if(!stk.empty()){
                char c = stk.top();
                stk.pop();
                    if(c!='(') answer++;
                }
                else{
                    answer++;
                }
            }
            i++;
        }
        
        while(!stk.empty()){
            answer++;
            stk.pop();
        }
        return answer;
    }
};
