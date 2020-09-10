//
// Created by user on 9/8/2020.
//

#ifndef UNTITLED3_LINKEDLIST_H
#define UNTITLED3_LINKEDLIST_H


//#include <string>
//#include <iostream>

using namespace std;

template <typename T1,typename T2>
struct Node {
    T1 key;
    T2 data;
    Node<T1,T2>* next;
    Node<T1,T2>* prev;
};

template <typename T1,typename T2>
class linkedlist {
private:
    Node<T1,T2>* head;
    Node<T1,T2>* tail;
    int nodes;
public:
    linkedlist(): head(nullptr), tail(nullptr), nodes(0) {};
    int size();
    void pop_front();
    Node<T1,T2>*front();
    Node<T1,T2>*back();
    void push_front(Node<T1,T2>* value);
    void pop_back();
    void push_back(Node<T1,T2>* value);
    void move_to_back(Node<T1,T2>* value);
    void imprimir();
    void imprimir_inverso();
};


#endif //UNTITLED3_LINKEDLIST_H
