class Solution {
public:
    bool checkValidString(string s) {
        int dp = 0 ;
        int n = s.length();
        for(char ch : s)
        {
            if(ch == '(' || ch =='*')  dp++ ;
            else if (ch == ')') dp--;
            if (dp < 0) return 0;
        }
        dp = 0;
        char c ;
        for(int i = n-1;i>=0;i--)
        {
            c = s[i];
            if(c == ')' || c =='*')  dp++ ;
            else if (c == '(') dp--;
            if (dp < 0) return 0;
        }
        
        
        return 1;
        
    }
};