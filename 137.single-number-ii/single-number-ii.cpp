
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int two = 0;
        int one = 0;
        int three = 0;
        for (int i = 0; i < nums.size(); ++i) {
            two|=one&nums[i];
            one^=nums[i];
            three=two&one;
            one&=~three;
            two&=~three;
        }
        return one;
    }
};