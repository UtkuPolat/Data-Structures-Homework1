#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
struct node{
	T info;
	node<T> *link;
};
template <class T>
class LL{
	protected:
		node<T> *head,*last;
		int count;
	public:
		LL();
		~LL();
		bool emptyList();
		int length(){
			return count;
		}
		T front();
		T back();
		void destroyList();
		node<T>* search(T&);
		void insertFirst(T&);
		void insertLast(T&);
		void deleteNode(T&);
		friend ostream& operator<<(ostream &os,LL<T> &lst){
			node<T> *p=lst.head;
				while(p!=NULL){
					os<<p->info;
					p=p->link;
				}
			return os;
		}
};
template <class T>
LL<T>::LL(){
	head=last=NULL;
	count=0;
}
template <class T>
LL<T>::~LL(){
	destroyList();
}
template <class T>
void LL<T>::destroyList(){
	node<T> *p;
	while(head!=NULL){
		p=head;
		head=head->link;
		delete p;
	}
	last=NULL;
	count=0;
}
template <class T>
bool LL<T>::emptyList(){
	return head==NULL;
}
template <class T>
T LL<T>::front(){
	assert(head!=NULL);
	return head->info;
}
template <class T>
T LL<T>::back(){
	assert(last!=NULL);
	return last->info;
}
template <class T>
node<T>* LL<T>::search(T &item){
	bool found=false;
	node<T> *p=head;
	while(p != NULL && !found){
		if(p->info==item)
			found=true;
		else 
			p=p->link;
	}
	return p;
}
template <class T>
void LL<T>::insertFirst(T &item){
	node<T> *p=new node<T>;
	p->info=item;
	p->link=head;
	head=p;
	if(last==NULL)
		last=head;
	count++;
}
template <class T>
void LL<T>::insertLast(T &item){
	node<T> *p=new node<T>;
	p->info=item;
	p->link=NULL;
	if(last!=NULL){
		last->link=p;
		last=p;
	}
	else 
		head=last=p;
	count++;
}

template <class T>
void LL<T>::deleteNode(T &item){
	node<T> *p,*q;
	bool found=false;
	if(head==NULL)
		cerr<<"List is empty";
	else{
		if(head->info==item){
			p=head;
			head=head->link;
			delete p;
			count--;
			if(head==NULL)
				last=NULL;
		}
		else{
			p=head;
			q=head->link;
			while(q!=NULL && !found){
				if(q->info==item)
					found=true;
				else{
					p=q;
					q=q->link;
				}					
			}
		}
		if(found){
			p->link=q->link;
			count--;
		    if(last==q)
				last=p;
    		delete q;
		}
	}
}

#endif
