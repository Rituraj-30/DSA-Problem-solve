class Solution {
public:
    double myPow(double x, int n) {
        long long bin=n;
        double ans=1;
        if (bin < 0) {
        bin = -bin;
    }
      
        while (bin > 0) {
        if (bin % 2 == 1) {
            ans = ans * x;
        }
        x = x * x;
        bin = bin / 2;
    }
    if (n < 0) {
        return (double)(1.0) / (double)(ans);
    }

    return ans;





    //      long long NN = n;

    //     if(NN<0){
    //         NN=-NN;
    //     }
    //     double ans=1.0;

    //     while(NN>0){
    //         if(NN%2==1){
    //                 ans=ans*x;
    //                 NN=NN-1;
    //         }else{
    //                 x=x*x;
    //                 NN=NN/2;
    //         }
    //     }
    //    if (n < 0) {
    //         ans = 1.0 / ans;
    //     }

    //    return ans;
    }
};