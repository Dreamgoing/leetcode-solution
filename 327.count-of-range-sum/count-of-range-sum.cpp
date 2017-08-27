class Solution {
public:
    using  ll = long;

    void showSum(const vector<ll> &sum,int l,int r){
        cout<<"show "<<l<<" "<<r<<endl;
        for(int i = l;i<=r;i++){
            cout<<sum[i]<<' ';
        }
        cout<<'\n';
    }
    void mergeSum(vector<ll>& sum,int l,int r,int mid){
        vector<ll> tmp;
//        showSum(sum,l,r);
        int i = l,j = mid+1;
        for(int k = 0;k<l;k++){
            tmp.push_back(sum[k]);
        }
        while (i<=mid&&j<=r){
            if(sum[i]<sum[j]){
                tmp.push_back(sum[i]);
                i++;
            } else{
                tmp.push_back(sum[j]);
                j++;
            }
        }

        while (i<=mid){
            tmp.push_back(sum[i]);
            i++;
        }
        while (j<=r){
            tmp.push_back(sum[j]);
            j++;
        }
        for(int k = r+1;k <sum.size();k++){
            tmp.push_back(sum[k]);
        }
//        cout<<'i'<<endl;
//        showSum(tmp,0,tmp.size()-1);
        sum = tmp;
//        sum = {0};
    }
    int mergeSort(vector<long>& sum, int lower, int upper, int low, int high)
    {
        if(high-low <= 1) return 0;
        int mid = (low+high)/2, m = mid, n = mid, count =0;
        count = mergeSort(sum,lower,upper,low,mid) + mergeSort(sum,lower,upper,mid,high);
        for(int i =low; i< mid; i++)
        {
            while(m < high && sum[m] - sum[i] < lower) m++;
            while(n < high && sum[n] - sum[i] <= upper) n++;
            count += n - m;
        }
        inplace_merge(sum.begin()+low, sum.begin()+mid, sum.begin()+high);
//        cout<<low<<" "<<high<<" "<<mid<<endl;
//        mergeSum(sum,low,high,mid+1);
//        sum = {0,1,2,3,4,5,6};
//        showSum(sum,0,4);
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        vector<ll> sum(len+1,0);
        for(int i =0; i< len; i++) sum[i+1] = sum[i]+nums[i];
//        showSum(sum,0,4);
        return mergeSort(sum, lower, upper, 0, len+1);
    }
};