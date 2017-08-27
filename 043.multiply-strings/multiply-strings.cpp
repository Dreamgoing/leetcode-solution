class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
          return "0";
        }
        int n = num1.length(), m= num2.length();
        vector<int> res(n+m,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<n;i++){
          int dig = num1[i]-'0';
          for(int j=0;j<m;j++){
            res[i+j] += dig*(num2[j]-'0');
          }
        }
        string res_str="";
        long long cur = 0;
        for(int i = 0;i<res.size();i++){
          cur+=res[i];
          res_str = to_string(cur%10)+res_str;
          cur/=10;
        }
        if(cur!=0){
          res_str = to_string(cur)+res_str;
        }
        int pos = 0;
        for(int i = 0;i<res_str.length();i++){
          if(res_str[i]=='0'){
            continue;
          }else{
            pos = i;
            break;
          }
        }
        return res_str.substr(pos, res_str.length()-pos);
    }
};
