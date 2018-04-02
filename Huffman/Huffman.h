#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include "BTree.h"
#include "PrioQueue.h"

namespace Charles{
    template<class T>
    class Huffman:public BTree<T>{
        public:
            void CreateHuffman(T w[],int n){
                Huffman<T> x,y,z,zero;
                PrioQueue<Huffman<T>> pq(n);
                for (int i=0;i<n;i++){
                    z.MakeTree(w[i],x,y);
                    pq.Append(z);
                    z = zero;
                }
                for (int i=1;i<n;i++) {
                    pq.Serve(x);pq.Serve(y);
                    z.MakeTree(x.getW()+y.getW(),x,y);
                    z.putW(x.getW()+y.getW());
                    pq.Append(z);
                    z = zero;
                }
                pq.Serve(z);
                return z;
            }
            operator T() const {return weight;}
            T getW(){return weight;}
            T putW(const T&x){weight = x;}
        private:
            T weight;
    };
}

#endif