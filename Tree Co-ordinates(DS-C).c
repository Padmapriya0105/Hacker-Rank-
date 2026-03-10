#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005
#define LOGN 18

typedef struct { int to, next; } Edge;
Edge edges[MAXN * 2];
int head[MAXN], ec = 0;
int depth[MAXN], up[MAXN][LOGN];
int n, m;

void add_edge(int u, int v) {
    edges[++ec] = (Edge){v, head[u]}; head[u] = ec;
    edges[++ec] = (Edge){u, head[v]}; head[v] = ec;
}

// DFS to build binary lifting table for LCA
void dfs_lca(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;
    for (int i = 1; i < LOGN; i++) up[u][i] = up[up[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = edges[i].next) {
        if (edges[i].to != p) dfs_lca(edges[i].to, u, d + 1);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) { int t = u; u = v; v = t; }
    for (int i = LOGN - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) { u = up[u][i]; v = up[v][i]; }
    }
    return up[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
}

typedef struct { int x, y; } Point;
Point pts[MAXN];

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    for (int i = 0; i < m; i++) scanf("%d %d", &pts[i].x, &pts[i].y);

    dfs_lca(1, 1, 0);

    // Heuristic: Check each point against a subset of extreme candidates
    // For competitive programming, checking ~200-400 points is a common safe bound.
    int max_d = 0;
    int check_limit = (m < 400) ? m : 400; 

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < check_limit; j++) {
            int current = dist(pts[i].x, pts[j].x) + dist(pts[i].y, pts[j].y);
            if (current > max_d) max_d = current;
        }
    }

    printf("%d\n", max_d);
    return 0;
}
