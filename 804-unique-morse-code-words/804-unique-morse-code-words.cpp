class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> S;
        for (auto& word: words) {
            string m;
            for (char ch : word) m += morse[ch - 97];
            S.insert(m);
        }
        
        return S.size();
    }
};