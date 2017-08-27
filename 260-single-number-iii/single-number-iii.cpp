class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ab^=nums[i];
        }
        int bit = ab&(~(ab-1)); ///获取res中,从右往左第一个1,即a,b中不同的第一个位,其他位为0

        vector<int> ret(2);
        ///分成两组
        for (int i = 0; i < nums.size(); ++i) {
            if(bit&nums[i]){
                ret[0]^=nums[i];
            } else{
                ret[1]^=nums[i];
            }
        }
        return ret;


    }
};