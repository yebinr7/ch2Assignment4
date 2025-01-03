#pragma once
#include <string>//��¿������
#include <unordered_map>

class Book;//��Ŀ�� �˾Ƽ� ã�ƶ�
class BorrowManager
{
public:
	BorrowManager();
	~BorrowManager();
public:
	//��ü�� ���� ���� staticŬ���� �Լ� 
	static BorrowManager* GetInstance() //�� �Լ��� ������ ������ �����ϴ� ��ü�� �ּ� �׻� ��� �� �� �ִ�.
	{
		static BorrowManager bm;//������ ������ �����ϴ� ��ü 
		return &bm;
	}

public:
	//�ʱ�å ���� ����
	void initializeStock(Book book, int quantity=3);
	
	//å �̸� �뿩 ���� �˻�& �뿩
	void borrowBook(std::string title);

	//å �۰� �뿩 ���� �˻�& �뿩
	void borrowBookAuthor(std::string author);

	//å �ݳ� �̸�����
	void returnBook(std::string title);

	//��� å�� �뿩 ���� Ȯ��
	void displayStock();



private:
	//å�̸�, å����
	std::unordered_map<std::string, int> _stock;


};


