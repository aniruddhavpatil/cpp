class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int maxSize;
    int currSum = 0;
    
    MovingAverage(int size) {
        maxSize = size;
    }
    
    double next(int val) {
        if(q.empty()){
            q.push(val);
            currSum += val;
            return val;
        }
        if(q.size() == maxSize){
            currSum -= q.front(); q.pop();
        }
        currSum += val;
        q.push(val);
        return 1.0 * currSum / q.size();
    }
};