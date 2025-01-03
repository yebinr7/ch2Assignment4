#pragma once
#include <iostream>//��¿�� ����..
#include <vector>
#include <utility> //tuple �̿� 

class Book;//���漱�� ��Ŀ�� �˾Ƽ� ã�Ƽ� �����ض�

class BookManager
{
public:
	BookManager();
	~BookManager();

public:
	//��ü�� ���� ���� staticŬ���� �Լ� 
	static BookManager* GetInstance() //�� �Լ��� ������ ������ �����ϴ� ��ü�� �ּ� �׻� ��� �� �� �ִ�.
	{
		static BookManager bm;//������ ������ �����ϴ� ��ü 
		return &bm;
	}


public:
	//���Ϳ� å�߰�
	 void addBook(Book book);
	 
	 //���Ͱ� �����ϴ� ��� å ��Ÿ����
	 void displayAllBooks();
	 
	 //�������� ã�Ƴ���: ������ �ִ�. ����,�۰� ���
	 void searchByTitle(std::string title);

	 //�۰��� ã�Ƴ���: ������ �ִ�, ����, �۰� ���, �����۰��� �۱ ������ 
	 void searchByAuthor(std::string author);

private:
	std::vector<Book> _books;
};

