using ll = long long;
class ATM {
public:
    vector<ll> curr{0,0,0,0,0}, den{20,50,100,200,500};
    ATM() {}
    void deposit(vector<int> a) {
        for(int i=0; i<5; ++i) curr[i] += a[i];
    }
    
    vector<int> withdraw(int n) {
        vector<int> money(5,0);
        for(int i=4; i>=0; --i) {
            money[i] = min(curr[i], n/den[i]);
            n -= money[i] * den[i];
        }
        if(n) return {-1};
        for(int i=0; i<5; ++i) curr[i] -= money[i];
        return money;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */