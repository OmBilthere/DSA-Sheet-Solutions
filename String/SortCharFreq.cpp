class Solution {
public:
    string frequencySort(string s) {
        
        map<char , int> mpp;

        for(auto it : s) 

        mpp[it]++;

        int n = s.size();
        
        vector<vector<char>> bucket(n+1);

        for( auto it: mpp ) 

        bucket[it.second].push_back(it.first);

        s = "";
        
        for(int i = n ; i > 0 ; i--) {
              
              for(int j = 0 ; j < bucket[i].size() ; j++) 

              s.append(i , bucket[i][j]);

              
        }
        return s;
      
    }
}; 