#include "CMemberList.h"
#include <iostream>
#include <string.h>

using namespace std;

CMemberList::CMemberList()
{
	
}


CMemberList::~CMemberList()
{
    
}

int CMemberList::PrintUser(User* puser){
    cout<<"CMemberList::PrintUser()"<<endl;
    if(puser) {
	    cout<<puser->UserNo<<"\t"<<puser->UserName<<"\t"<<puser->Address<<"\t"<<puser->PWD<<"\t"<<endl;
        return 0;
    }else
    cout<<"no user to print"<<endl;

    return 0;
}

User* CMemberList::GetUser(char* username){
	User* puser = (User*)list.Head()->data;

    do{
        puser = (User*)list.Next()->data;
        if(strcmp((puser->UserName),username)==0)
            return puser;
    }while(!list.IsEnd());
    return NULL;
}

int CMemberList::ab(){
    cout<<"ab"<<endl;
    return 0;
}
int CMemberList::AddUser(User* puser){

    list.AddNode((DWORD*)puser,1);
	
    return 0;
}


User* CMemberList::First(){

    User* puser = (User*)list.First()->data;
   
    return puser;
}

User* CMemberList::Tail(){

    User* puser = (User*)list.Tail()->data;
   
    return puser;
}