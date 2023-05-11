//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool PossibleToMakePalindrome(string s){
        int N = s.length();
        for(int i = 0 ; i < N / 2 ; i++)
            if(s[i] != '?' && s[N - i - 1] != '?' && s[i] != s[N - i - 1])
                return false;
        return true;
    }
    int minimumSum(string s) {
        if(!PossibleToMakePalindrome(s))
            return -1;
        int N = s.length();
        for(int i = 0 ; i < N / 2 ; i++){
            if(s[i] == '?' && s[N-  i - 1] != '?')
                s[i] = s[N - i - 1];
            else if(s[i] != '?' && s[N - i - 1] == '?')
                s[N - i - 1] = s[i];
        }
        vector<char>NextChar;
        for(int i = 0 ; i < N;){
            if(s[i] != '?')
                NextChar.push_back(s[i++]);
            else{
                if(NextChar.size() >= 1){
                    while(i < N && s[i] == '?'){
                        s[i] = NextChar.back();
                        i++;
                    }
                    NextChar.pop_back();
                }else
                i++;
            }
        }
        NextChar.clear();
        for(int i = N - 1 ; i >= 0;){
            if(s[i] != '?')
                NextChar.push_back(s[i--]);
            else{
                if(NextChar.size() >= 1){
                    while(i >= 0 && s[i] == '?'){
                        s[i] = NextChar.back();
                        i--;
                    }
                    NextChar.pop_back();
                }else
                i--;
            }
        }
        for(int i = 0 ; i < N / 2 ; i++){
            if(s[i] == '?' && s[N-  i - 1] != '?')
                s[i] = s[N - i - 1];
            else if(s[i] != '?' && s[N - i - 1] == '?')
                s[N - i - 1] = s[i];
        }
        for(int i = 0 ; i < N ; i++)
            if(s[i] == '?')
                s[i] = 'a';
       
        int Ans = 0;
        for(int i = 0 ; i < N  - 1; i++){
            int o = s[i] - 'a';
            int l = s[i + 1] - 'a';
            Ans += abs(o - l);
        }
        return Ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends