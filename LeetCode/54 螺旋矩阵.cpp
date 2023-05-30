class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans = vector<int>();
        vector<vector<int>> direction{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        short d = 0;
        int i = 0, j = 0;
        while(true) {
            cout_matrix(matrix);
            ans.emplace_back(matrix[i][j]);
            matrix[i][j] = -1e5;
            if(ans.size() == matrix.size() * matrix[0].size()) break;
            if(i + direction[d][0] < 0 || i + direction[d][0] >= matrix.size()
               || j + direction[d][1] < 0 || j + direction[d][1] >= matrix[0].size()
               || matrix[i + direction[d][0]][j + direction[d][1]] == -1e5) {
                d = (d + 1) % 4;
            }
            i = i + direction[d][0];
            j = j + direction[d][1];
        }
        return ans;
    }
};