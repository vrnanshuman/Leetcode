class UndergroundSystem {
    struct Stat {
        double sum;
        int count;
    };
    struct Customer {
        int id;
        string checkInStation;
        int t;
    };
    unordered_map<string, Stat> trips;
    unordered_map<int, Customer> checkInMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap.insert({id, Customer{id, stationName,t}});
    }
    
    void checkOut(int id, string stationName, int t) {
        auto customer = checkInMap[id];
        string key = customer.checkInStation + "-" + stationName;
        if(trips.find(key)!=trips.end()) {
            trips[key].sum += (double)(t - customer.t);
            trips[key].count += 1;
        } else {
            trips[key] = Stat{(double)(t-customer.t), 1};
        }
        checkInMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "-" + endStation;
        return trips[key].sum/trips[key].count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */