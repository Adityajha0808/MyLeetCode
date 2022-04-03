class Solution {
public:
    int hourDiff, minDiff;
    int removeColon(string s) {
        s.replace(2, 1, "");
        return stoi(s);
    }
    void diff(string s1, string s2) {
        int time1 = removeColon(s1), time2 = removeColon(s2);
        hourDiff = time2 / 100 - time1 / 100 - 1;
        minDiff = time2 % 100 + (60 - time1 % 100);
        if(minDiff >= 60) {
            hourDiff++;
            minDiff = minDiff - 60;
        }
    }
    int convertTime(string curr, string corr) {
        diff(curr, corr);
        int res = hourDiff;
        res += minDiff/15;
        minDiff %= 15;
        if(minDiff == 0) return res;
        res += minDiff/5;
        minDiff %= 5;
        if(minDiff == 0) return res;
        res += minDiff;
        return res;
    }
};