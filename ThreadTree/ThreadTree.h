#ifndef THREADTREE_H
#define THREADTREE_H
#include <iostream>

namespace Charles{
    template<class T>
    struct BTNode {
        T element;
        BTNode<T> *lchild,*rchild;
        int ltag,rtag;,
        BTNode() {lchild = rchild = NULL;}
        BTNode(const T&x) {element = x;lchild = rchild = NULL;}
        BTNode(const T&x,BTNode<T> *l,BTNode<T> *r) {element = x;lchild = l;rchild = r;}
    };

    template<class T>
    class ThreadTree {
        public:                                                                                                                                                       
            ThreadTree(){root = NULL;}
            ~ThreadTree(){Clear();}
            void MakeThread(){
                if (root) {
                    BTNode<T>* pr = NULL;
                    MakeThread(root,pr);
                    pr->rtag = 1;
                }
            }
            bool Root(T&x){
                if (root){
                    x = root->element;
                    return true;
                }
                else return false;
            }
            void MakeTree(const T&x,ThreadTree<T>& left,ThreadTree<T>& right) {
                if ((root)||(&left==&right))return;
                root = new BTNode<T>(x,left.root,right.root);
                left.root = right.root = NULL;
            }
            void BreakTree(T&x,ThreadTree<T>& left,ThreadTree<T>& right) {
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
            ThreadTree<T>* Copy(){
                ThreadTree<T>* p = new ThreadTree;
                p->root = Copy(root);
                return p;
            }
        protected:
            BTNode<T> *root;
        private:
            void MakeThread(BTNode<T>* t,BTNode<T>* pr) {
                if (t!=NULL) {
                    MakeThread(t->lchild,pr);
                    if (pr!=NULL){
                        if(pr->rchild==NULL){
                            pr->rtag = 1;
                            pr->rchild = t;
                        }
                        else pr->rtag = 0;
                    }
                    if (t->lchild==NULL) {
                        t->ltag = 1;
                        t->lchild = pr;
                    }
                    else t->ltag = 0;
                    pr = t;
                    MakeThread(t->rchild,pr);
                }
            }
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