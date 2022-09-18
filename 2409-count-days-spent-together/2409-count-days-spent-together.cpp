class Solution {
public:
    vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month(string s) {
        if(s[0] == '0')
            return (s[1] - '0');
        else
            return stoi(s);
    }
    int date(string s) {
        if(s[0] == '0')
            return (s[1] - '0');
        else
            return stoi(s);
    }      
    int calcDays(int n) {
        int res = 0;
        for(int i=0; i<n; ++i) {
            res += months[i];
        }
        return res;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArr = calcDays(month(arriveAlice.substr(0, 2))) + date(arriveAlice.substr(3, 2));
        int aliceLea = calcDays(month(leaveAlice.substr(0, 2))) + date(leaveAlice.substr(3, 2));
        int bobArr = calcDays(month(arriveBob.substr(0, 2))) + date(arriveBob.substr(3, 2));
        int bobLea = calcDays(month(leaveBob.substr(0, 2))) + date(leaveBob.substr(3, 2));
        if(aliceArr <= bobArr and bobArr <= bobLea and bobLea <= aliceLea)
            return bobLea - bobArr + 1;
        else if(bobArr <= aliceArr and aliceArr <= aliceLea and aliceLea <= bobLea)
            return aliceLea - aliceArr + 1;
        else if(aliceArr <= bobArr and bobArr <= aliceLea)
            return aliceLea - bobArr + 1;
        else if(bobArr <= aliceArr and aliceArr <= bobLea)
            return bobLea - aliceArr + 1;
        return 0;
    }
};