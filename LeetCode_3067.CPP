class Solution {
public:
    int s;

    int dfs(vector<vector<vector<int>>>& gf, int start, vector<int>& visit, int dist) {
        int sum = 0;
        visit[start] = 1;
        for (const auto& e : gf[start]) {
            int node = e[0];
            int w = e[1];
            if (!visit[node]) {
                visit[node] = 1;
                sum += dfs(gf, node, visit, dist + w);
            }
        }
        if (dist != 0 && dist % s == 0)
            sum++;
        return sum;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int Speed) {
        s = Speed;
        int n = 0;
        for (const auto& v : edges) {
            n = max(n, max(v[0], v[1]));
        }
        vector<vector<vector<int>>> gf(n + 1);
        for (auto& v : edges) {
            int a = v[0];
            int b = v[1];
            int c = v[2];
            gf[a].push_back({b, c});
            gf[b].push_back({a, c});
        }
        vector<int> result(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int ans = 0;
            int sum = 0;
            vector<int> visit(n + 1, 0);
            visit[i] = 1;
            for (const auto& e : gf[i]) {
                int c = dfs(gf, e[0], visit, e[1]);
                ans += (sum * c);
                sum += c;
            }
            result[i] = ans;
        }
        return result;
    }
};
