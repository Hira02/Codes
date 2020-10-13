/*
Problem Description : (LC 204)
----------------------------------------------------------------------------------
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/
//Code:
//-------------------------------------------------------------------------------------------
class Solution
{
public:
    int countPrimeHelper(int val, int *count)
    { // Sieve of Eratosthenes
        vector<bool> primes(val, true);
        for (int i = 2; i * i < val; i++)
        {
            if (primes[i] == false)
                continue;
            for (int j = i * i; j < val; j += i)
            {
                primes[j] = false;
            }
        }
        for (int i = 2; i < val; i++)
        {
            if (primes[i])
                (*count)++;
        }
        return (*count);
    } // TC : O(nlog log n)
    int countPrimes(int n)
    {
        if (n <= 1)
            return 0;
        int count = 0;
        return countPrimeHelper(n, &count);
    }
};