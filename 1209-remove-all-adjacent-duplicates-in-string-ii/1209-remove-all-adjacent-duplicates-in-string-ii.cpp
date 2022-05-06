class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size(), sz;
        // Let's create a temporary string to do our operations. Shall we?
        string t;
        for(int i=0; i<n; ++i) {
            // Push and push all the string characters till the very end.
            t.push_back(s[i]);
            sz = t.size();
            // Basic algorithm here will be that we push our characters in temporary string. And we check for last k occurences. If all of them are similar characters we delete them. Pretty Straighforwrad aye!
            if(sz >= k) {
                string tmp = t.substr(sz - k);
                // "find_first_not_of" returns index of first unmatched character.
                if(tmp.find_first_not_of(tmp[0]) == string::npos) {
                    // So, if all characters are matched resize our string.
                    int run = k;
                    while(run--) t.pop_back();
                }
            }
        }
        return t;
    }
};
// Takes time n * k and n space.