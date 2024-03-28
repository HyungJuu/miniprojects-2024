/*
	File : project01.c

	Created : 24-03-13
	Author : 김근아
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// 함수선언
int login(char*, char*);
void fileOpen();

// 메인함수
void main()
{
    char myID[SIZE];
    char myPWD[SIZE];
    printf("[아이디와 비밀번호를 입력하세요]\n");

    while(1)
    {
        printf("아이디 입력 >> ");
        scanf("%s", myID);

        printf("비밀번호 입력 >> ");
        scanf("%s", myPWD);
        printf("\n");

        int num = login(myID, myPWD);

        switch(num)
        {
            case 1:
                fileOpen(); // 로그인 성공 - 아이디 비밀번호 모두 일치
                exit(1);
                break;
            
            case 2: // 로그인 실패 - 아이디 또는 비밀번호가 다를 경우
                break;

            case 0: // 회원이 아님 - 아이디와 비밀번호 모두 틀릴경우
                break;
        }
    }
}

// 함수 정의
int login(char* myID, char* myPWD)
{
    char ID[] = "KGA";
    char PWD[] = "20001122";
    
    if(strcmp(ID, myID) == 0 && strcmp(PWD, myPWD) == 0) // 아이디, 비밀번호 O
    {
        printf("[로그인 성공. 회원정보를 열람합니다.]\n");
        printf("\n");
        return 1;
    }
    
    if(strcmp(ID, myID) != 0 && strcmp(PWD, myPWD) != 0) // 아이디, 비밀번호 X
    {
        printf("[존재하지 않는 회원입니다.]\n");
        printf("\n");
        return 0;
    }    

    else    // 아이디 또는 비밀번호 오류
    {
        printf("[아이디 또는 비밀번호가 일치하지 않습니다.]\n");
        printf("\n");
        return 2;
    }
}

void fileOpen()
{
    char myinfo[SIZE];

    FILE* fp;

    fp = fopen("myinfo.txt", "r");
    printf("*****개인정보*****\n");
    while(fgets(myinfo, sizeof(myinfo), fp) != NULL)
    {
        printf("%s", myinfo);
    }
    fclose(fp);
}