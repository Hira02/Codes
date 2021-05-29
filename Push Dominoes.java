/*
Problem Description : (LC 838)
------------------------------------------------------------------------------------------
There are N dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.


https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png
After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; 
S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state. 

Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Note:

0 <= N <= 10^5
String dominoes contains only 'L', 'R' and '.'

*/

//---------------------------------------------------------------------------------------------------------------------------
//Code:
class Solution {
  public String pushDominoes(String dominoes) {
	dominoes = "L" + dominoes + "R";
        char[] d = dominoes.toCharArray();
        int i = 0, j = 0, len = dominoes.length();
        
        while (i < len - 1) {
            j = i + 1;
            while (j < len && d[j] == '.') j++;
            
            if (d[i] == d[j]) Arrays.fill(d, i, j, d[i]);
            else if (d[i] == 'R' && d[j] == 'L') {
                int effect = (j - i - 1) / 2;
                Arrays.fill(d, i, i + effect + 1, 'R');
                Arrays.fill(d, j - effect, j + 1, 'L');
            }
            
            i = j;
        }
        
        return new String(Arrays.copyOfRange(d, 1, len - 1));
}

}
/*Approach :
#1:
if there is NO dot (meaning every domino is pushed), then the final state is the initial state
        //   for example, all "LLL" => "LLL", all "RRR" => "RRR",
        //                mixed "LLLRR" => "LLLRR" (falling domino having no effect on already-fallen domino)
        // if there is only ONE dot, we have a few possibilities:
        //   "L.R" => "L.R", "R.L" => "R.L" (center-one standing), "L.L" => "LLL", "R.R" => "RRR"
        // if there are TWO dots, we have the following possibilities:
        //   "L..R" => "L..R", "R..L" => "RRLL" (center-one standing), "L..L" => "LLLL", "R..R" => "RRRR"
        // if there are TWO dots, we have the following possibilities:
        //   "L...R" => "L...R", "R...L" => "RR.LL" (center-one standing), "L...L" => "LLLLL", "R...R" => "RRRRR"
        // Therefore the rule is:
        // for each region of dots (a substring "P....Q"), check its left and right
        //   if left is "L" and right is "R", the substring remains as is;
        //   if left is "R" and right is "L", the substring is converted into either "RRRLLL" or "RR.LL"
        //   if left and right are the same, the substring is converted into either "RRRRR" or "LLLLL"
        
        
 #2: Leetcode solution : 
 
 Intuition

We can calculate the net force applied on every domino. The forces we care about are how close a domino is to a leftward 'R', and to a rightward 'L': the closer we are,
the stronger the force.

Algorithm

Scanning from left to right, our force decays by 1 every iteration, and resets to N if we meet an 'R', so that force[i] is higher (than force[j]) if and only if 
dominoes[i] is closer (looking leftward) to 'R' (than dominoes[j]).

Similarly, scanning from right to left, we can find the force going rightward (closeness to 'L').

For some domino answer[i], if the forces are equal, then the answer is '.'. Otherwise, the answer is implied by whichever force is stronger.

Example

Here is a worked example on the string S = 'R.R...L': We find the force going from left to right is [7, 6, 7, 6, 5, 4, 0]. The force going from right to left 
is [0, 0, 0, -4, -5, -6, -7]. Combining them (taking their vector addition), the combined force is [7, 6, 7, 2, 0, -2, -7], for a final answer of RRRR.LL.


class Solution {
    public String pushDominoes(String S) {
        char[] A = S.toCharArray();
        int N = A.length;
        int[] forces = new int[N];

        // Populate forces going from left to right
        int force = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 'R') force = N;
            else if (A[i] == 'L') force = 0; // this is the catch
            else force = Math.max(force - 1, 0);
            forces[i] += force;
        }

        // Populate forces going from right to left
        force = 0;
        for (int i = N-1; i >= 0; --i) {
            if (A[i] == 'L') force = N;
            else if (A[i] == 'R') force = 0; // this is the catch
            else force = Math.max(force - 1, 0);
            forces[i] -= force;
        }

        StringBuilder ans = new StringBuilder();
        for (int f: forces)
            ans.append(f > 0 ? 'R' : f < 0 ? 'L' : '.');
        return ans.toString();
    }
}
