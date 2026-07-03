class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long dd = abs((long long)dividend);
        long long dv = abs((long long)divisor);

        long long ans = 0;

        while(dv<=dd){
            long long sum=dv;
            long long count=1;

            while(sum<=dd-sum){
                sum+=sum;
                count+=count;
            }
            ans+=count;
            dd-=sum;
        }
    return isNegative ? -ans : ans;


        
    }
};