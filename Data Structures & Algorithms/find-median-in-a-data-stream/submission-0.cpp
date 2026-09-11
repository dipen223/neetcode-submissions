class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    priority_queue<int>maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
       if(!minHeap.empty() &&  maxHeap.top() > minHeap.top()){
          minHeap.push(maxHeap.top());
          maxHeap.pop();
       }

       if(minHeap.size() > maxHeap.size()+1){
        maxHeap.push(minHeap.top());
        minHeap.pop();
       }
       if(maxHeap.size() > minHeap.size()+1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
       }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }else{
            return minHeap.top();
        }
    }
};

