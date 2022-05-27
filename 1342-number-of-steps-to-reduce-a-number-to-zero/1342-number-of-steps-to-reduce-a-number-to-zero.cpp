class Solution {
public:
    int numberOfSteps(int n) {
        int steps = 0;
        while(n) {
            n = (n&1 ? n-1 : n/2);
            steps++;
        }
        return steps;
    }
};