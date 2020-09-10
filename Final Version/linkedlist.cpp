//
// Created by user on 9/8/2020.
//

#include <iostream>
#include "linkedlist.h"

template <typename T1,typename T2>
int linkedlist<T1,T2>::size()
{
    return this->nodes;
}

template <typename T1,typename T2>
Node<T1,T2>* linkedlist<T1,T2>::front()
{
    return this->head;
}

template <typename T1,typename T2>
Node<T1,T2>* linkedlist<T1,T2>::back()
{
    return this->tail;
}

template <typename T1,typename T2>
void linkedlist<T1,T2>::pop_front()
{
    if(nodes>1)
    {
        this->head = this->head->next;
        this->head->prev= nullptr;
    }
    else if(nodes==1)
    {
        this->head= nullptr;
        this->tail= nullptr;
    }

    this->nodes--;

}

template <typename T1,typename T2>
void linkedlist<T1,T2>::push_front(Node<T1,T2>* nuevo)
{
    if(nodes==0)
    {
        this->head=nuevo;
        this->tail=nuevo;
        nuevo->next= nullptr;
    }
    else{
        nuevo->next=this->head;
        this->head->prev=nuevo;
        this->head=nuevo;
    }
    this->nodes++;
}

template <typename T1,typename T2>
void linkedlist<T1,T2>::pop_back()
{
    if(nodes!=0)
    {
        auto temp=this->tail;
        if(nodes>1)
        {
            this->tail=this->tail->prev;
            this->tail->next= nullptr;
        }
        else{
            this->head= nullptr;
            this->tail= nullptr;
        }
        this->nodes--;
    }
}

template <typename T1,typename T2>
void linkedlist<T1,T2>::push_back(Node<T1,T2>* nuevo)
{
    if(nodes==0)
    {
        this->head=nuevo;
        this->tail=nuevo;
        nuevo->next= nullptr;
    }
    else{
        this->tail->next=nuevo;
        nuevo->prev=this->tail;
        this->tail=nuevo;
        this->tail->next= nullptr;
    }
    this->nodes++;
}

template <typename T1,typename T2>
void linkedlist<T1,T2>::move_to_back(Node<T1, T2> *node)
{
    if(node!=this->tail) {
        if (node == this->head) {
            this->head = node->next;
            this->head->prev = nullptr;
            this->tail->next = node;
            node->prev = this->tail;
            node->next = nullptr;
            this->tail = node;
        } else if (node != this->tail) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            this->tail->next = node;
            node->prev = this->tail;
            node->next = nullptr;
            this->tail = node;
        }
    }
}

template <typename T1,typename T2>
void linkedlist<T1,T2>::imprimir_inverso(){
    auto aux=this->tail;
    if(this->head!=this->tail) {
        do {
            cout<<aux->key<<" : "<<aux->data << " / ";
            aux = aux->prev;
        } while (aux != this->head);
        cout <<aux->key<<" : "<<aux->data << " / ";
    }
    else
        cout<<aux->data;
}

template <typename T1,typename T2>
void linkedlist<T1,T2>::imprimir() {
    auto aux = this->head;
    while (aux != nullptr) {
        cout <<aux->key<<" : "<<aux->data << " / ";
        aux = aux->next;
    }
}