class Solution {
public:
    int totalWords(string str) {
        stringstream s(str);
        string word;
        int count = 0;
        while (s >> word) count++;
        return count;
    }
    string largestWordCount(vector<string>& m, vector<string>& s) {
        int n = m.size(), maxm = -1;
        unordered_map<string,int> mp;
        for(int i=0; i<n; ++i)
            mp[s[i]] += totalWords(m[i]);
        for(auto i: mp)
            maxm = max(maxm, i.second);
        vector<string> soo;
        for(auto i: mp) 
            if(i.second == maxm)
                soo.push_back(i.first);
        sort(soo.begin(), soo.end());
        return soo.back();
    }
};