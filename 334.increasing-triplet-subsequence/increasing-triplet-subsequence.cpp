const int MAX_INF = 0x7fffffff;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      if(nums.size()<3){
          return false;
      }
      int n = nums.size();
      // 注意一点,从1开始遍历, 注意边界条件
      int a = nums[0], b=MAX_INF;
      for(int i = 1;i<n;i++){
        if(nums[i]<=a){
          a = nums[i];
        }else if(nums[i]<b){
          b = nums[i];
        }else if(nums[i]>b){
          return true;
        }
      }
      return false;
    }
};
