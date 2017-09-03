class Solution {
public:
    int prefix_up[4] = {0x7f, 0xdf, 0xef, 0xf7};
    int prefix_down[4] = {0x00, 0xc0, 0xe0, 0xf0};
    int common_up = 0xbf;
    int common_down = 0x80;
    bool validUtf8(vector<int> &data) {
        for(int i = 0;i<data.size();i++){
            int type = get_type(data[i]);
            if(type==0){
                return false;
            }
            for(int j=1;j<type;j++){
                if((i+j)>=data.size()||!(data[i+j]<=common_up&&data[i+j]>=common_down)){
                    return false;
                }
            }
            i+=type-1;
        }
        return true;
    }
    int get_type(int v){
        for(int i = 0;i<4;i++){
            if(v>=prefix_down[i]&&v<=prefix_up[i]){
                return i+1;
            }
        }
        return 0;
    }

};