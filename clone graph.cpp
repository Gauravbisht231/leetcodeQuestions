// took hints from edtorial and solution section
class Solution {
public:
       unordered_map<Node*, Node*> naksha;
    Node* cloneGraph(Node* node) {
        if(node== NULL ) return NULL;
       queue<Node*> koo;
       koo.push(node);
       Node *firstnode= new Node(node->val, {});

       // map of current graph nodes and clone graph nodes

       naksha[node]= firstnode;
        while(!koo.empty()){
            auto top= koo.front();
            koo.pop();
            for(auto it: top->neighbors){
                // if the adjacent node is not found
                if(naksha.find(it)==naksha.end()){
                    naksha[it]= new Node(it->val, {});
                    koo.push(it);
                }
                naksha[top]->neighbors.push_back(naksha[it]);
            }
        }
        return naksha[node];
    }
};
