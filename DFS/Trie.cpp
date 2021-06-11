// Memory efficient trie using map

struct trie{
    unordered_map<char, trie*> child;
    bool isend;

    trie(){
        
        isend = false;
    }

};

trie *root = new trie();       // dhriti ayush

void insert(string &str){
    trie *curr = root;
    for(auto &x: str){
        if(!curr->child[x-'a']){
            curr->child[x - 'a'] = new trie();
        }
        curr = curr->child[x-'a'];
    }
    curr->isend = true;
}

bool search(string &str){
    trie* curr = root;
    for(auto &x: str){
        if(!curr->child[x - 'a'])   return false;
        curr = curr->child[x - 'a'];
    }
    if(curr->isend)   return 1;
    return 0;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        insert(s);
    }
    int x;
    cin>>x;
  
    while(x--){
        string s;
        cin>>s;
        cout<<search(s)<<"\n";
    }
  return 0;
 
}
