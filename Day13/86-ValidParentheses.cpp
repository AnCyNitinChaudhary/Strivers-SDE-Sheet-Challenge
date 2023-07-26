bool isValidParenthesis(string s)
{
    stack<char>st;
    // st.push(s[0]);
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'||s[i]=='('||s[i]=='[')st.push(s[i]);
        else if(s[i]=='}'){
            if(st.empty()||st.top()!='{')return false;
            else st.pop();
        }
        else if(s[i]==')'){
            if(st.empty()||st.top()!='(')return false;
            else st.pop();
        }
        else if(s[i]==']'){
            if(st.empty()||st.top()!='[')return false;
            else st.pop();
        }
    }
    return st.empty();
    // Write your code here.
}
