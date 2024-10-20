class Solution {
public:
    bool isOperator(char c){
        return c == '|' || c == '&' || c == '!';
    }
    
    char evaluate(vector<char> &vec, char op){
        if(op == '!'){
            if(vec[0] == 'f') return 't';
            return 'f';
        }
        
        if(op == '|'){
            for(auto c: vec){
                if(c == 't') return 't';
            }
            return 'f';
        }
        
        for(auto c: vec){
            if(c == 'f') return 'f';
        }
        return 't';
    }
    
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.length();
        
        for(int i = 0; i < n; i++){
            char c = expression[i];
            
            if(c == ','){
                continue;
            }
            else if(c == ')'){
                vector<char> vec;
                while(!st.empty() && st.top() != '('){
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                cout<<op<<"\t";
                st.pop();
                char res = evaluate(vec, op);
                st.push(res);
            }
            else{
                st.push(c);
            }
        }
        
        return st.top() == 't' ? true : false;
    }
};