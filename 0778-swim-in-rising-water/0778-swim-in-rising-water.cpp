class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;

        pq.push({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [t, coord] = pq.top();
            pq.pop();
            int x = coord.first, y = coord.second;

            if (x == n - 1 && y == n - 1)
                return t;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int newTime = max(t, grid[nx][ny]);
                    if (newTime < dis[nx][ny]) {
                        dis[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};
