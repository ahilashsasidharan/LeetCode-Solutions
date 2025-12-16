class Solution {
public:
    bool isPalindrome(string s) {
        int lp = 0;
        int rp = s.length() - 1;

        while(lp < rp){            

            if(!std::isalnum(s[lp])){
                lp++;
                continue;
            }
            if(!std::isalnum(s[rp])){
                rp--;
                continue;
            }


            if(std::tolower(s[lp]) != std::tolower(s[rp])){
                return false;
            }

            lp++;
            rp--;
        }

        return true;
    }
};