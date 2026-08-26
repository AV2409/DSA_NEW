class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:

        chefs = []

        for q, w in zip(quality, wage):
            chefs.append((w / q, q))

        chefs.sort()

        heap = []
        total = 0
        ans = float('inf')

        for rate, quality in chefs:
            if len(heap) == k - 1:
                ans = min(ans, rate * (total + quality))

            if len(heap) < k - 1:
                heapq.heappush(heap, -quality)
                total += quality

            elif k > 1 and quality < -heap[0]:
                total += quality + heapq.heappop(heap)
                heapq.heappush(heap, -quality)

        return ans