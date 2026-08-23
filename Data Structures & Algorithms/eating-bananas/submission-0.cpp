class Solution {
public:
    bool canEatInTime(vector<int>& piles, int h,int speed){
        int hours = 0;
        for(int pile:piles){
            hours += (int)ceil((double) pile/speed);
        }


        return hours <= h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;  //minSpeed
        int right = *max_element(piles.begin(),piles.end());  //maxSPeed;

        while(left < right){
            int mid = left + (right-left)/2;

            if(canEatInTime(piles,h,mid)){

                right = mid;

            }else{
                      left = mid+1;
            }
        }

        return left;
        
    }
};

