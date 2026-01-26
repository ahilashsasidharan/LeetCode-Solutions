class Solution {
public:
    int strStr(string haystack, string needle) {
        int candidate {},
            i {},
            j {};

        if(haystack.size() < needle.size()){
            return -1;
        }

        while(i <= haystack.size() - needle.size()){
            if(haystack[i + j] == needle[j]){
                j++;
                if(j == needle.size()) return i;
            }
            else{
                i++;
                j = 0;
            }
        }

        return -1;
    }
};