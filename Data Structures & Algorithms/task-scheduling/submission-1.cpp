class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for (char ch : tasks) mp[ch]++;

        priority_queue<int> pq;  // max-heap of counts only
        for (auto &it : mp) {
            pq.push(it.second);
        }

        int time = 0;
        queue<pair<int,int>> cooldown;  // {count, readyTime}

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                if (cnt - 1 > 0) {
                    cooldown.push({cnt - 1, time + n});
                }
            }

            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};