#ifndef BTREE_H
#define BTREE_H
#include <iostream>

namespace Charles{
    template<class T>
    struct BTNode {
        T element;
        BTNode<T> *lchild,*rchild;
        BTNode() {lchild = rchild = NULL;}
        BTNode(const T&x) {element = x;lchild = rchild = NULL;}
        BTNode(const T&x,BTNode<T> *l,BTNode<T> *r) {element = x;lchild = l;rchild = r;}
    };

    template<class T>
    class BTree {
        public:                                                                                                                                                       
            BTree(){root = NULL;}
            ~BTree(){Clear();}
            bool Root(T&x){
                if (root){
                    x = root->element;
                    return true;
                }
                else return false;
            }
            void MakeTree(const T&x,BTree<T>& left,BTree<T>& right) {
                if ((root)||(&left==&right))return;
                root = new BTNode<T>(x,left.root,right.root);
                left.root = right.root = NULL;
            }
            void BreakTree(T&x,BTree<T>& left,BTree<T>& right) {
                if ((!root)||(left.root)||(right.root)||(&left==&right)) return;
                left.root = root->lchild;
                right.root = root->rchild;
                delete root;
                root = NULL;
            }
            void Clear(){}
            void PreOrder(void (*Visit)(T& x)) {
                PreOrder(Visit,root);
            }
            void InOrder(void (*Visit)(T& x)) {
                InOrder(Visit,root);
            }
            void PostOrder(void (*Visit)(T& x)) {
                PostOrder(Visit,root);
            }
            int Size() {return Size(root);}
            BTree<T>* Copy(){
                BTree<T>* p = new BTree;
                p->root = Copy(root);
                return p;
            }
        protected:
            BTNode<T> *root;
        private:
            BTNode<T>* Copy(BTNode<T>* t) {
                if (!t) return NULL;
                BTNode<T>* q = new BTNode<T>(t->element);
                q->lchild = Copy(t->lchild);
                q->rchild = Copy(t->rchild);
                return q;
            }
            void Clear(BTNode<T> *t){}
            void PreOrder(void (*Visit)(T&x),BTNode<T>* t) {
                if (t) {
                    Visit(t->element);
                    PreOrder(Visit,t->lchild);
                    PreOrder(Visit,t->rchild);
                }
            }
            void InOrder(void (*Visit)(T&x),BTNode<T>* t) {
                if (t) {
                    InOrder(Visit,t->lchild);
                    Visit(t->element);
                    InOrder(Visit,t->rchild);
                }
            }
            void PostOrder(void (*Visit)(T&x),BTNode<T>* t) {
                if (t) {
                    PostOrder(Visit,t->lchild);
                    PostOrder(Visit,t->rchild);
                    Visit(t->element);
                }
            }
            int Size(BTNode<T> *t) {
                if (!t) return 0;
                return 1+Size(t->lchild)+Size(t->rchild);
            }
    };
    template<class T>
    void Visit(T& x) {
        std::cout<< x << " ";
    }
}

#endif