class Solution {
public:
    int reverse(int x) {
        int x1 = abs(x);
        int reversed=0;

        while(x1 > 0){
            int lastDigit = x1 % 10;
            if(reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && lastDigit > 7)) return 0;
            reversed = reversed* 10 +  lastDigit;
            x1/=10;
        }

        if(x < 0){
            return -reversed;
        }else{
            return reversed;
        }
        
    }
};
