class Solution {
public:
    bool validUtf8(vector<int>& a) {
        int res = 0;
        for(auto& i: a) {
            if(res) {
                if((i/64) != 0b10)
                    return false;
                res--;
            } else {
	            if(i/32 == 0b110)
                    res = 1;
                else if(i/16 == 0b1110)
                    res = 2;
	            else if(i/8 == 0b11110)
                    res = 3;
                else if(i/128)
                    return false;
            }
        }
        return (res == 0);
    }
};