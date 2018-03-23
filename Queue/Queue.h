#ifndef QUEUE_H
#define QUEUE_H
#include "Linked_List.h"
namespace Charles{
    template<class T>
    class Queue_Sequence {
        public:
            Queue_Sequence(int msize = 100) {
                s = new T[msize+1];
                front = 0;rear = 0;
                Max_Size = msize+1;
            }
            void Append(const T&x) {
                if (Isfull()) {
                    std::cout << "Overflow" << std::endl;
                    return;
                }
                rear = (rear+1)%Max_Size;
                s[rear] = x;
            }
            void Output(){
                if (Isempty()) {
                    std::cout << "Empty Queue" << std::endl;
                    return;
                }
                std::cout << "**********Output Queue**********" << std::endl;
                for (int i=(front+1)%Max_Size;i!=(rear+1)%Max_Size;i=(i+1)%Max_Size) {std::cout << s[i] << " ";}
                std::cout << std::endl << "********************************" << std::endl;
            }
            void Serve(){
                if (Isempty()) {
                    std::cout << "Underflow" << std::endl;
                    return;
                }
                front = (front+1)%Max_Size;
            }
            T Front() {return s[(front+1)%Max_Size];}
            bool Isempty() {return front==rear;}
            bool Isfull() {return (rear+1)%Max_Size==front;}
        private:
            T* s;
            int Max_Size;
            int front;
            int rear;
    };
    template<class T>
    class Queue_Link {
        public:
            Queue_Link(int msize = 100):s() {
                Max_Size = msize;
            }
            void Append(const T& x) {
                 if (Isfull()) {
                    std::cout << "Overflow" << std::endl;
                    return;
                }
                s.Insert_Tail(x);
            }
            void Serve() {
                if (Isempty()) {
                    std::cout << "Underflow" << std::endl;
                    return;
                }
                s.Remove_Head();
            }
            void Output(){
                if (Isempty()) {
                    std::cout << "Empty Queue" << std::endl;
                    return;
                }
                s.Print_List();
            }
            bool Isempty(){return s.List_Size()==0;}
            bool Isfull(){return s.List_Size()==Max_Size;}
            T Front() {return s.List_Head()->show();}
        private:
            Linked_List<T> s;
            int Max_Size;
    };
}
#endif