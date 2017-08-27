class Solution {
public:
    int reverse(int x) {
     using ll = long long;
    bool flag = 0;
    int tmpx = x;
    ll res = 0;
    if(x<0){
        tmpx = -x;
        flag = true;
    }
    while (tmpx>0){
        res*=10ll;
        res+=tmpx%10;
        tmpx/=10;
    }
    if(flag){
        res=-res;
    }
    if(res>=-(1<<31)&&res<=(1ll<<31)-1){
        return (int)res;
    } else{
        return 0;
    }

        
    }
};