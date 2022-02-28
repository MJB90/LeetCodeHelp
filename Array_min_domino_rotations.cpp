class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
       bool exist;
        int reqNum;
        for(int i=1;i<=6;i++){
            exist = true;
            for(int j=0;j<tops.size();j++){
                if(tops[j]!=i && bottoms[j]!=i){
                    exist = false;
                    break;
                }
            }
            if(exist){
             reqNum = i;
             break;   
            }
        }
        if(!exist) return -1;
        int topCount = 0,bottomCount=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]==reqNum && tops[i]!=bottoms[i]) topCount++;
            if(bottoms[i]==reqNum && tops[i]!=bottoms[i]) bottomCount++;
        }
        return min(topCount,bottomCount);
        
        
    }
};
