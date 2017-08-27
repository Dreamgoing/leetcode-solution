    class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
          map<string,int> mp;
        map<int,int> nummp;
        vector<int>ve(s.length()+1,-1);
        vector<int> res;
        res.clear();
        mp.clear();
        nummp.clear();
        if(s.length()<words[0].length()){
            return res;
        }
        int num=0;
        int len = (int)words[0].length();
        for(auto it:words){
            if(mp.find(it)==mp.end()){
                mp[it] = num++;
            }
            nummp[mp[it]]++;
        }
//        for(auto it:nummp){
//            cout<<it.second<<"#"<<endl;
//        }
        for(int i = 0;i<=s.length()-len;i++){
            if(i+len>s.length()){
                continue;
            }
            string tmp = s.substr(i,len);
//            cout<<tmp;
            if(mp.find(tmp)!=mp.end()){
//                cout<<"ok"<<endl;
                ve[i] = mp[tmp];
            }
        }

        map<int,bool> isExist;
        for(int i = 0;i<s.length();i++){
            isExist.clear();
            map<int,int> tmpmp(nummp);
            int tmpnum = 0;
            if(ve[i]==-1){
                continue;
            }
            for(int j = i;j<s.length();j+=len){
                if(ve[j]!=-1&&tmpmp[ve[j]]){
                    tmpmp[ve[j]]--;
                    isExist[ve[j]] = true;
                    tmpnum++;
                } else{
                    break;
                }
            }
            bool flag = false;
            for(auto it:tmpmp){
                if(it.second!=0){
                    flag = true;
                }
            }
            if(!flag&&tmpnum){
                res.push_back(i);

            }
        }
        return res;

        }
    };