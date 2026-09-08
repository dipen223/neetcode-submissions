class KthLargest {
    int k;
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};

