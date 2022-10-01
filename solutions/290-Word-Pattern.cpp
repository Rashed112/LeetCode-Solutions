/*
* use of unordered map
* map by default makes order, unordered map doesn't
* unordered map is like hashing to keep count not order
* in this problem, have to use two unordered_map (one is reverse type of another, e.g. one is <char,string> and another is <string, char>
* by using two reverse type map, we can comapre easily
*/



class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
            vector<string> words;
            istringstream ss(s);
            string temp;

            while (ss >> temp)
            {
                words.push_back(temp);

            }
            if (pattern.size() != words.size())
            {
                //cout<<"false"<<endl;
                return false;
            }
            unordered_map<char, string> mp1;
            unordered_map<string, char> mp2;
            for(int i=0; i<words.size();i++){
                if(mp1.find(pattern[i])!=mp1.end() && mp1[pattern[i]]!=words[i] ||
                    mp2.find(words[i])!=mp2.end() && mp2[words[i]]!= pattern[i] ){
                        //cout<<"false"<<endl;
                        return false;
                    }
                mp1[pattern[i]]=words[i];
                mp2[words[i]]=pattern[i];

            }
            //cout<<"true"<<endl;
            return true;


        }
};
