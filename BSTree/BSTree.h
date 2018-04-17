#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include "BTree.h"
#include "ListSet.h"

namespace Charles{
    template<class T>
    class BSTree{
        public:
            BSTree(){root = NULL;}
            ~BSTree(){
                T a = root->element;
                while (root->rchild||root->lchild) Remove(a);
                delete root;
            }
            ResultCode Search(T& x){
                BTNode<T> *p = root;
                while(p){
                    if (p->element==x) return Success;
                    else if (x<p->element) p = p->lchild;
                    else p = p->rchild;
                }
                return NotPresent;
            }
            ResultCode Insert(T& x){
                BTNode<T> *p = root;
                BTNode<T> *q = NULL;
                while(p){
                    q = p;
                    if (p->element>x) p = p->lchild;
                    else if (p->element<x) p = p->rchild;
                    else {x = p->element;return Duplicate;}
                }
                p = new BTNode<T>(x);
                if (!root) root = p;
                else if (x<q->element) q->lchild = p;
                else q->rchild = p;
                return Success;
            }
            ResultCode Remove(T&x){
                BTNode<T> *r,*s,*c,*p=root,*q=NULL;
                while(p){
                    if (p->element==x) break;
                    q = p;
                    if (p->element>x) p = p->lchild;
                    else p = p->rchild;
                }
                if (!p) return NotPresent;
                if (p->lchild&&p->rchild){
                    s = p->rchild;r = p;
                    while(s->lchild){
                        r = s;s = s->lchild;
                    }
                    p->element = s->element;p=s;q=r;
                }
                if (p->lchild) c = p->lchild;
                else c = p->rchild;
                if (p==root) root = c;
                else if (p==q->lchild) q->lchild = c;
                else q->rchild = c;
                delete p;
                return Success;
            }
        private:
            BTNode<T> *root;
    };
}

#endif