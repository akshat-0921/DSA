class Solution {
public:
    long long maxArea(vector<vector<int>>& pts) {
        int n = pts.size(), xMin = INT_MAX, xMax = INT_MIN, yMin = INT_MAX, yMax = INT_MIN;
        unordered_map<int,int> xMinY, xMaxY, yMinX, yMaxX, yCnt, xCnt;
        
        for (auto &p : pts) {
            int x = p[0], y = p[1];
            xMin = min(xMin, x);
            xMax = max(xMax, x);
            yMin = min(yMin, y);
            yMax = max(yMax, y);
            
            if (!yCnt[y]++) {
                xMinY[y] = xMaxY[y] = x;
            } else {
                xMinY[y] = min(xMinY[y], x);
                xMaxY[y] = max(xMaxY[y], x);
            }
            
            if (!xCnt[x]++) {
                yMinX[x] = yMaxX[x] = y;
            } else {
                yMinX[x] = min(yMinX[x], y);
                yMaxX[x] = max(yMaxX[x], y);
            }
        }
        
        long long res = 0;
        
        for (auto &p : yCnt) {
            int y = p.first;
            if (p.second < 2) continue;
            long long w = (long long)xMaxY[y] - xMinY[y];
            if (w <= 0) continue;
            long long h = max((long long)yMax - y, (long long)y - yMin);
            if (h > 0) res = max(res, w * h);
        }
        
        for (auto &p : xCnt) {
            int x = p.first;
            if (p.second < 2) continue;
            long long h = (long long)yMaxX[x] - yMinX[x];
            if (h <= 0) continue;
            long long w = max((long long)xMax - x, (long long)x - xMin);
            if (w > 0) res = max(res, w * h);
        }
        
        return res > 0 ? res : -1;
    }
};