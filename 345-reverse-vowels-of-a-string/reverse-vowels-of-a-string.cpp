class Solution {
public:
    string reverseVowels(string s) {
        int lp = 0;
        int rp = s.size() - 1;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        while(lp < rp){
            if(vowels.count(tolower(s[lp])) && vowels.count(tolower(s[rp]))){
                char temp = s[lp];
                s[lp] = s[rp];
                s[rp] = temp;
                lp++;
                rp--;
            }
            else if(vowels.count(tolower(s[lp]))){
                rp--;
            }
            else if(vowels.count(tolower(s[rp]))){
                lp++;
            }
            else{
                lp++;
                rp--;
            }
        }

        return s;
    }
};