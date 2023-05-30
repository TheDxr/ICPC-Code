class Solution {
  public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        vector<int> pos{ 0, 0 };
        map<vector<int>, bool> route;
        route.emplace(pair{ pos, true });
        for(int i = 0; i < command.size(); i++) {
            if(pos[0] > x || pos[1] > y) break;
            if(command[i] == 'U') {
                pos[1]++;
            }
            if(command[i] == 'R') {
                pos[0]++;
            }
            route.emplace(pair{ pos, true });
        }
        int n = 0;
        for(vector<int> obstacle : obstacles) {
            if(obstacle[0] > x || obstacle[1] > y)continue;
            n = min(obstacle[0] / pos[0],obstacle[1] / pos[1]);
            if(route[vector{ obstacle[0] - n*pos[0], obstacle[1] - n*pos[1] }]) {
                return false;
            }
        }
        n = min(x / pos[0],y / pos[1]);
        return route[vector{ x - n*pos[0], y - n*pos[1]}];
    }
};