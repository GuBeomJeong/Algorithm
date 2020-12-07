# Clone Graph
각 node를 따로 저장해야하는게 별로 였다.    
``` c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node){
            return node;
        }
        
        Node* head = new Node(node->val);
        Node* visit[101];
        
        for(int i=0;i<101;i++){
            visit[i] = 0;
        }
        
        queue<pair<Node*,Node*>> q;
        q.push({node,head});
        visit[node->val] = head;
        
        while(!q.empty()){
            Node* original = q.front().first;
            Node* newNode = q.front().second;
            q.pop();
            
            for(auto next : original->neighbors){
                Node* newNext = 0;
                if(visit[next->val]){
                    newNext = visit[next->val];
                }else{
                    newNext = new Node(next->val);
                }
                newNode->neighbors.push_back(newNext);
                if(!visit[next->val]){
                    visit[next->val] = newNext;
                    q.push({next,newNext});
                }
                
            }
        }
        return head;
    }
};
```