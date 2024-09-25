class Trie {
public:
    class trieNode{
      public:
        bool isEnd = false;
        vector<trieNode*> child = vector<trieNode*>(26, nullptr);
    };
    
    trieNode* root;
    Trie() {
        root = new trieNode();
    }
    
    void insert(string word) {
        trieNode* crawl = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(crawl->child[idx] == NULL){
                trieNode* newNode = new trieNode();
                crawl->child[idx] = newNode;
            }
            crawl = crawl->child[idx];
        }
        crawl->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* crawl = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(crawl->child[idx] == NULL){
                return false;
            }
            crawl = crawl->child[idx];
        }
        return crawl->isEnd;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl = root;
        for(char ch : prefix){
            int idx = ch - 'a';
            if(crawl->child[idx] == NULL){
                return false;
            }
            crawl = crawl->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */