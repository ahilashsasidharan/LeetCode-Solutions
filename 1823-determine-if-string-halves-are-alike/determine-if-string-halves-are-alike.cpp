class Solution {
public:
    bool halvesAreAlike(string s) {
        int half = s.length() / 2;
        int leftCount = 0;
        int rightCount = 0;
        std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for(int i = 0; i < half; i++){
            if(vowels.find(s[i]) != vowels.end()){
               leftCount++; 
            }
            if(vowels.find(s[s.length() - i - 1]) != vowels.end()){
               rightCount++; 
            }
        }

        return leftCount == rightCount;
    }
};