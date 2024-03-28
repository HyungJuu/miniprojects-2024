/*
	File : Product Manager

	Created : 24-03-06
	Author : 김근아
*/

#include <iostream>
#include <string>
using namespace std;

// 부모클래스
class Product
{
protected:
	string id;
	int price;
	string producer;

public:
	Product(string aid, int aprice, string aproducer)
		: id(aid), price(aprice), producer(aproducer)
	{ }

	virtual void ShowInfo() const
	{
		cout << "ID : " << id << ", 가격 : " << price << ", 제조사 : " << producer << endl;
	}

	string getId() const
	{
		return id;
	}

	virtual ~Product() {}
};

// 자식클래스
class Book : public Product
{
private:
	string ISBN; 	// 고유번호  ex) 978-89-001-0001-1
	string author;	// 저자
	string title;	// 제목

public:
	Book(string aid, int aprice, string aproducer, string aISBN, string aauthor, string atitle)
		: Product(aid, aprice, aproducer), ISBN(aISBN), author(aauthor), title(atitle)
	{ }

	void ShowInfo() const
	{
		Product::ShowInfo();
		cout << "고유번호 : " << ISBN << ", 저자 : " << author << ", 제목 : " << title << endl;
		cout << "************************************************" << endl;
	}
};

class Handphone : public Product
{
private:
	string model;	// 모델명
	int RAM;		// 램 크기

public:
	Handphone(string aid, int aprice, string aproducer, string amodel, int aRAM)
		: Product(aid, aprice, aproducer), model(amodel), RAM(aRAM)
	{ }

	void ShowInfo() const
	{
		Product::ShowInfo();
		cout << "모델명 : " << model << ", 램 크기 : " << RAM << "GB" << endl;
		cout << "************************************************" << endl;
	}
};

class Computer : public Product
{
private:
	string model;	// 모델명
	int cpu;		// cpu 크기
	int RAM;		// 램 크기

public:
	Computer(string aid, int aprice, string aproducer, string amodel, int acpu, int aRAM)
		: Product(aid, aprice, aproducer), model(amodel), cpu(acpu), RAM(aRAM)
	{ }

	void ShowInfo() const
	{
		Product::ShowInfo();
		cout << "모델명 : " << model << ", CPU 크기 : " << cpu << ", 램 크기 : " << RAM << "GB" << endl;
		cout << "************************************************" << endl;
	}
};

int main()
{
	Product* products[100];
	int num;
	char product = {};

	while (1)
	{
		printf("-----------------상품관리 프로그램-----------------\n");
		printf("1. 상품추가 / 2. 상품출력 / 3. 상품검색 / 0. 종료\n");
		cout << "번호 입력 >> ";
		cin >> num;
		cout << endl;

		if (num == 1)
		{
			int pnum1;
			string id;
			int price;
			string producer;

			cout << "[상품 종류 선택] " << endl;;
			cout << " >> 1. 책 / 2. 핸드폰 / 3.컴퓨터" << endl;;
			cout << "번호 입력 >> ";
			cin >> pnum1;
			cout << endl;

			cout << "ID 입력 >> ";
			cin >> id;
			cout << "가격 입력 >> ";
			cin >> price;
			cout << "제조사 입력 >> ";
			cin >> producer;
			cout << endl;


			if (pnum1 == 1)
			{
				string ISBN, author, title;

				cout << "고유번호 입력 >> ";
				cin >> ISBN;
				cout << "저자 입력 >> ";
				cin >> author;
				cout << "제목 입력 >> ";
				cin >> title;

				products[product++] = new Book(id, price, producer, ISBN, author, title);
			}

			else if (pnum1 == 2) {
				string model;
				int RAM;
				cout << "모델명 입력 >> ";
				cin >> model;
				cout << "램크기 입력(GB) >> ";
				cin >> RAM;

				products[product++] = new Handphone(id, price, producer, model, RAM);
			}

			else if (pnum1 == 3) {
				string model;
				int cpu, RAM;
				cout << "모델명 입력 >> ";
				cin >> model;
				cout << "CPU 크기 입력 >> ";
				cin >> cpu;
				cout << "램크기 입력(GB) >> ";
				cin >> RAM;

				products[product++] = new Computer(id, price, producer, model, cpu, RAM);
			}

			else 
			{
				cout << "잘못된 입력입니다." << endl;
				continue;
			}
		}

		else if (num == 2)
		{
			cout << "<< 상품 출력 >> " << endl;
			for (int i = 0; i < product; ++i)
			{
				products[i]->ShowInfo();
				cout << endl;
			}
		}

		else if (num == 3)
		{
			string id;
			cout << "<< 상품 검색 >> " << endl;
			cout << "검색할 상품의 ID를 입력하세요 >> ";
			cin >> id;
			cout << endl;

			bool found = false;
			for (int i = 0; i < product; ++i)
			{
				if (products[i]->getId() == id)
				{
					cout << "<< 검색 결과 >> " << endl;
					products[i]->ShowInfo();
					found = true;
				}
			}
			if(!found)
			{
				cout << "검색 결과가 없습니다." << endl << endl;
			}
		}

		else if (num == 0)
		{
			cout << "프로그램을 종료합니다." << endl;;
			break;
		}

		else
		{
			cout << "잘못된 입력입니다. 해당 선택지 안에서 입력하세요." << endl;
			continue;
		}

	}

	return 0;
}