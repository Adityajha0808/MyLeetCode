class Solution {
public:
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& a) {
        set<string> st;
        for(auto i: a) {
            string s = "";
            for(auto j: i) {
                s += morse[j - 'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};