class Solution {
public:
    int getAns(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int current_sum=0,left=0,count=0;

        for(int right=0;right<nums.size();right++){
            current_sum+=nums[right];
            
            while (current_sum > goal) {
                current_sum -= nums[left];
                left++;
            }

            count +=(right-left+1);
        }
        return count;
    
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
            return getAns(nums,goal)-getAns(nums,goal-1);
    }

};