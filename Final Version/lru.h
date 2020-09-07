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
    unordered_map<string,Node<T>*> table;
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
                cout << aux->key<<" : "<<aux->data << " / ";
                aux = aux->prev;
            } while (aux != this->head);
            cout << aux->key<<" : "<<aux->data << " / ";
        }
        else
            cout<<aux->data;
    }

    void imprimir() {
        auto aux = this->head;
        while (aux != nullptr) {
            cout << aux->key<<" : "<<aux->data << " / ";
            aux = aux->next;
        }
    }


    void insert(std::string key,T value)
    {
        auto nuevo=new Node<T>;
        nuevo->data=value;
        nuevo->key=key;

        if(table[key]!=nullptr)
        {
            table[key]->data=value;
            searchvalue(key);
        }
        else if(nodes<size)
        {
            table[key]=nuevo;
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
            table.erase(this->head->key);
            this->head->key=key;
            this->head->data=value;
            auto aux=this->head;


            aux->next->prev= nullptr;
            this->head=aux->next;
            this->tail->next=aux;
            aux->prev=this->tail;
            this->tail=aux;
            this->tail->next= nullptr;
            table[key]=this->tail;


        }
    }

    Node<T>* getMostRecent()
    {
        return this->tail;
    }

    void getValuefrom(string key)
    {
        auto aux=searchvalue(key);
        if (aux == nullptr)
            cout<<"No encontrado"<<endl;
        else
            cout<<aux->data<<endl;
    }

    Node<T>* searchvalue(string key)
    {
        if(this->tail->key==key)
        {
            return this->tail;

        }
        auto aux=this->head;
        if(this->head->key==key)
        {
            aux->next->prev= nullptr;
            this->head=aux->next;
            this->tail->next=aux;
            aux->prev=this->tail;
            this->tail=aux;
            this->tail->next= nullptr;
            return  aux;

        }

        aux=table[key];


        if(aux== nullptr)
        {
            table.erase(key);
            return nullptr;
        }

        else {

            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            this->tail->next = aux;
            aux->prev = this->tail;
            aux->next = nullptr;
            this->tail = aux;
            return aux;
        }


    }



};




#endif //UNTITLED3_LRU_H
