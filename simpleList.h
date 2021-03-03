#ifndef _simpleList_
#define  _simpleList_

#include <iostream>
using namespace std;

//Clase Nodo que puede aceptar cualquier tipo
template <class T>
class Node{
private:
	//Puntero que almacena el dato
	T* data;
	//Puntero al siguiente nodo para mantener el enlace
	Node<T>* next;
public:
	//Constructores con y sin parametro
	Node(){
		this->data = NULL;
		this->next = NULL;

	}
	Node(T &pData){
		this->data = &pData;
		this->next = NULL;

	}
	//Retorna el puntero con el dato, contenido dentro del nodo
	T* getDataNode(){return this->data;};
	
	//Cambia el puntero del dato
	void setData(T &pData){
		this->data = &pData;
	}

	//Retorna el nodo siguiente
	Node<T>* getNext(){return this->next;};

	//Cambia el nodo siguiente
	void setNext(Node<T>* pNext ){this->next = pNext;};


};

//Clase listaSimple genérica implementando nodos genéricos
template <class T>
class SimpleList{
protected:
	//Punteros al primero y último nodo
	Node<T>* first;
	Node<T>* last;
	//Largo de lista
	int size;


public:
	//Constructor
	SimpleList(){
		this->first = NULL; 
		this->last = NULL;
		this->size = 0;
	}

	Node<T>* getFirst(){return this->first;};
	Node<T>* getLast(){return this->last;};
	bool isEmpty(){return this->size==0;};
	int getSize(){return this->size;};



	void insertBegin(T &pData){
		Node<T>* toInsert = NULL;
		toInsert = new Node<T>(pData);
		if(isEmpty()){
			//Si la lista está vacía el nodo insertado será el primero y ultimo
			this->first = toInsert;
			this->last = toInsert;
		}
		else{
			//Si no está vacía el nodo nuevo será asignado como primero
			//Y el anterior primero será el siguiente del nuevo nodo
			toInsert->setNext(this->first);
			this->first = toInsert;
		}
		this->size++;
	}

	void insertEnd(T &pData){
		Node<T>* toInsert = NULL;
		toInsert = new Node<T>(pData);
		if(isEmpty()){
			//Si la lista está vacía el nodo insertado será el primero y ultimo
			this->first = toInsert;
			this->last = toInsert;
		}

		else{
			//Si no está vacía el nodo nuevo se declara como el que le sigue al ultimo
			//Se declara el nuevo nodo como el ultimo
			this->last->setNext(toInsert);
			this->last = toInsert;
		}
		this->size++;
	}
	void deleteBegin(){
		if(isEmpty()){
			cout<<"The list have no elements \n";
		}
		else{
			//Se pone un apuntador auxiliar en el primero
			Node<T>* toDelete = NULL;
			toDelete = this->first;
			if(this->size == 1){
				//Si hay solo un elemento se pone primero y ultimo en null
				this->first = NULL;
				this->last = NULL;
			}
			else{	
				//Si hay más de un elemento se asigna como primero al
				//segundo elemento de la lista
				this->first = this->first->getNext();
			}
			//Se borra el primero
			delete toDelete;
			this->size--;
		}
		
	}
	void deleteEnd(){
		if(isEmpty()){
			cout<<"The list have no elements \n";
		}
		else{
			//Se pone un puntero en el ultimo elemento de la lista que será el eliminado
			//Y un pivote en el primero para recorrer la lista y encontrar el nuevo ultimo
			Node<T> *toErase, *pivot;
			pivot = NULL;
			pivot = this->first;
			toErase = NULL;
			toErase = this->last;
			if(this->size == 1){
				//Si hay solo un elemento se pone primero y ultimo en null
				this->first = NULL;
				this->last = NULL;
			}
			else{
				//Se corre el pivote hasta quedar en la penúltima posición
				while(pivot->getNext()!= this->last){
					pivot = pivot->getNext();
				}
				//Se asigna este pivote como el nuevo ultimo
				pivot->setNext(NULL);
				this->last = pivot;
			}
			//Se borra el ultimo elemento
			delete toErase;
			this->size--;
		}
		
	}
	void showList(){
		if(isEmpty()){
			cout<<"The list have no elements "<<endl;

		}
		else{
			Node<T>* current = NULL;
			current = this->first;
			while(current != NULL){
				cout<<*current->getDataNode()<<" -> ";
				current = current->getNext();
			}
			cout<<"\n";
		}
		

	}
};

#endif