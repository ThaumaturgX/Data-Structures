class Trie {
    struct Node {
        char val;
        bool isWord;
        std::vector<Node*> children;
        Node(char val): val(val), isWord(0),
            children(std::vector<Node*>(256, nullptr)) {}
    };
    
public:
    Trie(): root(new Node(0)) {}
    Trie(const std::vector<std::string> &v): Trie() {
        for(const auto &s : v)
            this->insert(s);
    }
    ~Trie() {
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                for(auto &node : q.front()->children)
                    if(node) q.push(node);
                    delete(q.front());
                    q.pop();
                }
        }
    }
    
    void insert(const std::string &s) {
        int n = s.size();
        Node *cur = root;
        for(int i = 0; i < n; i++) {
            if(!cur->children[s[i]])
                cur->children[s[i]] = new Node(s[i]);
            cur = cur->children[s[i]];
            if(i == n - 1)
                cur->isWord = 1;
        }
    }
    
    Node* getNode(const std::string &s) {
        Node *cur = root;
        for(const auto &c : s) {
            if(!cur->children[c])
                return nullptr;
            cur = cur->children[c];
        }
        return cur;
    }
    
    bool find(const std::string &s) {
        Node *cur = getNode(s);
        return cur ? cur->isWord : 0;
    }
    
    void erase(const std::string &s) {
        Node *cur = getNode(s);
        if(cur) cur->isWord = 0;
    }
    
private:
    Node *root;
};
