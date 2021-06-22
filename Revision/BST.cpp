#include <iostream>
#include <queue>
using namespace std;
class BinarySearchTree{
private:
    struct Node{
        int item;
        Node *left,*right;
    };
    Node *root;
public:
    BinarySearchTree(){
        root= nullptr;
    }


    void preOrder(Node *p){
        if(p!= nullptr){
            cout<<p->item<<" ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }
    void inOrder(Node *p){
        if(p!=NULL){
            inOrder(p->left);
            cout<<p->item<<" ";
            inOrder(p->right);
        }
    }
    void postOrder(Node *p) {
        if (p != nullptr) {
            postOrder(p->left);
            postOrder(p->right);
            cout << p->item << " ";
        }
    }
    void levelOrder(Node *root){
        if (root==NULL)
            return;
        queue<Node*>Q;
        Q.push(root);
        while (!Q.empty()){
            Node *curr=Q.front();
            cout<<curr->item<<" ";
            if (curr->left==NULL)
                Q.push(curr->right);
            Q.pop();
        }
    }
    bool Empty(){
        return root== nullptr;

    }

    bool search(int item){
        Node *curr=root;
        while (curr!= nullptr){
            if (curr->item==item)
                return true;
            else if(curr->item>item)
                curr=curr->left;
            else
                curr=curr->right;
        }
        return false;
    }
    void Insert(int item){
        Node *curr;
        Node *Prev;
        Node *newNode;
        newNode=new Node;
        newNode->item=item;
        newNode->left=newNode->right=NULL;
        if(root==NULL)
            root=newNode;
        else{
            curr=root;
            while (curr!=NULL){
                Prev=curr;
                if (curr->item==item){
                    cout<<"item already in tree ----- duplicates are not allowed \n";
                    return;
                }
                else
                if (curr->item>item)
                    curr=curr->left;
                else
                    curr=curr->right;
            }
            if(Prev->item>item)
                Prev->left=newNode;
            else
                Prev->right=newNode;

        }
    }

    void remove(int item)
    {
        Node *current;  //pointer to traverse the tree
        Node *trailCurrent; //pointer behind current

        if(root == NULL)
        {
            cout<<"Cannot delete from the empty tree."<<endl;
            return;
        }
        if(root->item == item)
        {
            deleteFromTree(root);
            return;
        }

        //if you get here, then the item to be deleted is not the root
        trailCurrent = root;

        if(root->item > item)
            current = root->left;
        else
            current = root->right;

        //search for the item to be deleted.
        while(current != NULL)
        {
            if(current->item == item)
                break;
            else
            {
                trailCurrent = current;
                if(current->item > item)
                    current = current->left;
                else
                    current = current->right;
            }
        }// once the while is done, current points to either NULL or to the node to be deleted

        if(current == NULL)
            cout<<"The delete item is not in the tree."<<endl;
        else if(trailCurrent->item > item)
            deleteFromTree(trailCurrent->left);
        else
            deleteFromTree(trailCurrent->right);
    }

    void deleteFromTree(Node* &p)
    {
        Node *current;    //pointer to traverse
        //the tree
        Node *trailCurrent;   //pointer behind current
        Node *temp;        //pointer to delete the node

        if(p->left == NULL && p->right == NULL)
        {
            delete p;
            p = NULL;
        }
        else if(p->left == NULL)
        {
            temp = p;
            p = p->right;
            delete temp;
        }
        else if(p->right == NULL)
        {
            temp = p;
            p = p->left;
            delete temp;
        }
        else
        {
            current = p->left;
            trailCurrent = NULL;

            while(current->right != NULL)
            {
                trailCurrent = current;
                current = current->right;
            }//end while

            p->item = current->item;

            if(trailCurrent == NULL) //current did not move;
                //current == p->left; adjust p
                p->left = current->left;
            else
                trailCurrent->right = current->left;

            delete current;
        }//end else
    }//end deleteFromTree

    void PostOrderTrav(){
        postOrder(root);
    }
    void PreOrderTrav(){
        preOrder(root);
    }void inOrderTrav(){
        inOrder(root);
    }
};

int main() {
    BinarySearchTree T1;
    T1.Insert(5);
    T1.Insert(6);
    T1.Insert(6);
    T1.Insert(4);
    T1.Insert(9);
    T1.Insert(1);
    T1.remove(6);
    T1.PostOrderTrav();
    cout<<endl;
    T1.inOrderTrav();
    cout<<endl;
    T1.PreOrderTrav();
    cout<<endl;






    return 0;
}
