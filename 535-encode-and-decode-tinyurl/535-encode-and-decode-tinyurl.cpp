class Solution {
public:
    unordered_map<string, string> mp;
    string encode(string longUrl) {
        string res = "http://tinyurl.com/";
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<std::mt19937::result_type> dist(0,9);
        res.push_back(dist(rng));
        res.push_back((char)(res.back() + 'a'));
        res.push_back(dist(rng));
        res.push_back((char)(res.back() + 'a'));
        res.push_back(dist(rng));
        res.push_back((char)(res.back() + 'a'));
        res.push_back(dist(rng));
        mp[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));