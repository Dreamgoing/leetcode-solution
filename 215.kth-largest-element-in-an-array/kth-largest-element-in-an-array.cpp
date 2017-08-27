class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      int n = nums.size();
      int rk = n-k;
      int pos = -1;
      int res = 0;
      int l = 0, r = n-1;
      while (pos!=rk) {
        pos = poivt(nums,l,r);
        if(pos==rk){
          return nums[pos];
        }else if(pos>rk){
          r = pos-1;
        }else{
          l = pos+1;
        }
      }
    }
    int poivt(vector<int>& nums, int l, int r){
      int p = nums[l];
      int pos = l;
      for(int i = l;i<=r;i++){
        if(nums[i]<p){
          swap(nums[i], nums[++pos]);
        }
      }
      swap(nums[l], nums[pos]);
      return pos;
    }
};
