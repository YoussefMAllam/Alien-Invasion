#pragma once
#include "LinkedQueue.h"

template <typename T>
class Deque:public LinkedQueue<T> {
	int count=0;
public:
	bool enqueue_back(const T& x) {
		if (this->isEmpty()) {
			this->enqueue(x);
			return true;
		}
		Node<T>* p = new Node<T>;
		p->setItem(x);
		this->backPtr->setNext(p);
		this->backPtr = p;
		count++;
		return true;
	}
	

	bool enqueue_front(const T& x) {
		if(this->isEmpty()) {
			this->enqueue(x);
			count++;
			return true;
		}
		else {
			Node<T>* p = new Node<T>;
			p->setItem(x);
			p->setNext(this->frontPtr);
			this->frontPtr = p;
			count++;
			return true;
		}
	}

	bool double_dequeue(T &r1, T &r2) {
		if (this->isEmpty()) {
			return false;
		}
		if(this->frontPtr == this->backPtr ) {
			delete this->frontPtr;
			this->frontPtr = nullptr;
			this->backPtr= nullptr;
			count--;
			return true;
		}
		else
		{
			Node<T>* newfront = this->frontPtr->getNext();
			Node<T>* newrear = this->frontPtr;
			while(newrear->getNext()!= this->backPtr) {
				newrear = newrear->getNext();
			}
			if(newfront==this->backPtr && newrear==this->frontPtr) {
				r1 = this->frontPtr->getItem();
				r2 = this->backPtr->getItem();
				this->frontPtr = nullptr;
				this->backPtr = nullptr;
				return true;
			}
			r1= this->frontPtr->getItem();
			r2= this->backPtr->getItem();
			this->frontPtr = newfront;
			this->backPtr = newrear;
			newrear->setNext(nullptr);
			count = count - 2;
			return true;
		}
	}
	void peek_front(T &r) {
		if(this->isEmpty()) {
			return;
		}
		r = this->frontPtr->getItem();
	}

	void peek_back(T &r) {
		if(this->isEmpty()) {
			return;
		}
		r = this->backPtr->getItem();
	}
	void printDQ() {
		Node<T>* left = this->frontPtr;
		while (left != nullptr) {
			cout << left->getItem();
			if (left->getNext()) { cout << ","; }
			left = left->getNext();
		}
	}
};