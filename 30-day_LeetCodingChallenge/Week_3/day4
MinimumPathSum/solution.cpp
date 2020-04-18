class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i =0,j=0;
        int const row = grid.size(); int const colm = grid[0].size();
        int ans = 0;
        int sum[row][colm];
        //memset(sum,0,sizeof(int)*row*colm);
        for(i=0;i<row;i++)
        {
            for(j=0;j<colm;j++)
            {
                sum[i][j]=grid[i][j];
                if(i>0&&j>0) sum[i][j]+=min(sum[i][j-1],sum[i-1][j]);
                else if(j>0) sum[i][j]+=sum[i][j-1];
                else if(i>0) sum[i][j]+=sum[i-1][j];
                //cout<<sum[i][j]<<" ";
            }
            //cout<<endl;
        }
        return sum[row-1][colm-1];
    }
    int min(int i , int j)
    {
        return (i>j)? j:i ;
    }
    
};