class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        int n = 0;
        float time = 0;
        for(int i = 0; i < cars.size(); i++){
            float curr_time = float(target - cars[i].first) / cars[i].second;
            if(time >= curr_time){
                continue;
            }
            else{
                time = curr_time;
                n++;
            }
        }
        return n;
    }
};
