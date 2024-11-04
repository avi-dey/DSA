# Important Problems of Dynamic Programming on Strings

Dynamic Programming (DP) on strings is a crucial area in computer science, particularly in bioinformatics, natural language processing, and data compression. Here are some of the most important problems that are commonly solved using dynamic programming on strings:

## 1. Longest Common Subsequence (LCS) --done
   - **Problem**: Given two strings, find the length of the longest subsequence that appears in both.
   - **Applications**: It is used in version control systems to find differences between files, DNA sequence alignment, and more.
   - **DP Approach**: A 2D array is used to store solutions to subproblems, where `dp[i][j]` represents the length of the LCS of the first `i` characters of the first string and the first `j` characters of the second string.

## 2. Longest Palindromic Subsequence --done
   - **Problem**: Given a string, find the longest subsequence that is also a palindrome.
   - **Applications**: Useful in computational biology and text analysis.
   - **DP Approach**: A 2D table is used where `dp[i][j]` represents the length of the longest palindromic subsequence in the substring starting at index `i` and ending at `j`.

## 3. Edit Distance (Levenshtein Distance) --done
   - **Problem**: Given two strings, find the minimum number of operations (insertions, deletions, and substitutions) required to transform one string into the other.
   - **Applications**: Spell checkers, DNA sequence alignment, plagiarism detection.
   - **DP Approach**: A 2D array `dp[i][j]` is used, where `dp[i][j]` represents the edit distance between the first `i` characters of the first string and the first `j` characters of the second string.

## 4. Longest Palindromic Substring
   - **Problem**: Given a string, find the longest contiguous substring that is a palindrome.
   - **Applications**: Text analysis, pattern recognition.
   - **DP Approach**: A 2D table where `dp[i][j]` indicates if the substring from index `i` to `j` is a palindrome, and then find the longest.

## 5. String Alignment (Needleman-Wunsch and Smith-Waterman)
   - **Problem**: Align two strings in a way that maximizes their similarity or minimizes the cost of alignment (often used in bioinformatics).
   - **Applications**: DNA, RNA, and protein sequence analysis.
   - **DP Approach**: Uses a scoring system to fill a 2D matrix, calculating scores for matches, mismatches, and gaps, with different penalties and bonuses depending on the alignment method.

## 6. Regular Expression Matching
   - **Problem**: Determine if a given string matches a pattern that includes special characters like `*` (zero or more of the preceding element) and `.` (any single character).
   - **Applications**: Parsing, validation of inputs, and search functionalities.
   - **DP Approach**: A 2D table where `dp[i][j]` tells if the substring `s[0...i]` matches the pattern `p[0...j]`.

## 7. Shortest Common Supersequence (SCS)
   - **Problem**: Given two strings, find the length of the shortest string that has both as subsequences.
   - **Applications**: Data compression, DNA sequence analysis.
   - **DP Approach**: Uses the LCS approach as a foundation and derives the length of the SCS from it.

## 8. Word Break Problem
   - **Problem**: Given a string and a dictionary of words, determine if the string can be segmented into a space-separated sequence of dictionary words.
   - **Applications**: NLP, text segmentation.
   - **DP Approach**: A 1D DP array where `dp[i]` represents whether the substring `s[0...i]` can be segmented into words from the dictionary.

## 9. Distinct Subsequences
   - **Problem**: Given two strings `s` and `t`, count the number of distinct subsequences of `s` which equals `t`.
   - **Applications**: Sequence analysis and parsing problems.
   - **DP Approach**: A 2D array `dp[i][j]` is used, where `dp[i][j]` indicates the number of ways to match the first `j` characters of `t` with the first `i` characters of `s`.

## 10. Wildcard Matching
   - **Problem**: Given a string and a pattern where `*` matches any sequence of characters and `?` matches any single character, determine if the string matches the pattern.
   - **Applications**: Text pattern matching, file search utilities.
   - **DP Approach**: A 2D DP table is used, where `dp[i][j]` indicates whether the first `i` characters of the string match the first `j` characters of the pattern.

These problems are fundamental to understanding how dynamic programming can be applied to strings and sequences, offering a variety of practical applications. The DP approaches often involve defining a table that tracks possible sub-solutions, using overlapping subproblems and optimal substructure properties to build a final solution.
