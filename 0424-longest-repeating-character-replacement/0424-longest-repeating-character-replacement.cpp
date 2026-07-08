class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,maxi=0,maxiSub=0;
        vector<int> freq(26,0);

        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            

            maxiSub=max(maxiSub, freq[s[right]-'A']);
            while((right-left+1)-maxiSub>k){
                freq[s[left]-'A']--;
                left++;
            }


            maxi=max(maxi,right-left+1);
        }
        return maxi;
        
    }
};