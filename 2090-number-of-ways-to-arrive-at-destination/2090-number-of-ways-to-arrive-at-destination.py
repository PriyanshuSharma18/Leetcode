class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        MOD = 10**9 + 7
        adj = [[] for _ in range(n)]
        
        for u, v, t in roads:
            adj[u].append((v, t))
            adj[v].append((u, t))
            
        heap = [(0, 0)]
        dist = [float('inf')] * n
        ways = [0] * n
        dist[0] = 0
        ways[0] = 1
        
        while heap:
            time, u = heapq.heappop(heap)
            if time > dist[u]:
                continue
                
            for v, t in adj[u]:
                new_time = time + t
                if new_time < dist[v]:
                    dist[v] = new_time
                    ways[v] = ways[u]
                    heapq.heappush(heap, (new_time, v))
                elif new_time == dist[v]:
                    ways[v] = (ways[v] + ways[u]) % MOD
                    
        return ways[-1]