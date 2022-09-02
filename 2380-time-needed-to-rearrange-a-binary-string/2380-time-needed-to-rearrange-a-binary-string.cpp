class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zero = 0, time = 0;
        for(auto& i: s) {
            if(i == '0') zero++;
            if(i == '1' and zero)
                time = max(time + 1, zero);
        }
        return time;
    }
};