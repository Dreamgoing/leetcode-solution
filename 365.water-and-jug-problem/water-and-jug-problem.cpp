class Solution {
public:
    ///欧几里得定理:gcd(a,b) == gcd(b, a%b)
    ///扩展欧几里得算法: 对于不完全为 0 的非负整数 a，b，gcd（a，b）表示 a，b 的最大公约数，必然存在整数对 x，y ，使得 gcd（a，b）=ax+by。
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
    int exgcd(int a,int b,int &x,int &y){
        if(b==0){
            x = 1;
            y = 0;
            return a;
        }
        int r = exgcd(b, a%b, x, y);
        int t = x;
        x = y;
        y = t-a/b*y;
        return r;
    }

    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y){
            return false;
        }
        int a,b = 0;
        int r = exgcd(x,y,a,b);
        return (r!=0&&z%r==0)||(r==0&&z==0);
    }
};