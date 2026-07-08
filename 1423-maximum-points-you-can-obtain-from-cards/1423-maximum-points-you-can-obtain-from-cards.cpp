class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum=0;
        int n=cardPoints.size();
        for(int i:cardPoints){
            totalSum+=i;
        }
        if(n==k) return totalSum;

        int windo=n-k;
        int currentSum=0;

        for(int i=0;i<windo;i++){
            currentSum=currentSum+cardPoints[i];
        }
        int minSum=currentSum;

        for(int right=windo;right<n;right++){
            currentSum=currentSum+cardPoints[right];

            currentSum-=cardPoints[right-windo];

            minSum=min(minSum,currentSum);
        }
    
    return totalSum-minSum;
    }
};