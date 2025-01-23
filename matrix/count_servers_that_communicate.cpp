#include <vector>
using namespace std;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> row(grid.size(), 0);
        vector<int> col(grid[0].size(), 0);
        int servers = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                row[r] = (grid[r][c] == 1) ? row[r] + 1 : row[r];
                col[c] = (grid[r][c] == 1) ? col[c] + 1 : col[c];
            }
        }

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                servers = (grid[r][c] == 1 && max(row[r], col[c]) > 1) ? servers + 1 : servers;
            }
        }

        return servers;
    }
};