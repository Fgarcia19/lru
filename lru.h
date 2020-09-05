//
// Created by user on 9/5/2020.
//

#ifndef UNTITLED3_LRU_H
#define UNTITLED3_LRU_H

using namespace std;
template <typename T>
struct Node {
    string key;
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class LRU{
    Node<T>* head;
    Node<T>* tail;
    int nodes;
    int size;
public:
    LRU(int n)
    {
        nodes=0;
        size=n;
        head= nullptr;
        tail= nullptr;
    }

    void imprimir_inverso(){
        auto aux=this->tail;
        if(this->head!=this->tail) {
            do {
                cout << aux->data << " ";
                aux = aux->prev;
            } while (aux != this->head);
            cout << aux->data;
        }
        else
            cout<<aux->data;
    }

    void imprimir() {
        auto aux = this->head;
        while (aux != nullptr) {
            cout << aux->data << " ";
            aux = aux->next;
        }
    }


    void insert(std::string key,T value)
    {
        auto nuevo=new Node<T>;
        nuevo->data=value;
        nuevo->key=key;



        if(nodes<size)
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
        else
        {
            this->head->key=key;
            this->head->data=value;
            auto aux=this->head;


            aux->next->prev= nullptr;
            this->head=aux->next;
            this->tail->next=aux;
            aux->prev=this->tail;
            this->tail=aux;
            this->tail->next= nullptr;
        }
    }

    Node<T>* getMostRecent()
    {
        return this->tail;
    }

    bool getValuefrom(string key)
    {
        if(this->tail->key==key)
        {
            cout<<this->tail->data;
            return 0;
        }
        auto aux=this->head;
        if(this->head->key==key)
        {
            aux->next->prev= nullptr;
            this->head=aux->next;
            this->tail->next=aux;
            aux->prev=this->tail;
            this->tail=aux;
            cout<< aux->data;
            return 0;

        }

        while(aux->key!=key) {

            aux = aux->next;
            if(aux== nullptr)
                break;
        }

        if(aux== nullptr)
        {
            cout<<"No encontrado"<<endl;
            return 0;
        }
        else {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            this->tail->next = aux;
            aux->prev = this->tail;
            aux->next = nullptr;
            this->tail = aux;
            cout<< aux->data;
        }
        return 0;
    }
};




#endif //UNTITLED3_LRU_H
