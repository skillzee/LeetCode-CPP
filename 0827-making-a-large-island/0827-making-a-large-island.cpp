class Solution {
public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
	// dfs method
	const int m = grid.size(), n = grid[0].size();
	int result = 0;
	bool has_zero = false;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) continue;
			grid[i][j] = 1;

			std::vector<std::vector<bool>> visited(m, std::vector<bool>(n));
			result = std::max(result, helper(grid, i, j, visited));
			if (result == m * n) return result;

			grid[i][j] = 0;
			has_zero = true;
		}
	}
	return has_zero ? result : m * n;
}
int helper(std::vector<std::vector<int>>& grid, int i, int j, 
		   std::vector<std::vector<bool>>& visited) {
	const int m = grid.size(), n = grid[0].size();
	if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) return 0;
	visited[i][j] = true;
	return 1 + helper(grid, i - 1, j, visited) 
			 + helper(grid, i + 1, j, visited) 
			 + helper(grid, i, j - 1, visited) 
			 + helper(grid, i, j + 1, visited);
}
    
};