class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int nChildren = 0;
        int gp = 0;

        // sort both arrays
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        for(int i {0uz}; i < s.size(); i++){
            if(s[i] >= g[gp]){
                nChildren++;
                if(gp + 1 < g.size()) gp++;
                else break;
            }
        }

        return nChildren;
    }
};