#ifndef _stack_
#define _stack_

#include "simpleList.h"
#include <iostream>

using namespace std;

template <class T>
class Stack: public SimpleList<T>{
public:
	void push(T &pData){
		this->insertBegin(pData);
	};

	void pop(){
		this->deleteBegin();
	};

	Node<T>* getTop(){
		if(this->size == 0){
			cout<<"Empty stack \n";
		}
			return this->getFirst();
		
	};

	void showStack(){
		if(this->size == 0){
			cout<<"Empty stack"<<endl;

		}
		else{
			cout<<"__\n";
			Node<T>* current = NULL;
			current = this->first;
			while(current != NULL){
				cout<<*current->getDataNode()<<endl;
				cout<<"||"<<endl;
				current = current->getNext();
			}
			cout<<"__\n";
		}
	};

};
#endif