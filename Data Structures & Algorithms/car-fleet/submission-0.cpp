class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;

        for(int i = 0; i < position.size(); i++) {
    cars.push_back({position[i], speed[i]});
}

        stack<double>st;
        sort(cars.rbegin(),cars.rend());

        for(auto &it :cars){
            int pos = it.first;
            int speed = it.second;

            double time = (double)(target - pos) / speed;
            

            if(!st.empty() && time <= st.top()){
                continue;
            }

            st.push(time);
            
        }

        return (int)st.size();

    }
};


