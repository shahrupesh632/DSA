class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(char ch:expression){
            if(ch == ',' || ch == '(') continue;

            else if(ch == ')'){
                bool hasTrue = false, hasFalse = false;
                while(st.top()!= '!' && st.top() != '&' && st.top()!= '|'){
                    if(st.top() == 'f') hasFalse = true;
                    else
                        hasTrue = true;
                    st.pop();
                }
                char result;
                if(st.top() == '!'){
                    result = hasTrue ? 'f' : 't';
                }
                else if(st.top() == '&'){
                    result = hasFalse ? 'f' : 't';
                }
                else{
                    result = hasTrue ? 't' : 'f';
                }
                st.pop();
                st.push(result);
            }
            else{
                st.push(ch);
            }
        }

        return st.top() == 't' ? true : false;
    }
};
