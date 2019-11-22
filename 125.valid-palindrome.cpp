/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (31.93%)
 * Total Accepted:    388.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.length();

        if (size == 0) return true;
        int start = 0;
        int end = size-1;
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (start != end) {
            
            //cout << "COMPAIRING:  " << s[start] << "AND" << s[end] << endl;
            if (!((s[start] >= 'a' && s[start] <= 'z') || (s[start] >= '0' && s[start] <= '9'))) {
                start += 1;
                continue;
            }

            
            if (!((s[end] >= 'a' && s[end] <= 'z') || (s[end] >= '0' && s[end] <= '9'))) {
                end -= 1;
                continue;

            }
            if (s[start] == s[end]) {
                start += 1;
                end -= 1;
            } else {
                return false;
            }
            
        }
        return true;
    }
};

