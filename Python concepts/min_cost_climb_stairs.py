from typing import List


class Solutions:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        first = cost[0]
        second = cost[1]
        for i in range(2, n):
            curr  = cost[i] + min(first, second)
            second, first = curr, second       
        return min(first, second)
if __name__ == "__main__":
    cost = [1,100,1,1,1,100,1,1,100,1]
    s = Solutions()
    print(s.minCostClimbingStairs(cost))