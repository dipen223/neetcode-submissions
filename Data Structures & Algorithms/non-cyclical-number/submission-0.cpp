class Solution {
public:
    bool isHappy(int n) {
        set<int>nums;
        int sum  = 0;
        while(n > 0){
            sum += (n%10)*(n%10); 
            n/=10;
            if(sum == 1 && n==0){
                return true;
            }else if(n==0){
                if(nums.count(sum)){
                    return false;
                }else{
                     nums.insert(sum);
                     n = sum;
                     sum=0;

                }
            }

        }
        return false;
    }
};
