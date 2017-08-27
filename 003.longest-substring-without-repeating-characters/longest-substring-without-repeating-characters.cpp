class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int ans = 0;
    int st = 0;
    int fn = 0;
    map<char,int> pos;
    pos.clear();
    for(int i = 0;i<s.length();i++){
        map<char,int>::iterator it = pos.find(s[i]);
        if(it==pos.end()){
            pos[s[i]] = i;

        }else{
            st = max(pos[s[i]]+1,st);
            pos[s[i]] = i;
        }
//        cout<<"pos "<<pos[s[i]]<<" "<<st<<endl;
        ans = max(ans,i-st+1);

    }
    return ans;
    }
};