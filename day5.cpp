const int K = 26;
struct node{
    node *nxt[K];
    bool isEnd;
};
 
node* newNode(){
    node* tmp = new node();
    for(int i = 0; i < K; i++){
        tmp->nxt[i] = NULL;
    }
    tmp->isEnd = false;
    return tmp;
}
 
class WordDictionary {
    node* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = newNode();        
    }
 
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        node* tmp = root;
        for(int i = 0; i < n; i++){
            int idx = word[i] - 'a';
            if(tmp->nxt[idx] == NULL){
                tmp->nxt[idx] = newNode();
            }
            tmp = tmp->nxt[idx];
        }
        tmp->isEnd = true;
    }
 
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_helper(0, word, root);
    }
 
    bool search_helper(int idx, string word, node* tmp){
        if(idx > word.size() || tmp == NULL) return false;
 
        while(idx < word.size()){
            int pos = word[idx] - 'a';
 
            if(pos == '.' - 'a'){
                bool okay = false;
                for(int j = 0; j < K; j++){
                    if(tmp->nxt[j] == NULL) continue;
                    okay = search_helper(idx + 1, word, tmp->nxt[j]);
                    if(okay) break;
                }                  
                return okay;
            }
 
            if(tmp->nxt[pos] == NULL) return false;
            tmp = tmp->nxt[pos];
            idx++;
        }
 
        return tmp->isEnd;
    }
};
