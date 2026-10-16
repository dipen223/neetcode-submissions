class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int>star;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }else if(!star.empty()){
                    star.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open.empty() && !star.empty()){
            int first = open.top();
            int second = star.top();
            if(first < second){
                open.pop();
                star.pop();
            }else{
                return false;
            }
       
            
        }

        return open.empty();
    }
};

