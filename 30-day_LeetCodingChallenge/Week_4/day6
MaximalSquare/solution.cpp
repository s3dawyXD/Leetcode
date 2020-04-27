class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int i, j;
        int size = 0, ans = 0 ;
        if(matrix.size()==0)return 0;
        int n = matrix.size(), m = matrix[0].size();
        //cout<<m<<endl;
        for(i=0;i<n;i++){
            if(matrix[i][0]=='1'){
                ans =max(ans,1) ;
                //cout<<matrix[i][0]<<", ";
            } 
                
            for(j=0;j<m;j++){
               
                size = 0;
                if(matrix[i][j]=='1'){
                    size++;
                    while(square(matrix,i,j,size)&&size+i<n&&size+j<m){
                        size++;
                    }
                }
                 ans = max(ans,size);
            }
        }
        return ans*ans;
    }
    bool square(vector<vector<char>>& matrix,int i, int j, int size){
        int n = matrix.size(), m = matrix[0].size();
        int limit_i = i+size+1, limit_j = j+size+1;
        int check = 1 ,x;
        for(; i<n && i<limit_i ;i++){
            for(x=j; x<m && x<limit_j ;x++){
                check =  check * (matrix[i][x]-'0');
            }
        }
        return check;
    }
};