class Solution {
public:
    vector<int> temp;
    int CountSteps(int n){
        if(n<=0) return 0;
        if(n==1 || n==2) return n;
        if(temp[n]!=-1) return temp[n];
        else{
            temp[n] = CountSteps(n-1)+CountSteps(n-2);
            return temp[n];
        }
    }
    int climbStairs(int n) {
        temp.resize(n+1);
        fill(temp.begin(),temp.end(),-1);
        return CountSteps(n);
    }
};
