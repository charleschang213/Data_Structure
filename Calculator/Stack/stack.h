#ifndef STACK_H
#define STACK_H
#include "Linked_List.h"
namespace Charles{
    template<class T>
    class Stack_Sequence {
        public:
            Stack_Sequence(int msize = 100) {
                s = new T[msize];
                top = -1;
                Max_Size = msize;
            }
            void Push(const T&x) {
                if (Isfull()) {
                    std::cout << "Overflow" << std::endl;
                    return;
                }
                top = top+1;
                s[top] = x;
            }
            void Output(){
                if (Isempty()) {
                    std::cout << "Empty Stack" << std::endl;
                    return;
                }
                std::cout << "**********Output Stack**********" << std::endl;
                for (int i=top;i>=0;i--) {std::cout << s[i] << " ";}
                std::cout << std::endl << "********************************" << std::endl;
            }
            void Pop(){
                if (Isempty()) {
                    std::cout << "Underflow" << std::endl;
                    return;
                }
                top = top-1;
            }
            T Top() {return s[top];}
            bool Isempty() {return top==-1;}
            bool Isfull() {return top==Max_Size-1;}
        private:
            T* s;
            int Max_Size;
            int top;
    };
    template<class T>
    class Stack_Link {
        public:
            Stack_Link(int msize = 100):s() {
                Max_Size = msize;
            }
            void Push(const T& x) {
                 if (Isfull()) {
                    std::cout << "Overflow" << std::endl;
                    return;
                }
                s.Insert_Head(x);
            }
            void Pop() {
                if (Isempty()) {
                    std::cout << "Underflow" << std::endl;
                    return;
                }
                s.Remove_Head();
            }
            void Output(){
                if (Isempty()) {
                    std::cout << "Empty Stack" << std::endl;
                    return;
                }
                s.Print_List();
            }
            bool Isempty(){return s.List_Size()==0;}
            bool Isfull(){return s.List_Size()==Max_Size;}
            T Top() {return s.List_Head()->show();}
        private:
            Linked_List<T> s;
            int Max_Size;
    };
}
#endif