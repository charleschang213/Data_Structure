#ifndef HEAP_H
#define HEAP_H
#include <iostream>

namespace Charles{
    template<class T>
    class Heap{
        public:
            Heap(int maxsize):MaxSize(maxsize),Size(0){
                s = new T[maxsize];                
            }
            ~Heap(){delete s;}
            void Append(const T x){
                if (Size==MaxSize){
                    std::cout << "Full Heap" << std::endl;
                    return;
                }
                Size = Size+1;
                s[Size-1] = x;
            }
            Void Serve(T& x){
                if (Size==0){
                    std::cout << "Empty Heap" << std::endl;
                    return;
                }
                x = s[0];
                s[0] = s[Size-1];
                Size--;
            }
            void Create_Heap(){
                for (int i = (Size-2)/2;i>-1;i--) Adjust_Down(i);
            }
            void Output(){
                for (int i=0;i<Size;i++) {std::cout << s[i] << " ";}
                std::cout << std::endl;
            }
        private:
            T* s;
            int MaxSize,Size;
            void Adjust_Down(int r){
                int child = 2*r+1;
                T temp = s[r];
                while (child<=Size-1){
                    if ((child<Size-1)&&(s[child]>s[child+1])) child++;
                    if (temp<=s[child]) break;
                    s[(child-1)/2] = s[child];
                    child = child*2+1;
                }
                s[(child-1)/2] = temp;
            }
            void Adjust_Up(){
                int i = Size-1;temp = s[i];
                while ((i>0)&&temp<s[(i-1)/2]){
                    s[i] = s[(i-1)/2];i = (i-1)/2;
                }
                s[i] = temp;
            }
    };
}

#endif