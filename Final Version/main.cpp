#include <bits/stdc++.h>
#include <iostream>
#include "linkedlist.cpp"
#include "cache.cpp"
using namespace std;


template <typename T1,typename T2>
void LRU(Cache<T1,T2>* cache,T1 key, T2 data)
{
    if(cache->table[key]!=nullptr)
    {
        cache->table[key]->data=data;
        cache->nodes.move_to_back(cache->table[key]);
    }
    else if(cache->nodes.size()<cache->size)
    {
        auto nuevo=new Node<T1,T2>;
        nuevo->key=key;
        nuevo->data=data;
        cache->nodes.push_back(nuevo);
        cache->table[nuevo->key]=cache->nodes.back();
    }
    else
    {
        auto aux=cache->nodes.front();
        aux->key=key;
        aux->data=data;
        cache->nodes.move_to_back(aux);
        cache->table.erase(aux->key);
        cache->table[key]=aux;
    }
};


template <typename T1,typename T2>
void FIFO(Cache<T1,T2>* cache,T1 key, T2 data)
{

    if(cache->table[key]==nullptr) {
        if (cache->nodes.size() < cache->size) {
            auto nuevo = new Node<T1, T2>;
            nuevo->key = key;
            nuevo->data = data;
            cache->nodes.push_back(nuevo);
            cache->table[nuevo->key] = cache->nodes.front();
        } else {
            auto aux = cache->nodes.front();
            cache->table.erase(aux->key);
            aux->key = key;
            aux->data = data;
            cache->nodes.pop_front();
            cache->nodes.push_back(aux);
            cache->table[key] = aux;
        }
    }

};


int main()
{
    /*
     Los tiempos seran en O(1) ya que se realiza acceso directos a los nodos a travez del  unordered_map y todas las operaciones de la linkedlist tiennen tiempo de
     O(1), por lo tante tambien el Cache lo tendra de esta manera
     */
    cout<<"LRU"<<endl;
    auto a=Cache<int,int>(4,LRU);
    a.insert(1,2);
    a.insert(2,3);
    a.insert(3,4);
    a.getValuefrom(1);
    cout<<a.getMostRecent()->key<<" -> "<<a.getMostRecent()->data<<endl;
    a.insert(4,5);
    a.insert(5,6);
    a.getValuefrom(1);
    cout<<a.getMostRecent()->key<<" -> "<<a.getMostRecent()->data<<endl;
    a.getValuefrom(3);
    cout<<a.getMostRecent()->key<<" -> "<<a.getMostRecent()->data<<endl;
    a.ver();
    cout<<endl;
    cout<<"FIFO"<<endl;
    auto b=Cache<int,int>(4,FIFO);
    b.insert(1,2);
    b.insert(2,3);
    b.insert(3,4);
    b.getValuefrom(1);
    cout<<b.getMostRecent()->key<<" -> "<<b.getMostRecent()->data<<endl;
    b.insert(4,5);
    b.insert(5,6);
    b.getValuefrom(1);
    cout<<b.getMostRecent()->key<<" -> "<<b.getMostRecent()->data<<endl;
    b.getValuefrom(3);
    cout<<b.getMostRecent()->key<<" -> "<<b.getMostRecent()->data<<endl;
    b.ver();
}

