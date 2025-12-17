class Solution {
public:
    bool isPalindrome(string s, int lp, int rp){
        while(lp < rp){
            if(s[lp] == s[rp]){
                lp++;
                rp--;
            }
            else{
                return false; 
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        // Strategy:
        // check if the string is a palindrome
        // if at some point the string is not a palindrome check if moving the left or right pointer makes it one
        // if you can then continue otherwise fail
        // Ignore this logic Incorrect:
        // do this once and use a boolean to keep track of this
        // if there is another point where it is not a palindrome fail

        int lp = 0;
        int rp = s.size() - 1; 

        while(lp < rp){
            if(s[lp] == s[rp]){
                lp++;
                rp--;
            }
            else{
                return isPalindrome(s, lp + 1, rp) || isPalindrome(s, lp, rp - 1); 
            }
        }

        return true;
    }
};