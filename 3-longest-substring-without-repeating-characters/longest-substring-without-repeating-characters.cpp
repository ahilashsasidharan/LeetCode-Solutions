class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<int> sub;
        int lp = 0;
        int max = 0;
        for(int i = 0; i < s.length(); i++){
            if(sub.find(s[i]) != sub.end()){
                if(max < (i - lp)){
                    max = i - lp;
                }
                
                while(s[lp] != s[i]){
                    sub.erase(s[lp]);
                    lp++;
                }
                 lp++;
            }else{
                sub.insert(s[i]);
            }
        }

        if(max < (s.length() - lp)){
            max = s.length() - lp;
        }

        return max;
    }
};