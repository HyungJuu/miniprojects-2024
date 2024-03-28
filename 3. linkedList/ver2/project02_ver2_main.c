/* 
    File : project02_ver2_main.c

    Created : 24-03-27
    Author : 김근아
*/
#include <stdio.h>
#include "project02_ver2.h"

void main() 
{
    int num;
    node* head = NULL;
    while(1)
    {
        printf("*****도서관리 프로그램*****\n");
        printf("1. 도서등록 \n2. 도서검색 \n3. 도서삭제 \n4. 도서출력 \n0. 종료\n");
        printf("---------------------------\n");
        printf("* 번호 입력 >> ");
        scanf("%d", &num);
        printf("\n");
        
        switch(num)
        {
            case 1:
                head = bookAdd(head);   // 도서등록 함수를 호출하여 head필드에 저장
                break;

            case 2:
                while(1)
                {
                    switch(bookSearchPrint())   // 검색방법에 대한 함수에서 리턴한 값을 받음
                    {
                        case 1:
                            search_T(head); // 제목을 검색할때의 함수 호출
                            rentalselect(head);
                            break;
                        
                        case 2:
                            search_A(head); // 저자를 검색할 때의 함수 호출
                            rentalselect(head);
                            break;

                        case 3:
                            search_P(head); // 출판사를 검색할 때의 함수 호출
                            rentalselect(head);
                            break;
                        
                        default:
                            printf("[잘못된 입력입니다. 번호(1~3)를 다시 입력하세요.]\n\n");
                            continue;
                    }
                    break;
                }
                break;
                
            case 3:
                head = bookDelete(head);    // 삭제후의 변경된 시작점을 받아서 head로 저장
                break;

            case 4:
                bookShow(head);
                break;

            case 0:
                printf("[프로그램을 종료합니다.]\n");
                exit(1);
                break;

            default:
                printf("[잘못된 입력입니다. 번호(0~4)를 다시 입력하세요.]\n\n");
        }
    }
}