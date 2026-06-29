class Solution {
public:


    vector<int> twoSum(vector<int>& nums, int target) {
        
   int n=nums.size();
        //  vector<int> ans;

        for(int i =0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int ans=nums[i]+nums[j];
                if(ans== target){ 
                    // ans.push_back(i);
                    // ans.push_back(j);
                    return {i,j}; 
                }
            }
        }
    return {0,0};
    }
};