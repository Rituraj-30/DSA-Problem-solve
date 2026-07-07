class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int st=-1;

        vector<int> dic(256,-1);

        for(int i=0;i<s.size();i++){

            if(dic[s[i]]>st){
                st=dic[s[i]];
            }
            dic[s[i]]=i;
            maxi=max(maxi,i-st);
        }
        return maxi;
    }
};