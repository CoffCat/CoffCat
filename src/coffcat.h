#ifndef __COFFCAT_H__
#define __COFFCAT_H__

typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned long	DWORD;


typedef struct User{
	int		UserNo;
	char	UserName[32];
	char	PWD[32];
	char	Address[256];
}User;

#endif