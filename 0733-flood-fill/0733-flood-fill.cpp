using p = pair<int, int>;
vector<p> dirn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> res = image;
        queue<p> q;
        q.push({sr, sc});
        int lala = res[sr][sc];
        res[sr][sc] = color;

        auto check = [&](int a, int b){
            return a >= 0 && b >= 0 && a < res.size() && b < res[0].size() && res[a][b] != color && res[a][b] == lala;
        };

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto &x: dirn){
                if(check(x.first + r, x.second + c)){
                    q.push({x.first + r, x.second + c});
                    res[x.first + r][x.second + c] = color;
                }
            }
        }

        return res;
    }
};