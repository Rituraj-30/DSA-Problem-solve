class Solution {
public:
    //  set<vector<int>>s;
    void helper(int idx,int target,vector<int>& nums,vector<int>&combin,vector<vector<int>>&ans){
           if(target==0){
            // if(s.find(combin)==s.end()){
            //     s.insert(combin);
                ans.push_back(combin);
            // }
            return ;
        }
        if(idx==nums.size() || target<0){
            return ;
        }
        for(int i=idx ;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;

            combin.push_back(nums[i]);
            helper(i+1, target-nums[i],nums, combin,ans);
            combin.pop_back();


        }

    }
    vector<vector<int>> combinationSum2(vector<int>&nums , int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        sort(nums.begin(),nums.end());

        helper(0, target,nums, combin,ans);
        return ans;

    }
};