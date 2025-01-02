#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        queue<vector<int>> queue;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) {
                    queue.push({r,c});
                }
            }
        }

        if (queue.size() > 0) {
            count = bfs(grid, queue);
        }

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    return -1;
                }
            }
        }

        return count; 
    }

private:
    int bfs(vector<vector<int>>& grid, queue<vector<int>>& queue) {
        int count = 0;

        while (queue.size() > 0) {
            int queue_size = queue.size();
            int fresh_orange_sighted = false;
            for (int i = 0; i < queue_size; i++) {
                vector<int> cell = queue.front();
                int r = cell.front();
                int c = cell.back();
                queue.pop();

                vector<vector<int>> adjacents = {{1,0}, {0,1}, {-1,0}, {0,-1}};

                for (vector<int> dir : adjacents) {
                    int dr = r + dir.front();
                    int dc = c + dir.back();

                    if (dr < grid.size() && dc < grid[0].size() && dr >= 0 && dc >= 0) {
                        if (grid[dr][dc] == 1) {
                            queue.push({dr,dc});
                            grid[dr][dc] = 0;
                            fresh_orange_sighted = true;
                        }
                    }
                }
            }

            if (fresh_orange_sighted) {
                count++;
            }
        }

        return count;
    }
};