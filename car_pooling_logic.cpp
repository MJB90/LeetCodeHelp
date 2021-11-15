class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxDistance = trips[0][2];
        for(int i=0;i<trips.size();i++){
            maxDistance= max(maxDistance,trips[i][2]);
        }
        int numPassengers = 0;
        for(int i=0;i<maxDistance;i++){
            for(int j=0;j<trips.size();j++){
                if(i==trips[j][1]){
                    numPassengers += trips[j][0];
                }
                if(i==trips[j][2]){
                    numPassengers -= trips[j][0];
                }
                
            }
            if(numPassengers>capacity) return false;
        }
        return true;
    }
};

//https://leetcode.com/problems/car-pooling/submissions/
