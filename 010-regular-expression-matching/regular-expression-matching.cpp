class Solution {
public:
    bool isMatch(string s, string p) {
         if(s.empty()&&p.empty()){
            return true;
        }
        bool res = false;
        if(p.length()>=2&&p[1]=='*'){
            if(!s.empty()&&(s[0]==p[0]||p[0]=='.')){
                res = res|isMatch(s.substr(1,s.length()-1),p);
            }
            res = res|isMatch(s,p.substr(2,p.length()-2));
        }else{
            if(!s.empty()&&(s[0]==p[0]||p[0]=='.')){
                res = res|isMatch(s.substr(1,s.length()-1),p.substr(1,p.length()-1));
            } else{
                res = res|false;
            }
        }
        return res;

    
        
    }
};