class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int pos = m-1;
      for(int i = 0;i<m;i++){
        nums1[pos+n] = nums1[pos];
        pos--;
      }
      int nums1_pos = n;
      int nums2_pos = 0;
      pos = 0;
      while (nums2_pos<n&&nums1_pos<n+m) {
        if(nums1[nums1_pos]<nums2[nums2_pos]){
          nums1[pos] = nums1[nums1_pos];
          nums1_pos++;
        }else{
          nums1[pos] = nums2[nums2_pos];
          nums2_pos++;
        }
        pos++;
      }
      while(nums1_pos<n+m){
        nums1[pos++] = nums1[nums1_pos++];
      }
      while (nums2_pos<n) {
        nums1[pos++] = nums2[nums2_pos++];
      }

    }
};
