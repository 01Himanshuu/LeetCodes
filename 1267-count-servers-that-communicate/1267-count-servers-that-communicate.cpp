#include <vector>

class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        std::vector<int> rowCount(rows, 0);
        std::vector<int> colCount(cols, 0);
        
        // 1. Count servers in each row and column
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        // 2. Count servers that have at least one partner in their row or column
        int communicatingServers = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    if (rowCount[i] > 1 || colCount[j] > 1) {
                        communicatingServers++;
                    }
                }
            }
        }
        
        return communicatingServers;
    }
};