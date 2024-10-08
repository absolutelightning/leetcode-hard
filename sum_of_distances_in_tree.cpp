//
// Created by Ashesh Vidyut on 08/10/24.
//

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <climits>
#include <algorithm>
#include <utility>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <cmath>

#define ll long long int

using namespace std;

const int MAX = (int)1e5 + 7;
const int MOD = (int)1e9 + 7;

int height[MAX];
int subtree[MAX];
int dp[MAX];

class Solution {
public:
    void compute_height_subtree(int v, vector<int> g[], vector<bool>& vis) {
        subtree[v]++;
        vis[v] = true;
        for (int ad : g[v]) {
            if (!vis[ad]) {
                height[ad] = 1 + height[v];
                compute_height_subtree(ad, g, vis);
                subtree[v] += subtree[ad];
            }
        }
    }
    /*
     * Example we move from root 0 to next child - we move one step closer to all nodes below
     * So we remove one edge from each child in subtree below
     * But we need to increase one edge from each node in the (n - subtree[adj]) space of nodes
     * because we move one step further away from them.
     * Recurrence -
     * dp[ch] = dp[par] - subtree[ch] + n - subtree[ch]
     */
    void rec(int v, vector<int> g[], vector<bool> & vis, int n) {
        vis[v] = true;
        for (int ad : g[v]) {
            if (!vis[ad]) {
                dp[ad] = dp[v] + (n - (2 * (subtree[ad])));
                rec(ad, g, vis, n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int> >& edges) {
        fill(height, height + n, 0);
        fill(subtree, subtree + n, 0);
        fill(dp, dp + n, 0);
        vector<int> graph[n];
        for (int i = 0; i < n - 1; ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        fill(vis.begin(), vis.end(), false);
        compute_height_subtree(0, graph, vis);
        for (int i = 0; i < n; ++i) {
            dp[0] += height[i];
        }
        fill(vis.begin(), vis.end(), false);
        rec(0, graph, vis, n);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(dp[i]);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    auto solution = new Solution();
    int n = 6;
    vector<vector<int>> edge = { {0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    vector<int> res = solution->sumOfDistancesInTree(n, edge);
    for (auto v : res) {
        cout << v << endl;
    }
    delete(solution);
    return 0;
}


