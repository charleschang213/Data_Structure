#ifndef LISTSET_H
#define LISTSET_H

namespace Charles{
    enum ResultCode{Undeflow,Overflow,Success,Duplicate,NotPresent};
   
    template<class T>
    class ListSet{
        public:
            ListSet(int n):MaxSize(n),Size(0){
                s = new T[MaxSize];
            }
            ~ListSet(){delete []s;}
            ResultCode Search(T&x);
            ResultCode Insert(T&x);
            ResultCode Remove(T&x);
            bool IsEmpty(){return Size==0;}
            bool IsFull(){return Size==MaxSize;}
        private:
            int Size;
            T* s;
            int MaxSize;
    };
}

#endif