class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int res = 1;
        vector<bool> isExist(nums.size()+1,false);
        for(auto it:nums){
            if(it<0){
                continue;
            }
            isExist[it] = true;
            if(it==res){

                int pos = it;
                while (isExist[pos]){
                    pos++;
                }
                res = pos;
            }
        }
        return res;
        
    }
};