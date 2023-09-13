class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room, vector<bool>& vis){
        vis[room]= true;
        for(auto x:rooms[room]){
            if(!vis[x]){
                dfs(rooms, x, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        dfs(rooms, 0, vis); 
        for(auto x : vis){
            if(!x){
                return false;
            }
        }  
        return true;
    }
};

//Time: O(N+E), N=no. of rooms(vertexes), E=no. of keys (edges)
//Space: O(N)
