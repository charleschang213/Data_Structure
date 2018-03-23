#ifndef LINKED_LIST_H
#define LINKED_LIST_H
namespace Charles {
    template<class T>
    class Node {
        public:
            Node(T a=0,Node<T>* N = NULL){
                data = a;
                Next = N;
            }
            void Append(Node<T>* N){
                Next = N;
            }
            T show(){return data;}
            Node<T>* step(){
                return Next;
            }
        private:
            T data;
            Node<T>* Next;
    };
    template<class T>
    class Linked_List {
        public:
            Linked_List(){
                head = NULL;tail = NULL;size = 0;
            }
            Linked_List(T head_data){
                head = new Node<T>(head_data);
                size = 1;
                tail = head;
            }
            ~Linked_List(){
                Node<T> *tmp = NULL;
                Node<T> *tmp2 = head;
                while (tmp2!=tail) {tmp = tmp2;tmp2 = tmp2->step(); delete tmp;}
                delete tmp2;
                head = NULL;tail = NULL;size = 0;
            }
            bool empty(){return size==0;}
            void Print_List(){
                if (empty()) {std::cout << "Empty List" << std::endl; return;}
                std::cout << "**********Print List**********" << std::endl;
                Node<T> *tmp = head;
                while (tmp!=NULL) {
                    std::cout << tmp->show() << " ";
                    tmp = tmp->step();
                } 
                std::cout << std::endl << "******************************" << std::endl;
            };
            void Insert_Head(T dat) {
                if (size==0) {
                    Node<T>* newnode = new Node<T>(dat);
                    head = tail = newnode;
                    size = 1;
                    return;
                }
                Node<T>* newnode = new Node<T>(dat,head);
                head = newnode;
                size++;
            }
            void Insert_Tail(T dat) {
                if (size==0) {
                    Node<T>* newnode = new Node<T>(dat);
                    head = tail = newnode;
                    size = 1;
                    return;
                }
                Node<T>* newnode = new Node<T>(dat);
                tail->Append(newnode);
                tail = newnode;
                size++;
            }
            void Remove_Head() {
                if (size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                if (size==1) {
                    delete head;
                    head = tail = NULL;
                    size = 0;
                    return;
                }
                Node<T>* tmp = head->step();
                delete head;
                head = tmp;
                size--;
            }
            void Remove_Tail() {
                if (size==0) {
                    std::cout << "Empty List" << std::endl;
                    return;
                }
                if (size==1) {
                    delete head;
                    head = tail = NULL;
                    size = 0;
                    return;
                }
                Node<T>* tmp = head;
                while (tmp->step()!=tail) {tmp = tmp->step();}
                delete tail;
                tail = tmp;
                tail->Append(NULL);
                size--;
            }
            int List_Size(){return size;}
            Node<T>* List_Head(){return head;}
            Node<T>* List_Tail(){return tail;}
            int List_Search(T dat) {
                int i = -1;
                int count = 0;
                Node<T>* tmp = head;
                while (tmp!=NULL) {
                    if (tmp->show()==dat) {
                        i = count;
                        break;
                    }
                    count++;
                    tmp = tmp->step();
                }
                return i;
            }
            void List_Merge(Linked_List<T> b) {
                Node<T>* tmp = b.List_Head();
                while (tmp!=NULL) {
                    Insert_Tail(tmp->show());
                    tmp = tmp->step();
                }
            }
        private:
            Node<T> *head,*tail;
            int size;
    };
}
#endif