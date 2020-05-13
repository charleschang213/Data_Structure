#ifndef UFSET_H
#define UFSET_H
#include <iostream>
// Implementation of UF-set

namespace Charles{
    template<class T>
    class UFSet{
        public:
            UFSet(int n):Size(n){
                s = new T[n];
                parent = new int[n];
                for (int i=0;i<n;i++) {
                    parent[i] = -1;
                    s[i] = i;
                }
            }
            UFSet(int n,T* d):Size(n){
                s = new T[n];
                parent = new int[n];
                for (int i=0;i<n;i++) {
                    parent[i] = -1;
                    s[i] = d[i];
                }
            }
            ~UFSet(){delete []s;delete []parent;}
            void Union(int x,int y){
                parent[x] = y;
            }
            int Find(int i){
                int r=i;
                int t,l;
                while (parent[r]>0){r = parent[r];}
                if (r!=i){
                    for (t = i;parent[t]!=r;t=l){
                        l = parent[t];parent[t] = r;
                    }
                }
                return r;
            }
        private:
            int Size;
            T* s;
            int* parent;
    };
}

#endif