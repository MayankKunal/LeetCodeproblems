 class Node{
public:
     int key;
     int val;
     Node*left;
     Node*right;
     Node(int keyVal,int dataVal)
     {
        key=keyVal;
        val=dataVal;
        left=NULL;
        right=NULL;
     }
    };
class LRUCache {
    unordered_map<int,Node*>mp;
    int cap;
       Node*firstNode=new Node(-1,-1);
        Node*lastNode=new Node(-1,-1);
public:
    LRUCache(int capacity) {
        cap=capacity;
        firstNode->right=lastNode;
        lastNode->left=firstNode;
    }

    void removeNode(Node*curr)
    {
        Node*prevNode=curr->left;
        Node*nextNode=curr->right;
        prevNode->right=nextNode;
        nextNode->left=prevNode;
        mp.erase(curr->key);
    }
    void addNode(Node*curr)
    {
       Node*secondNode=firstNode->right;
       firstNode->right=curr;
       curr->left=firstNode;
       curr->right=secondNode;
       secondNode->left=curr;
       mp[curr->key]=curr;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;
        Node*curr=mp[key];
        removeNode(curr);
        addNode(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            Node*curr=mp[key];
            curr->val=value;
            removeNode(curr);
            addNode(curr);
            return;
        }
        Node*secondLast=lastNode->left;
        if(mp.size()==cap)
        {
            removeNode(secondLast);
        }
        Node*newNode=new Node(key,value);
        addNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */