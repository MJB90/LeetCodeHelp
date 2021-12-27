class Solution {
private:
    vector<string>res;
public:
    vector<string> generateParenthesis(int n) {
        if(!n) return {};
        int nOpen = n, nClose = 0;
        addParanthesis("", nOpen, nClose);
        return res;
    }
    void addParanthesis(string curr, int nOpen, int nClose){
        if(nOpen == 0 and nClose == 0){
            res.push_back(curr);
            return;
        }
        if(nOpen > 0){
            addParanthesis(curr+'(', nOpen-1, nClose+1); //adding one open paranthesis is bringing need to add one closing paranthesis
        }
        if(nClose > 0){
            addParanthesis(curr+')', nOpen, nClose-1);
        }
    }
};
