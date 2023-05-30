class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans{};
        vector<vector<int>> edges(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> degree_queue;
        for(vector<int> prerequisite : prerequisites) {
            degree[prerequisite[0]]++;
            edges[prerequisite[1]].emplace_back(prerequisite[0]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(degree[i] == 0) {
                degree_queue.emplace(i);
            }
        }

        while(!degree_queue.empty()) {
            int now = degree_queue.front();
            degree_queue.pop();
            ans.emplace_back(now);
            for(int edge : edges[now]) {
                degree[edge]--;
                if(degree[edge] == 0){
                    degree_queue.emplace(edge);
                }
            }
        }
        if(ans.size() < numCourses)return {};
        return ans;
    }
};