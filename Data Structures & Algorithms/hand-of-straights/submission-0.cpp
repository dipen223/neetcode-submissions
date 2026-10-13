class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int,int>m;
        for(int card:hand){
            m[card]++;
        }

        while(!m.empty()){
            int start = m.begin()->first;
            for(int i=0; i<groupSize;i++){
                int card = start+i;
                if(m.find(card) == m.end()) return false;
                m[card]--;
                if(m[card] == 0) m.erase(card);
            }
        }

        return true;
    }
};

