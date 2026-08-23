class TimeMap {
   public:
    struct Entry {
        string val;
        int timestamp;
        
    };
    unordered_map<string, vector<Entry>> map;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
         map[key].push_back({value, timestamp}); }

    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) return "";
        auto& entries = map[key];
        int lo = 0, hi = entries.size();

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if (entries[mid].timestamp <= timestamp) lo = mid + 1;
            else hi = mid;
        }

        if (lo == 0) return "";
        return entries[lo-1].val;
 

           
    }
};
