class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int left=0;
      int windo=0;
      int maxi=0;

      for(int right=0;right<nums.size();right++){
        windo+=nums[right];

        while(right-left+1 != windo){
            windo=windo-nums[left];
            left++;
        }

        maxi=max(maxi,right-left+1);
      }
      return maxi;
    }
};