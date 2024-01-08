class Solution
{
    private:
    struct Node* reverse(Node *head){
        Node *p, *q, *r;
        r= NULL, q= NULL;
        p= head;
        while(p){
            r= q;
            q=p;
            p= p->next;
            q->next= r;
        }
        head = q;
        return head;
    }
    public:
    struct Node * mergeResult(Node *h1,Node *h2)
    {
        Node *dummy= new Node;
        dummy->data= -1;
        dummy->next= NULL;
        Node *temp= dummy;
        while(h1!= NULL and h2!= NULL){
            if(h1->data < h2->data) {
                temp->next= h1;
                temp= temp->next;
                h1= h1->next;
            }
            else {
                temp->next= h2;
                temp= temp->next;
                h2= h2->next;
            }
        }
        if(h1!= NULL) temp->next = h1;
        if(h2!= NULL) temp->next = h2;
        return reverse(dummy->next);
        
    }  
};