class Node{
    public:
    vector<Node*> next;
    bool is_end;
    Node(){
        next = vector<Node*>(26,nullptr);
        is_end = false;
    }
};
class Solution {
    Node* root;
public:
    void add_to_tree(string &word){
        Node* q = root;
        for(char c: word){
            if(q->next[c-'a'] == nullptr){
                q->next[c-'a'] == new Node();
            }
            q = q->next[c-'a'];
        }
        q->is_end = true;
    }
    void buildTrie(vector<string>& wordDict){
        root = new Node();
        for(auto word: wordDict){
            add_to_tree(word);
        }
    }
    bool find_word(string word){
        Node* q = root;
        for(char c: word){
            if(q->next[c-'a'] == nullptr){
                return false;
            }
            q = q->next[c-'a'];
        }

        return q->is_end;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        buildTrie(wordDict);
    }
};