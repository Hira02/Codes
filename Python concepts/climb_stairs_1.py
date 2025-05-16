"""
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


| | | |


"""

def climbStairs(n) -> int:
    first = 1
    second = 1
    for i in range(2, n+1):
        curr = first + second
        first = second
        second = curr
    return second 

if __name__ == "__main__":
    n = 2
    print(climbStairs(n))