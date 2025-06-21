
class DisjointSet {
    std::vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node != parent[node]) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unionbs(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    }

    int getSize(int u) { return size[find(u)]; }
};

class Solution {
public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int index1 = i * n + j;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            int index2 = ni * n + nj;
                            ds.unionbs(index1, index2);
                        }
                    }
                }
            }
        }
        int largest = 0;
        for (int i = 0; i < n * n; ++i) {
            if (grid[i / n][i % n] == 1) {
                largest = max(largest, ds.getSize(i));
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int currentSize = 1;
                    std::set<int> st;

                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            int root = ds.find(ni * n + nj);
                            if (st.insert(root).second) {
                                currentSize += ds.getSize(root);
                            }
                        }
                    }

                    largest = max(largest, currentSize);
                }
            }
        }

        return largest == 0 ? n * n : largest;
    }
};