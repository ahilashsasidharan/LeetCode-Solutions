class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // have a slow and fast pointer
        // when you get to a letter that doesn't match advance the fast pointer to see if it will change something

        int s_backspaces = 0;
        int t_backspaces = 0;
        int sp = s.size() - 1;
        int tp = t.size() - 1;

        while(sp >= 0 || tp >= 0){
            while(sp >= 0 && s[sp] == '#'){
                s_backspaces++;
                sp--;
            }

            while(tp >= 0 && t[tp] == '#'){
                t_backspaces++;
                tp--;
            }

            while(s_backspaces > 0 && sp >= 0 && s[sp] != '#'){
                sp--;
                s_backspaces--;
            }

            while(t_backspaces > 0 && tp >= 0 && t[tp] != '#'){
                tp--;
                t_backspaces--;
            }

            if(t_backspaces == 0 && s_backspaces == 0 && sp >= 0 && tp >= 0 && s[sp] != '#' && t[tp] != '#'){
                if(s[sp] != t[tp]) return false;
                sp--;
                tp--;
            }

            if(tp == -1 && (sp >= 0 && s[sp] != '#')) return false;

            if(sp == -1 && (tp >= 0 && t[tp] != '#')) return false;
        }

        return (sp == tp);
    }
};