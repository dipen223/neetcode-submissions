class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1) return false;
        stack<char>st;
        for(char ch:s){
          if(ch == '{' || ch=='[' || ch=='('){
            st.push(ch);

          }else{
            if(st.size() > 0){
                if(ch == ')' && st.top() == '('){
                    st.pop();
                }else if(ch =='}' && st.top() == '{'){
                    st.pop();
                }else if(ch == ']' && st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
          }
                
          
        }

        if(!st.empty()){
            return false;
        }else{
            return true;
        }
    }
};


