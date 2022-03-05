class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> left(height.size()),right(height.size());
        
        int maxArea = 0;
        int l=0,r=height.size()-1;
        
        while(l<r){
            int currArea = (r-l)*min(height[l],height[r]);
            maxArea = max(maxArea,currArea);
            
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxArea;
    }
};
