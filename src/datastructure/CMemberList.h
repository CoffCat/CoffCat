#ifndef __CMemberList_H__
#define __CMemberList_H__

#include "../coffcat.h"
#include "CLinkList.h"

class CMemberList
{
    private:
		CLinkList list;
    public:
		CMemberList();
		~CMemberList();
    public:
		int AddUser(User* puser);
		User* First();
		User* Tail();
		User* GetUser(char* username);
		int PrintUser(User* puser);
		int FindNode(char* mess, int col);
		int ab();
};

#endif