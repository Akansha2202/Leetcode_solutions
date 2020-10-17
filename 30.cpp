class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.length()==0||words.size()==0||words[0].length()>s.length())
            return {};
        unordered_map<string,int> freq;
        vector<int> ans;
        for(auto i:words)
            freq[i]++;
        int i,j,k,l=words[0].length();
        i=0,j=0,k=words.size();
        for(i=0;i<=s.length()-l*k+1;i++){
            unordered_map<string,int> seen;
            for(j=0;j<k;j++){
                string s1=s.substr(i+j*l,l);
                if(freq.find(s1)!=freq.end()){
                    seen[s1]++;
                    if(seen[s1]>freq[s1])
                        break;
                }
                else
                    break;
            }
            if(j==k)
                ans.push_back(i);            
        }
        return ans;
    }
};