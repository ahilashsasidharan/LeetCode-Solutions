class Solution {
public:
    bool isVowel(char c){
        // since s consist of printable ASCII characters this is safe
        // but if not c should be cast to an unsigned_char to prevent undefined behaviour
        // where c is not between [0, 255] i.e. -1 or not EOF
        // because std::tolower requires EOF or an unsigned char value.
        c = tolower(c);
        return c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {

        int lp = 0;

        // safe to do in this case since s.length is guranteed to be >=1
        // if it wasn't s.size() should be casted to an int before the subtraction
        // or something else should be done to prevent underflow when s.size() equals 0 (i.e. s is empty)
        int rp = s.size() - 1;

        while(lp < rp){
            if(!isVowel(s[lp])){
                lp++;
            }
            else if(!isVowel(s[rp])){
                rp--;
            }   
            else{
                swap(s[lp], s[rp]);
                lp++;
                rp--;
            }
        }

        return s;
    }
};