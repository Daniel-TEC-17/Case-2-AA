#ifndef _queue_
#define _queue_

#include "simpleList.h"
#include <iostream>

using namespace std;

template <class T>
class Queue: public SimpleList<T>{
public:
	Node<T>* getFront(){
		if(this->size == 0){
			cout<<"The queue is empty\n";
		}
		return this->getFirst();
	};
	void enqueue(T &pData){
		this->insertEnd(pData);
	};
	void dequeue(){
		this->deleteBegin();
	};

	void showQueue(){
		this->showList();
	};
};
#endif