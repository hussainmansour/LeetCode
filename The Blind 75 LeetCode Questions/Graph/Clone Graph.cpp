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
    map<Node*,  bool> visited;
    map<int,Node*> cloned;
    void dfs(Node* node)
    {
        if(visited[node])
        {
            return;
        }
        visited[node] = true;
        if(cloned.count(node->val) == 0){
            Node* newNode = new Node(node->val);
            cloned[node->val] = newNode;
        }
        for(auto i:node->neighbors)
        {
            if(cloned.count(i->val) == 0){
                Node* child = new Node(i->val);
                cloned[i->val] = child;
                cloned[node->val]->neighbors.push_back(child);
            }
            else
                cloned[node->val]->neighbors.push_back(cloned[i->val]);
            dfs(i);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        dfs(node);  
        return cloned[1];
    }
};
