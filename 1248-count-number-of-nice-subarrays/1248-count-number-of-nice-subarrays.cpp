class Solution {
public:
    int getAns(vector<int>& nums, int k){
        if(k<0) return 0;

        int left=0,count=0;
        int oddCount=0;
        for(int right=0;right<nums.size();right++){

            if(nums[right]%2!=0)oddCount++;

            while(oddCount>k){
                if(nums[left]%2!=0)oddCount--;

                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return getAns(nums,k)-getAns(nums,k-1);
    }
};