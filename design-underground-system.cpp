class UndergroundSystem {
    map<int, pair<string, int>> checkInMap;
    map<pair<string, string>, pair<double, int>> stationToTimeMap;

   public:
    UndergroundSystem() {
        checkInMap.clear();
        stationToTimeMap.clear();
    }

    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        pair<string, int> p1 = checkInMap[id];
        checkInMap.erase(id);
        pair<string, string> stationPair = make_pair(p1.first, stationName);
        stationToTimeMap[stationPair].first += (double)(t - p1.second);
        stationToTimeMap[stationPair].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        pair<string, string> stations = make_pair(startStation, endStation);
        return (stationToTimeMap[stations].first / stationToTimeMap[stations].second);
    }
};