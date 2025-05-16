class Solution:
    def reverseWords(self, s: list[str]) -> None:
        # Helper to reverse a portion of the list in-place
        def reverse(l, left, right):
            while left < right:
                l[left], l[right] = l[right], l[left]
                left += 1
                right -= 1

        n = len(s)
        
        # Step 1: Reverse the whole list
        reverse(s, 0, n - 1)

        # Step 2: Reverse each word
        start = 0
        for end in range(n + 1):
            if end == n or s[end] == ' ':
                reverse(s, start, end - 1)
                start = end + 1


# ---------- main function ----------
if __name__ == "__main__":
    # Take input as a string
    input_str = input("Enter the string with words separated by single spaces:\n")

    # Convert string to list of characters (simulate char array)
    s = list(input_str)

    # Call the function
    Solution().reverseWords(s)

    # Print the result as a string
    print("Reversed words:")
    print(''.join(s))