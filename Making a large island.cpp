

class Solution {
    
    int moves[4][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
        
    vector<vector<int>> islandIndex;
    unordered_map<int, int> islandArea;

    
    bool isValid(int R, int C, int r, int c) 
    {
        if(r < 0 || r >= R) return false;
        if(c < 0 || c >= C) return false;
        return true;
    }

    int bfs(vector<vector<int>>& grid, int r, int c, int index) 
    {
        queue<pair<int, int>> line;
        line.push({r, c});
        
        int totalNodes = 0; 

        while(!line.empty()) {

            pair<int, int> cur = line.front();
            line.pop();

            //inspection begins
            if(!isValid(grid.size(), grid[0].size(), cur.first, cur.second) || !grid[cur.first][cur.second])
                continue; 


            if(islandIndex[cur.first][cur.second] == index)
                continue;
            //inspection ends


            totalNodes++;
            if(index > -1)  islandIndex[cur.first][cur.second] = index;
    
            for(int k=0; k<4; k++) {
                line.push({cur.first + moves[k][0], cur.second + moves[k][1]});
            }
        }

        return totalNodes;
    }

public:
    

    //Complexity N^2
    int largestIsland(vector<vector<int>>& grid) 
    {

        islandIndex = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = 0;
        int index = 0;
        
        
        //For ones (bfs call)
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {

                if(!grid[i][j])
                    continue;
                
                int temp =  index; //index for current island

                int currentArea;
                if(islandIndex[i][j] > -1) {
                    currentArea = islandArea[islandIndex[i][j]];
                } else {
                    currentArea = bfs(grid, i, j, temp);
                }

                if(islandArea.find(temp) == islandArea.end())
                { 
                    islandArea[temp] = currentArea;
                    index++;
                }
                
                ans = max(ans, currentArea);
           }
        }

        
        
        //For zeros (no bfs call)
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                
                if(grid[i][j])
                    continue;
                
                int currentArea = 1;
                unordered_set<int> seenIndex;
                
                for(int k=0; k<4; k++) {
                    int nextR = i + moves[k][0];
                    int nextC = j + moves[k][1];
                    
                    if(isValid(grid.size(), grid[0].size(), nextR, nextC) && grid[nextR][nextC]) {
                        if(seenIndex.find(islandIndex[nextR][nextC]) == seenIndex.end()) {
                            currentArea += islandArea[islandIndex[nextR][nextC]];
                            seenIndex.insert(islandIndex[nextR][nextC]);
                        }
                    }
                }
                
                ans = max(ans, currentArea);
            }
        }
        return ans;
    }
};
