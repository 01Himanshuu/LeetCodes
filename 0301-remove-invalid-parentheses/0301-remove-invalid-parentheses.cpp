class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> q{s}, vis{s};
        vector<string> ans;
        while (1) {
            for (auto &x:q) {
                int b=0;
                for(char c:x) {
                    if(c=='(') b++;
                    else if(c==')' && --b<0) { b=-1; break; }
                }
                if(!b) ans.push_back(x);
            }
            if(ans.size()) return ans;
            unordered_set<string> nq;
            for(auto &x:q)
                for(int i=0;i<x.size();i++)
                    if(x[i]=='('||x[i]==')') {
                        string y=x.substr(0,i)+x.substr(i+1);
                        if(vis.insert(y).second) nq.insert(y);
                    }
            q=nq;
        }
    }
};