class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.size() , m = t.size();

        if( n != m ) return false;
        
        unordered_map<int , int>mpp;

        for(int i=0 ; i<n ; i++) {

            mpp[s[i]]++;

            mpp[t[i]]--;
        }
           
        

        for(auto it: mpp) 

        if(it.second != 0 ) return false;
    
        return true;
        
    }
};