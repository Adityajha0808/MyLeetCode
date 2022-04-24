class UndergroundSystem {
public:
    map<int, pair<string,int>> mp;
    map<string, map<string, pair<int,int>>> mp2;
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(mp2[mp[id].first].count(stationName) <= 0) {
             mp2[mp[id].first][stationName] = {t - mp[id].second, 1};
        } else {
            mp2[mp[id].first][stationName].first += t - mp[id].second;
            mp2[mp[id].first][stationName].second += 1;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double x = mp2[startStation][endStation].first, y = mp2[startStation][endStation].second;
        return x/y;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */