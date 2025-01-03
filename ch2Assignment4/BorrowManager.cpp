#include <utility> //tuple �̿� 
#include <iostream>
#include <iomanip>
#include "BookManager.h"
#include "BorrowManager.h"
#include "Book.h"
BorrowManager::BorrowManager()
{
}

BorrowManager::~BorrowManager()
{
}

void BorrowManager::initializeStock(Book book, int quantity)
{
	_stock.insert(std::make_pair(book._info.second/*å�̸�*/, quantity));
}
//
void BorrowManager::borrowBook(std::string title)
{
	////1. å�̸� �ΰ��

	////2. �۰��� ������ ��� -> �б�ó�� ����å ������? 


	//auto &m = _stock; //����
	////�뿩 �ߴ��� Ȯ�� (å �̸��� �ϳ��� ����) 

	//auto it = std::find(m.begin(), m.end(),title );//map�̶� �̹�� x
	auto it = _stock.find(title);

	if (it != _stock.end())
	{
		//ã�Ҵٸ�

		//1. ��� üũ
		if (it->second > 0)//��� �ִٸ�
		{

			//2. ��� ������ ����-1 ���Ƚ��ϴ� ���
			it->second -= 1;
			std::cout << "�뿩 �ƽ��ϴ�. �뿩�� å�̸�: " << it->first << "\n";
		}
		else //��� �� 0�̶��..
		{
			//3. ��� ���ٸ� ��� �����ϴ�. 
			std::cout << "�˼��մϴ�. ��� �뿩�ƽ��ϴ�...��� �뿩�� å�̸�: " << it->first << "\n";
		}
	}
	else
	{
		//�ƿ� ���� 
		//�������� �ʴ� å�Դϴ�. ��� 

		std::cout << title<<"�� �������� �ʴ� å�Դϴ�..\n";
	}

	std::cout << "\n\n";

}

void BorrowManager::borrowBookAuthor(std::string author)
{
	//1. 

}

void BorrowManager::returnBook(std::string title)
{
	//auto& m = _stock; //����
	//å�ݳ��ϱ�
	auto it = _stock.find(title);

	if (it != _stock.end())//�������� �ִ� å�̶��...
	{
		//1. ��� üũ 3�̸��� ���
		if (it->second < 3)
		{
			it->second += 1;
			std::cout << "�ݳ��ƽ��ϴ�. �ݳ��� å�̸�: " << it->first << "\n";
		}
		else//2. ��� üũ 3�ʰ� �ΰ��
		{
			std::cout<<"�̹� å��� �� á���ϴ�.. �ٸ� ������ �ݳ����ּ���. �ݳ��� å�̸�: " 
				     << it->first << "\n";
		}
	}
	else
	{
		//�ƿ� ���� 
		//�������� �ʴ� å�Դϴ�. ��� 
		std::cout << " �������� �ʴ� å�Դϴ�.. �ٸ� �������� ã�ư�����.\n";
	}
	std::cout << "\n\n";
}

void BorrowManager::displayStock()
{

	// ����� �� ����
	const int authorWidth = 20;   // ���� ��� ��
	const int titleWidth = 20;   // å ���� ��� ��
	const int stockWidth = 20;

	std::cout << "###�뿩 ���###\n";

	// ��� ���
	std::cout /*<< std::left << std::setw(authorWidth) << "����"*/
			  << std::setw(titleWidth) << "å����"
			  << std::setw(stockWidth) << "����å ����" << std::endl;
	std::cout << std::string(/*authorWidth +*/ titleWidth + stockWidth, '-') << std::endl;

	for (auto info : _stock)
	{
		std::cout << std::left << std::setw(authorWidth) << info.first
			<< std::setw(titleWidth) << info.second << std::endl;
	}

	std::cout << "\n\n";

	////const auto vec = BookManager::GetInstance()->getBmVector();
	//const std::vector<Book>& _books = BookManager::GetInstance()->getBmVector();

	//å ���, ���� ����



	std::cout << "\n\n";


}

