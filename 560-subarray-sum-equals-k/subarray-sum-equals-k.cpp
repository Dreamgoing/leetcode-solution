
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        
        int n = nums.size();
        vector<int> sum(n+1,0);
        for(int i = 0;i<n;i++){
          sum[i+1] = sum[i]+nums[i];
        }
        for(int i = 1;i<=nums.size();i++){
          for(int j = 0;j<i;j++){
            if(sum[i]-sum[j]==k){
              res++;
            }
          }
        }
        return res;
    }
};
