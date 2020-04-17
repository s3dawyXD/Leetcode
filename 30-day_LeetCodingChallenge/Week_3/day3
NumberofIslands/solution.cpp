class Solution {
public:
    
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        vector<vector<char>> map = grid ;
        for(int i =0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(map[i][j]== '1'){
                 count+=1;
                 colbfs(map,i,j);
                    
                }
            }
            
        }
            
        return count;
        
    }
    void colbfs(vector<vector<char>> &grid,int i ,int j)
    {
        if(i < 0 || i>=grid.size() || j<0 || j>=grid[i].size()||grid[i][j] == '0') return ;
        grid[i][j] = '0';
        colbfs(grid,i,j+1);
        colbfs(grid,i,j-1);
        colbfs(grid,i+1,j);
        colbfs(grid,i-1,j);
        
    }
    
};