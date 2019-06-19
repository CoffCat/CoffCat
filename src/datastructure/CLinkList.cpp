#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "CLinkList.h"
//#include "DateType.h"

using namespace std;

Node* CLinkList::GetNode(int pos)
{
	cout<<"CLinkList::GetNode():"<<pos<<endl;
	cur = head;

	if(cur->next == tail || num ==0){
		cout<<"list is empty!"<<endl;
		return NULL ;
	}

	for(int i=0;i<pos;i++)
		cur = cur->next;
	
	return cur;
}


// int CLinkList::PrintAll(){
// 	cur = head->next;
// 	do{		
// 		cout<<"Address of cur is:"<<cur<<endl;
// 		PrintNode((User*)cur->data);
// 		cur = cur->next;
// 	}while(cur->next);
// 	cur = head;
// 	return 0;
// }

CLinkList::CLinkList()
{
	Init();
}


CLinkList::~CLinkList()
{

}

int CLinkList::Init()
{
	head = new Node();
	tail = new Node();
	
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
	cur = head;
	cout<<"CLinkList::Init()  head = "<< head<<"   tail = "<<tail<<"  cur = "<<cur<<endl;
	return 0;
}

int CLinkList::Free()
{
    /*delete all node*/
	delete head;
	delete tail;
	return 0;
}

int CLinkList::AddNode(DWORD* data,int pos)
{
	if(!data) {
		return -1;
	}
	
	Node* node = new Node();
	node->data = data;

	switch(pos)
	{
		case 0:{
			//在链表前部插入
			cur = head->next;
			head->next = node;
			node->next = cur;
			node->prev = head;
			
			num += 1;
			cur = head;
			break;
		}
		case 1:{
			//在链表尾部添加
			node->prev = tail->prev;
			node->next = tail;
			tail->prev->next = node;
			tail->prev = node;
		
			num += 1;
			cur = head;
			break;
		}

	}
 
	return 0;
}

int CLinkList::DelNode(int pos)
{
	Node* node;
	if(pos){
		cur = head;
		for(int i=0;i<pos;i++)
			cur = cur->next;
		node = cur;

		// cout<<"DelNode(): "<<PrintNode((User*)node->data)<<endl;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		
		delete node;
		return 0;
	}else
	return -1;
}

int CLinkList::GetNum(){
	return num;
}

Node* CLinkList::Head(){
		
	cur = head;
	return cur;
}

Node* CLinkList::First(){
	if (num<=0) return NULL;
	
	cur = head->next;
	return cur;
}

Node* CLinkList::Next(){
	if (num<=0) return NULL;
	
	cur = cur->next;
	return cur;
}

Node* CLinkList::Tail(){
	if (num<=0) return NULL;
	
	cur = tail->prev;
	return cur;
}

int CLinkList::IsEnd(){
	
	if(cur->next == tail)
		return 1;
	
	return 0;
}