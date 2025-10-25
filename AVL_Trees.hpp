#include <iostream>
#include <ctime>
using namespace std;




class Node
{
    public:

    string val;
    int height;
    int created_timestamp;
    Node* left;
    Node* right;

    Node(string value,int ct)
    {
        this->val = value;
        this->created_timestamp = ct;
        this->height = 1;
        this->left = NULL;
        this->right = NULL;
    }

    int getHeight(Node* n)
    {
        if(n==NULL) return 0;
        return n->height;
    }


    int balfac(Node* n)
    {
        if(n==NULL) return 0;
        return getHeight(n->left)-getHeight(n->right);
    }



    Node* rightRotate(Node* root)
    {
        Node* t1 = root->left;
        Node* t2 = t1->right;

        t1->right = root;
        root->left = t2;

        root->height = 1 + max(getHeight(root->left),getHeight(root->right));
        t1->height = 1 + max(getHeight(t1->left),getHeight(t1->right));

        return t1;
    }



    Node* leftRotate(Node* root)
    {
        Node* t1 = root->right;
        Node* t2 = t1->left;

        t1->left = root;
        root->right = t2;

        root->height = 1 + max(getHeight(root->left),getHeight(root->right));
        t1->height = 1 + max(getHeight(t1->left),getHeight(t1->right));

        return t1;
    }




    
    

    Node* insert(Node* root, string value,int ct)
    {
        if(root==NULL) 
        {   
            Node* n = new Node(value,ct);
            
            return n;
        }

        if(ct < root->created_timestamp) root->left = insert(root->left,value,ct);
        else if(ct >= root->created_timestamp) root->right = insert(root->right,value,ct);

        root->height = 1 + max(root->getHeight(root->left),root->getHeight(root->right));

        int bf = root->balfac(root);
        


        //Left-Left case (Right rotation)
        if(bf > 1 and root->balfac(root->left)>=0)
        {
            root = root->rightRotate(root);
        }

        
        //Right-Right case (Left rotation)
        else if(bf < -1 and root->balfac(root->right)<=0)
        {
            root = root->leftRotate(root);
        }

        
        //Left-Right case (Left and then Right rotation)
        else if(bf > 1 and root->balfac(root->left)<0)
        {
            root->left = root->leftRotate(root->left);
            root = root->rightRotate(root);
        }


        //Right-Left cases (Right and then Left rotation)
        else if(bf < -1 and root->balfac(root->right)>0)
        {
            root->right = root->rightRotate(root->right);
            root = root->leftRotate(root);
        }


        return root;
    }


    void reverse_inorder(Node* root)
    {
        if(root==NULL) return;
        reverse_inorder(root->right);
        cout<<root->val<<endl;
        reverse_inorder(root->left);
        return;
    }


    void reverse_inorder_n(Node* root,int n,int &cnt)
    {
        if(root==NULL) return;
        reverse_inorder_n(root->right,n,cnt);
        if(cnt>=n) return;
        cout<<root->val<<endl;
        cnt++;
        reverse_inorder_n(root->left,n,cnt);
        return;
    }



};



