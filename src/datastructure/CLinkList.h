#ifndef __CLinkList_H__
#define __CLinkList_H__

#include "../coffcat.h"

typedef struct Node{
	Node*	prev;
	DWORD*	data;
	Node*	next;
}Node;

class CLinkList
{
	private:
		Node *head,*tail,*cur;
		int	num=0;
		int eof=0;
	public:
		CLinkList();
		~CLinkList();
	public:
		int Init();
		int Free();
		Node* Head();
		Node* First();
		Node* Next();
		Node* Prev();
		Node* Tail();
		int IsEnd();
		int PrintAll();
		int AddNode(DWORD* data,int pos=0);
		int DelNode(int pos);
		Node* GetNode(int pos=0);
		int GetNum();
};

#endif