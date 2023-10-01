/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

*/

#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        //credit to deleted_user
        //very similar to Smallest Substring of All Characters on Pramp
        /*
        Time Complexity: we’re doing a linear iteration of both str and arr of lengths N and M      respectively, so the runtime complexity is linear in the size of the input, i.e. O(N+M).

        Space Complexity: we’re using a Map/Hash Table countMap with M key/values pairs plus few constant size counters, which together give us an O(M) space complexity (linear in the size of arr).
        */
        unordered_map<char, int> map;
        for(char c: t){
            map[c]++;
        }
        //begin and end mark the span of sliding window
        //counter keep track of how many char has not been found in sliding window
        int counter = t.size(), begin = 0, end = 0, len = INT_MAX, head = 0;
        while(end < s.size()){
            if(map[s[end++]]-- > 0){
                counter--;
            }
            while(counter == 0){
                if(end - begin < len){
                    head = begin;
                    len = end - head;
                }
                if(map[s[begin++]]++ == 0){
                    counter++;
                }
            }
        }
        return len == INT_MAX ?"":s.substr(head, len); 
    }
};