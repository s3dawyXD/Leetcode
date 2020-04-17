class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = shift.size();
        int left = 0 , right = 0;
        for(int i =0;i<n;i++)
        {
            if(shift[i][0]== 1 ) right+=shift[i][1];
            if(shift[i][0]== 0 ) left +=shift[i][1];
        }
        bool dir = (right>left)? 1 : 0 ; // 1 for right 0 for left
        int moves = abs(right-left) ;
        for(int i =0;i<moves;i++)
        {
            if(dir)
            {
                s.insert(0,&s.back());
                s.pop_back();
            }
            else
            {
                s+=s[0];
                s.erase(0,1);
            }
        }
        return s ;
        
    }
};