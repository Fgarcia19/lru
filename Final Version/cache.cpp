//
// Created by user on 9/8/2020.
//
#include "cache.h"

template <typename T1,typename T2>
void Cache<T1,T2>::insert(T1 key, T2 value)
{
    funcion(this,key,value);
}

template <typename T1,typename T2>
Node<T1,T2>* Cache<T1,T2>::getMostRecent()
{
    return this->nodes.back();
}

template <typename T1,typename T2>
void Cache<T1,T2>::getValuefrom(T1 key)
{
    cout<<"For "<<key<<" value: ";
    if(this->table[key]!= nullptr) {
        funcion(this, key, this->table[key]->data);
        cout<<this->table[key]->data<<endl;
    }
    else
    {
        cout<<"None"<<endl;
        this->table.erase(key);
    }
}

template <typename T1,typename T2>
void Cache<T1,T2>::ver()
{
    this->nodes.imprimir();
    cout<<endl;
    this->nodes.imprimir_inverso();
}

