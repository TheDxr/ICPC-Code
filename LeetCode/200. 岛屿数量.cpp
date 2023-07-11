// 方法一：BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        height = grid.size();
        width = grid[0].size();
        visit.resize(height,vector<bool>(width, false));
        int ans = 0;
        for(int i = 0;i < height;i++){
            for(int j = 0;j < width;j++){
                if(!visit[i][j] && grid[i][j] == '1'){
                    ans+=1;
                    bfs(Vector2(i,j), grid);
                }
            }
        }
        return ans;
    }
private:
    int height{};
    int width{};
    vector<vector<bool>> visit;
    struct Vector2{
        int x;
        int y;
        Vector2(int x,int y):x(x),y(y){}
    };
    array<Vector2,4> direction = {Vector2(-1,0),{1,0},{0,-1},{0,1}};
    //int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(Vector2 begin, vector<vector<char>>& grid){
        queue<Vector2> q;
        q.push(begin);
        visit[begin.x][begin.y] = true;
        while(!q.empty()) {
            Vector2 now = q.front();
            q.pop();
            for(Vector2 dir : direction){
                Vector2 next = Vector2(now.x+dir.x,now.y+dir.y);
                if(next.x >= 0 && next.x < height && next.y >= 0 && next.y < width 
                   && grid[next.x][next.y] != '0' && !visit[next.x][next.y]){
                    q.push(next);
                    visit[next.x][next.y] = true;
                }
            }
        }
    }
};
// 方法二：强连通分量
