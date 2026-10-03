class Solution {
private:
    int bfs(string beginWord, string endWord, unordered_set<string>& candidates){
        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string curr = q.front();
                if(curr == endWord) return step;
                q.pop();
                for(int j = 0; j < curr.size(); j++){
                    string temp = curr;
                    for(int k = 0; k < 26; k++){
                        temp[j] = 'a' + k;
                        if(temp != curr && candidates.count(temp)){
                            q.push(temp);
                            candidates.erase(temp);
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> candidates;
        for(string str : wordList){
            candidates.insert(str);
        }
        return bfs(beginWord, endWord, candidates);
    }
};
