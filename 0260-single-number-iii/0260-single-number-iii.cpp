class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorSum = 0;
        
        
        for (int num : nums) {
            xorSum ^= num;
        }

        unsigned int rightmostSetBit = xorSum & -(unsigned int)xorSum;

        int b1=0;
        int b2=0;

        for(int num:nums){
            if((num & rightmostSetBit) != 0){
                    b1=b1^num;
            }else{
                b2=b2^num;
            }
        }

     
        return {b1,b2};

    }
};