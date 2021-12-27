class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid,high,low,start,end;
        low = 0;
        high = nums.size()-1;
        
        start = -1;
        end = -1;
        
        while(low<=high){
            mid = low + (high - low) /2;
            if(nums[mid]==target && mid == 0){
                start = mid;
                break;
            }
            else if(nums[mid]==target && nums[mid-1]!=target){
                start = mid;
                break;
            }
            else if(nums[mid]==target && nums[mid-1]==target){
                high = mid - 1;
            }
            else if(nums[mid]>target){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        
        low = 0;
        high = nums.size()-1;
        
        while(low<=high){
            mid = low + (high - low) /2;
            if(nums[mid]==target && mid == nums.size()-1){
                end = mid;
                break;
            }
            
            else if(nums[mid]==target && nums[mid+1]!=target){
                end = mid;
                break;
            }
            else if(nums[mid]==target && nums[mid+1]==target){
                low = mid + 1;
            }
            else if(nums[mid]<target){
                low = mid +1;
            }
            else{
                high = mid-1;
            }
        }
        
        return {start,end};
    }
};
