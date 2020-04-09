class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s,t ;
        int S_n = S.size();int T_n = T.size();
        int i;
        for(i=0;i<S_n;i++)
        {
            if(S[i]=='#'&&s.size())
            {
                s.pop();
                continue;
            }
            if(S[i]=='#') continue;
            s.push(S[i]);
        }
        for(i=0;i<T_n;i++)
        {
            if(T[i]=='#'&&t.size())
            {
                t.pop();
                continue;
            }
            if(T[i]=='#') continue ;
            t.push(T[i]);
        }
        if(s.size()!=t.size())return 0;
        int n = s.size();
        while(n--)
        {
            if(t.top()!=s.top()) return 0;
            t.pop();s.pop();
        }
        return 1;
        
    }
};