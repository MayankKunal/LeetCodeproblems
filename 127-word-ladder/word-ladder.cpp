class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        unordered_set<string>st;
        st.insert(wordList.begin(),wordList.end());
        queue<pair<int,string>>q;
        q.push({1,beginWord});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int turn=it.first;
            string word=it.second;
            if(word==endWord) return turn;
         for(int i=0;i<word.size();i++)
         {
            char originalCharacter=word[i];
            for(char c='a';c<='z';c++)
            {
                word[i]=c;
                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({turn+1,word});
                }

            }
            word[i]=originalCharacter;
         }
        }
        return 0;
    }
};