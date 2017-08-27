#include<iostream>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int> > pvector;
        pvector.clear();
        int n = pairs.size();
        for(int i = 0;i<n;i++){
          pvector.push_back(make_pair(pairs[i][0],pairs[i][1]));
        }
        sort(pvector.begin(), pvector.end());
        vector<int> dp(n,1);
        int res = 1;
        for(int i = 1;i<n;i++){
          for(int j = 0;j<i;j++){
            if(!hasConflict(pvector[j],pvector[i])){
              dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(dp[i], res);
          }
        }
        return res;

    }
    bool hasConflict(pair<int,int> p1, pair<int,int> p2){
      return !(p1.second<p2.first);
    }
};
