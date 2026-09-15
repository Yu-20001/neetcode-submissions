class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};
        for(char task : tasks){
            freq[task - 'A']++;
        }
        int maxFreq = 0;
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] > freq[maxFreq]) maxFreq = i;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] == freq[maxFreq]) cnt++;
        }
        
        return max((freq[maxFreq] - 1) * (n + 1) + cnt, (int)tasks.size());
    }
};

