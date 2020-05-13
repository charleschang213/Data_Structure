#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Linked_List/Linked_List.h"
//Implementation of linked list

namespace Charles{
    template<class T>
    class List_Sequence{
        public:
            List_Sequence(int msize=100) {
                Max_Size = msize;
                s = new T[Max_Size];
                Size = 0;
            }
            T* Begin(){return s;}
            T* End(){return s+Size-1;} 
            void Insert(int pos,T& x) {
                if (Size==Max_Size) {
                    std::cout << "Full List" << std::endl;
                    return;
                }
                if ((pos>Size)||(pos<0)) {
                    std::cout << "Invalid position" << std::endl;
                    return;
                }
                for (int i = Size-1;i>=pos;i--) s[i+1] = s[i];
                s[pos] = x;
                Size++;
            }
            void Remove(int pos) {
                if (Size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                if ((pos<0)||(pos>=Size)) {
                    std::cout << "Invalid position" << std::endl;
                    return;
                }
                for (int i=pos;i<Size-1;i++) s[i] = s[i+1];
                Size--;
            }
            void Retrieve(int pos,T& x) {
                if (Size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                if ((pos<0)||(pos>=Size)) {
                    std::cout << "Invalid position" << std::endl;
                    return;
                }
                x = s[pos];
            }
            void Replace(int pos,T& x) {
                if (Size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                if ((pos<0)||(pos>=Size)) {
                    std::cout << "Invalid position" << std::endl;
                    return;
                }
                s[pos] = x;
            }
            int Length() {return Size;}
            bool Isempty() {return Size==0;}
            bool Isfull() {return Size==Max_Size;}
            void Output(){
                if (Size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                std::cout << "**********Print List**********" << std::endl;
                for (int i=0;i<Size;i++) std::cout << s[i] << " ";
                std::cout << std::endl << "******************************" << std::endl;
            }
            void Clear() {
                Size=0;
            }
        private:
            T* s;
            int Size;
            int Max_Size;
    };

    template<class T>
    class List_Link{
        public:
            List_Link(int msize=100) {
                Max_Size = msize;
                head = NULL;tail = NULL; Size=0;
            }
            void Insert(int pos,T& x) {
                if (Isfull()) {
                    std::cout << "Full List" << std::endl;
                    return;
                }
                if ((pos>Size)||(pos<0)) {
                    std::cout << "Invalid position" << std::endl;
                    return;
                }
                if (Isempty()) {
                    Node<T>* newnode = new Node<T>(x);
                    head = tail = newnode;
                    Size = 1;Size++;
                    return;
                }
                if (pos==0) {
                    Node<T> *tmp = new Node<T>(x);
                    tmp->Append(head);
                    head = tmp;Size++;
                    return;
                }
                if (pos==Size) {
                    Node<T> *tmp = new Node<T>(x);
                    tail->Append(tmp);
                    tail = tmp;Size++;
                }
                Node<T> *tmp = head;
                for (int i = 0;i<pos-1;i++) tmp = tmp->step();
                Node<T> *tmp2 = new Node<T>(x);
                tmp2->Append(tmp->step());
                tmp->Append(tmp2);
                Size++;
            }
            void Remove(int pos) {
                 if (Size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                if ((pos<0)||(pos>=Size)) {
                    std::cout << "Invalid position" << std::endl;
                    return;
                }
                if (Size==1) {
                    delete head;
                    head = tail= NULL;
                    Size = 0;
                    return;
                }
                if (pos==0) {
                    Node<T> *tmp = head->step();
                    delete head;
                    head = tmp;Size--;
                    return;
                }
                if (pos==Size-1) {
                    Node<T> *tmp = head;
                    while (tmp->step()!=tail) tmp = tmp->step();
                    delete tail;
                    tail = tmp;Size--;
                    return;
                }
                Node<T> *tmp = head;
                for (int i = 0;i<pos-1;i++) tmp = tmp->step();
                Node<T> *tmp2 = tmp->step()->step();
                delete tmp->step();
                tmp->Append(tmp2);
                Size--;
            }
            Node<T>* Begin(){return head;}
            Node<T>* End(){return tail;}
            void Replace(int pos,T& x) {
                if (Size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                if ((pos<0)||(pos>=Size)) {
                    std::cout << "Invalid position" << std::endl;
                    return;
                }
                Node<T> *tmp = head;
                for (int i = 0;i<pos;i++) tmp = tmp->step();
                tmp->Replace(x);
            }
            void Retrieve(int pos,T& x) {
                if (Size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                if ((pos<0)||(pos>=Size)) {
                    std::cout << "Invalid position" << std::endl;
                    return;
                }
                Node<T> *tmp = head;
                for (int i = 0;i<pos;i++) tmp = tmp->step();
                x = tmp->show();
            }
            int Length() {
                return Size;
            }
            bool Isempty(){
                return Size==0;
            }
            bool Isfull() {
                return Size==Max_Size;
            }
            void Output() {
                if (Size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                Node<T> *tmp = head;
                std::cout << "**********Print List**********" << std::endl;
                while (tmp!=NULL) {
                    std::cout << tmp->show() << " ";
                    tmp = tmp->step();
                }
                std::cout << std::endl << "******************************" << std::endl;
            }
        private:
            Node<T> *head,*tail;
            int Max_Size;
            int Size;
    };
}

#endif