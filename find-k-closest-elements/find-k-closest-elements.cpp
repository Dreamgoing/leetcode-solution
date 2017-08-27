class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        res.clear();
        int n = arr.size();
        int pos = mlowerbound(arr,x);
        int l = pos-1,r = pos;
        int num = 0;
        while (l>=0&&r<n&&num<k){
            int disl = abs(arr[l]-x);
            int disr = abs(arr[r]-x);
            if(disl<=disr){
                res.push_back(arr[l]);
                l--;
            } else {
                res.push_back(arr[r]);
                r++;
            }
            num++;
        }
        while(num<k){
            if(l<0){
                res.push_back(arr[r++]);
            }else{
                res.push_back(arr[l--]);
            }
            num++;
        }
        sort(res.begin(),res.end());
        return res;

    }
    int mlowerbound(vector<int>& arr, int key){
      int l = 0, r = arr.size();
      while (l<r) {
        int m = l+(r-l)/2;
        if(key>arr[m]){
          l = m+1;
        }else{
          r = m;
        }
      }
      return l;
    }
};
