class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> seen;

        if(s.length() != t.length()){
            return false;
        }

        for(int i = 0; i < s.length(); i++){
            seen[s[i]]++;
            seen[t[i]]--;
        }

        for(const auto [key, value]: seen){
            if(value != 0)
                return false;
        }

        return true;
        
    }
};