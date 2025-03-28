class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:

        findBest = lambda x: (bisect_left(arr, x))

        m, n, prev = len(grid),len(grid[0]), 0
        heap, arr = [(grid[0][0], (0, 0))], []
        dir = ((1,0), (0,1), (-1,0), (0,-1))

        grid[0][0] = None
        
        while heap:
            cellVal, (row, col) = heappop(heap)
            arr.append(cellVal)

            for dr, dc in dir:
                r, c = row + dr, col + dc

                if 0 <= r < m and 0 <= c < n and grid[r][c]:
                    
                    heappush(heap, (grid[r][c], (r, c)))
                    grid[r][c] = None

        for i in range(m*n):
            prev = arr[i] = max(arr[i],prev)

        return [findBest(q) for q in queries]