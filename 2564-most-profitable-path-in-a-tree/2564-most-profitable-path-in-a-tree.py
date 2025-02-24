class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        n = len(amount)

        graph = [[] for _ in range(n)] # make graph with connected nodes for each node
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        bob_time = [n] * n # [node] = time, time that bob reached node in path
        def find_bob_path(node, prev, time): 
            if node == 0: 
                bob_time[node] = time # 0 is last in path
                return True
            for nxt in graph[node]:
                if nxt != prev and find_bob_path(nxt, node, time + 1): # avoid loops and check connected nodes
                    bob_time[node] = time # path lead to 0, set time for current node
                    return True
            return False # path didn't lead to 0
        find_bob_path(bob, -1, 0) # set values for bob_time

        max_income = float('-inf')
        def find_alice_path(node, prev, time, income):
            if time < bob_time[node]:
                income += amount[node] # alice reached gate node first
            elif time == bob_time[node]:
                income += amount[node] // 2 # alice and bob arrived at same time

            if node != 0 and len(graph[node]) == 1: # check if at leaf, node != 0 to pass starting node
                nonlocal max_income
                max_income = max(max_income, income) # set new max income
                return # arrived at leaf, path over

            for nxt in graph[node]: # exlpore connected nodes
                if nxt != prev: # avoid looping
                    find_alice_path(nxt, node, time + 1, income)

        find_alice_path(0, -1, 0, 0) # find alice's max income
        return max_income