class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> storage;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = storage.find(key);
        if(it == storage.end()){
            return "";
        }
        else{
            const auto& vec = it->second;
            string res = "";
            if(timestamp < vec[0].first) return res;
            int l = 0;
            int r = vec.size() - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(vec[mid].first <= timestamp){
                    res = vec[mid].second;
                    if(vec[mid].first == timestamp) return res;
                    else l = mid + 1;
                }
                else r = mid - 1;
            }
            return res;
        }
    }
};
