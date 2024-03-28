# miniprojects-2024
부경대 2024 IoT 개발자과정 미니프로젝트 리포지토리

## 1. 상품관리 프로그램
- Product Manager

	```
	File : Product Manager.cpp
	Created : 24-03-06
	Lang : C++
	```

	- 부모클래스 생성, 자식클래스 생성 및 부모클래스 상속
	- 상품 추가, 출력, 검색, 프로그램 종료 기능을 함수로 작성, 구현

## 2. 파일로그인
- File 입출력

	```
	File : project01.c
		myinfo.txt
	Created : 24-03-13
	Lang : C
	```

	- myinfo.txt 파일에 회원(개인정보) 저장
	- 아이디와 비밀번호를 입력받아 일치하면 파일을 읽어온다
	- 불일치 시, 각 상황에 맞는 문구 출력  
		&rarr; 아이디/비밀번호 중 하나만 오류일 때, 보안강화를 위한 하나의 문구로 통합출력

## 3. 도서관리 프로그램
- LinkedList
	- 연결리스트 자료구조
	- 도서 등록, 검색, 삭제, 출력, 프로그램 종료 기능을 함수로 작성, 구현
		- ver1 : 검색도서의 유무확인
		
			```
			File : project02_ver1.c
			Created : 24-03-27
			Lang : C
			```
			
		- ver2 : 검색 후 대여/반납 기능 추가 / 파일분할 / makefile
		
			```
			File : project02_ver2.c
				project02_ver2.h
				project02_ver2_main.c
			Created : 24-03-27
			Lang : C
			```