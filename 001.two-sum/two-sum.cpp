class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
    result.clear();
    map<int,vector<int> > mp;
    mp.clear();
    for(int i = 0;i<nums.size();i++){
        mp[nums[i]].push_back(i);
    }
    sort(nums.begin(),nums.end());
    bool found = false;
    for(int i = 0;i<nums.size();i++){
        if(found){
            break;
        }
        vector<int>::iterator re = find(nums.begin(),nums.end(),target-nums[i]);
        if(re!=nums.end()){
            found = true;
            if(nums[i]!=*re){
                result.push_back(mp[nums[i]][0]);
                result.push_back(mp[*re][0]);
            } else{
                result.push_back(mp[nums[i]][0]);
                result.push_back(mp[nums[i]][1]);
            }

        }
    }
    return result;
    }
};