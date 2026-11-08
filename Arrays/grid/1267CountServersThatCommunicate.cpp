class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();


        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(grid[i][j]==0) continue;

                bool found=false;

                for(int col=0; col<m; col++){
                    if(col==j) continue;

                    if(grid[i][col]){
                      found=true;
                      break;
                    }
                }

                if(found){
                    ans++;
                    continue;
                }

                for(int row=0; row<n; row++){
                    if(row==i) continue;

                    if(grid[row][j]){
                        found=true;
                        break;
                    }
                }

                if(found){
                    ans++;
                }


            }
        }


        return ans;
    }
};