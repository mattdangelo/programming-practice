class UndergroundSystem {
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            return h1 ^ h2;  
        }
    };

    std::unordered_map<std::pair<std::string, std::string>, std::pair<int, int>, pair_hash> averages;
    std::unordered_map<int, std::pair<int, std::string>> active_trips;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        active_trips[id] = std::make_pair(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto key = std::make_pair(active_trips[id].second, stationName);

        auto start = active_trips[id];

        if (averages.count(key) > 0) {
            averages[key] = std::make_pair((averages[key].first + (t - start.first)), averages[key].second + 1);
        }
        else {
            averages[key] = std::make_pair(t - start.first, 1);
        }
        
        active_trips.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto avg = averages[std::make_pair(startStation, endStation)];
        return (avg.first + 0.0) / avg.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */