// For review purposes only! Does not represent the actual solution!

#ifndef BST_H
#define BST_H

template <class Type>
struct node
{
        Type data;
        node<Type> * llink;
        node<Type> * rlink;
};

template <class Type>
class BST
{

public:

BST();

~BST();

void insert (const Type& insertItem);

void processNodes(void (*funcPtr)(Type& item)) const;

void destroy (node<Type> * &p);

private:

void traverseBST (node<Type> *p, void (*funcPtr)(Type & item)) const;

node<Type> * root;

};

/* implementation */

template<class Type>
BST<Type>::BST()
{
        root=NULL;
}

template<class Type>
BST<Type>:: ~BST()
{
        destroy(root);
}

template<class Type>
void BST<Type>::insert (const Type& insertItem)
{
        node<Type> *current=NULL;
        node<Type> *trailCurrent=NULL;
        node<Type> *newNode;

        newNode = new node<Type>;
        newNode->data = insertItem;
        newNode->llink = NULL;
        newNode->rlink = NULL;

        if (root==NULL)
        {
                root = newNode;
        }
        else
        {
                current=root;

                while (current !=NULL)
                {
                        trailCurrent=current;

                        if (insertItem==current->data)
                        {
                                cout<<"Duplicates are not allowed!"<<endl;
                                return;
                        }
                        else
                        {
                                if(insertItem<current->data)
                                {
                                        current=current->llink;
                                }
                                else
                                {
                                        current=current->rlink;
                                }
                        }
                }

                if (insertItem<trailCurrent->data)
                {
                        trailCurrent->llink=newNode;
                }
                else
                {
                        trailCurrent->rlink=newNode;
                }
        }
}

template <class Type>
void BST<Type>::processNodes(void (*funcPtr)(Type& item)) const
{
        traverseBST(root,*funcPtr);
}

template <class Type>
void BST<Type>::destroy (node<Type> * &p)
{
        if(p!=NULL)
        {
                destroy (p->llink);
                destroy (p->rlink);
                delete p;
                p=NULL;
        }
}

template <class Type>
void BST<Type>::traverseBST(node<Type> *p, void (*funcPtr)(Type& item)) const
{
        if (p!=NULL)
        {
                (*funcPtr)(p->data);
                traverseBST(p->llink, *funcPtr);
                traverseBST(p->rlink, *funcPtr);
        }
}

#endif
