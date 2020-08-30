class Trie {
    struct Node {
        vector<Node *> next;
        bool leaf;
        Node():leaf(false){
            for(int i=0; i<26; i++)
                next.push_back(nullptr);
        }
    };
    Node *head;
    public:
        Trie():head(new Node()) { }
        void addWord(string &s) {
            Node *root = head;
            string::reverse_iterator it = s.rbegin();
            for(; it<s.rend(); it++) {
                int index = *it-'a';
                if(root->next[index] == nullptr)
                    root->next[index] = new Node();
                root = root->next[index];
            }
            root->leaf = true;
        }
        bool checkPresent(string &s, int st, int len) {
            Node *root = head;
            for(int it = st; it>st-len; it--) {
                int index = s[it]-'a';
                if(root->next[index] == nullptr)
                    return false;
                root = root->next[index];
                if (root->leaf)  return true;
            }
            return root->leaf;
        }
};

class StreamChecker {
public:
    Trie *dict;
    string searchStr;
    int maxLen, minLen;

    StreamChecker(vector<string>& words) {
        dict = new Trie;
        maxLen = 0, minLen = INT_MAX;
        for(auto it: words){
            dict->addWord(it);
            minLen = minLen > it.length() ? it.length() : minLen;
            maxLen = maxLen < it.length() ? it.length() : maxLen;
        }
    }

    bool query(char letter) {
        searchStr += letter;
        if(searchStr.length() < minLen) return false;
        int len = min<long>(maxLen, searchStr.length());
        bool status = dict->checkPresent(searchStr, searchStr.length()-1, len);
        return status;
    }
};
