///给定n+1个数, 这些数在1到n之间, 有一个数重复,求重复的数
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = (int) (nums.size() - 1);
        while (l<r){
            int m = l+(r-l)/2;
            int cnt = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if(nums[i]<=m){
                    cnt++;
                }
            }
            if (cnt<=m){
                l = m+1;
            } else{
                r = m;
            }
        }
        return l;
    }
};