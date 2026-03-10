import sys
from collections import deque, defaultdict

# Increase recursion depth for deep trees
sys.setrecursionlimit(5000)

def solve():
    n, r = map(int, sys.stdin.readline().split())
    if r == 0:
        print(1)
        return
        
    adj = defaultdict(list)
    for _ in range(n - 1):
        u, v = map(int, sys.stdin.readline().split())
        adj[u].append(v)
        adj[v].append(u)

    def get_subtree(start_node):
        # BFS to find all nodes within radius R
        nodes = []
        distances = {start_node: 0}
        q = deque([start_node])
        while q:
            u = q.popleft()
            nodes.append(u)
            if distances[u] < r:
                for v in adj[u]:
                    if v not in distances:
                        distances[v] = distances[u] + 1
                        q.append(v)
        
        # Build local adjacency for the subtree
        sub_adj = {node: [] for node in nodes}
        node_set = set(nodes)
        for u in nodes:
            for v in adj[u]:
                if v in node_set:
                    sub_adj[u].append(v)
        return nodes, sub_adj

    def get_tree_hash(u, p, sub_adj):
        child_hashes = []
        for v in sub_adj[u]:
            if v != p:
                child_hashes.append(get_tree_hash(v, u, sub_adj))
        child_hashes.sort()
        return "(" + "".join(child_hashes) + ")"

    def get_canonical_hash(nodes, sub_adj):
        # Find tree center to make hash root-invariant
        # Centers are nodes that minimize the maximum distance to any other node
        degrees = {u: len(sub_adj[u]) for u in nodes}
        q = deque([u for u in nodes if degrees[u] <= 1])
        remaining = len(nodes)
        
        while remaining > 2:
            remaining -= len(q)
            for _ in range(len(q)):
                u = q.popleft()
                for v in sub_adj[u]:
                    degrees[v] -= 1
                    if degrees[v] == 1:
                        q.append(v)
        
        centers = list(q)
        # If 2 centers, hash from both and pick the smaller string
        hashes = [get_tree_hash(c, -1, sub_adj) for c in centers]
        return min(hashes)

    unique_subtrees = set()
    for i in range(1, n + 1):
        sub_nodes, sub_adj = get_subtree(i)
        unique_subtrees.add(get_canonical_hash(sub_nodes, sub_adj))

    print(len(unique_subtrees))

solve()
