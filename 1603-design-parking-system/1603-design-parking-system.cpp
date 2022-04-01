class ParkingSystem {
public:
    int big, med, sml;
    ParkingSystem(int b, int m, int s) {
        big = b; med = m; sml = s;
    }
    
    bool addCar(int c) {
        if(c == 1) {
            if(big) {
                big--;
                return true;
            } else
                return false;
        } else if(c == 2) {
            if(med) {
                med--;
                return true;
            } else
                return false;
        } else {
            if(sml) {
                sml--;
                return true;
            } else
                return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */