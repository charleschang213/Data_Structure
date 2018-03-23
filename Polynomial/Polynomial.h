#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include "List/List.h"

namespace Charles{
    class Term {
        public:
            Term(double a,double b):coeff(a),order(b){}
            double Coeff(){return coeff;}
            double Order(){return order;}
            void Print(){
                if (order==0) {std::cout << coeff;return;}
                if (order==1) {std::cout << "x^" << order;return;}
                if (order==-1) {std::cout << "-x^" << order;return;}
                std::cout << coeff << "x^" << order;
            }
            Term operator+(const Term& t) {
                if(order==t.order){
                    Term sum(coeff+t.coeff,order);
                    return sum;
                }
                std::cout << "The two cannot be summed to one term, the left term will be returned." << std::endl;
                Term a(coeff,order);
                return a;
            }
            Term operator*(const double& x) {
                Term product(coeff*x,order);
                return product;
            }
            friend Term operator*(const double& x, const Term& a) {
                Term product(a.coeff*x,a.order);
                return product;
            }
            Term operator*(const Term& b) {
                Term product(coeff*b.coeff,order+b.order);
                return product;
            }
            double Value(const double x) {
                double a = 1;
                for (int i=0;i<order;i++){
                    a = a*x;
                }
                return a*coeff;
            }
        private:
            double coeff;
            int order;
    };
    class Polynomial{
        public:
            Polynomial(int msize=100): List_Link(msize) {}
        private:
            List_Link<Term> s;
            int Length;
    };
}

#endif