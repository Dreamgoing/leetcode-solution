class Solution {
public:

int countPrimes(int n){
    int res = 0;
    vector<bool> vis(n,0);
    vis[0] = true;
    vis[1] = true;
    
    for(int i = 0;i<sqrt(n);i++){
        if(!vis[i]){
            for(int j = i*i;j<n;j+=i){
                vis[j] = true;
            }
        }
    }
    res = 0;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            res++;
        }
    }
    return res;

}
};