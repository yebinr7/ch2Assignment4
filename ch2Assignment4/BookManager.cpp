#include <iostream>
#include <iomanip>
#include "BookManager.h"
#include "Book.h"

BookManager::BookManager()
{

}

BookManager::~BookManager()
{
}

void BookManager::addBook(Book book)
{
	_books.emplace_back(book);
}

void BookManager::displayAllBooks()
{
	std::cout << "###�������� �ִ� å ���###\n";
	// ����� �� ����
	const int authorWidth = 20;   // ���� ��� ��
	const int titleWidth = 20;   // å ���� ��� ��

	// ��� ���
	std::cout << std::left << std::setw(authorWidth) << "����"
		<< std::setw(titleWidth) << "å����" << std::endl;
	std::cout << std::string(authorWidth + titleWidth, '-') << std::endl;

	// å ���
	for (auto book : _books)
		book.displayBook();

	std::cout << "\n\n";
}

void BookManager::searchByTitle(std::string title)
{
	std::cout << "###å �˻���...����: "<<title<<"###\n";


	bool find = false;
	for (auto iter : _books)
	{
		if (iter._info.second == title)
		{
			//ã������
			find = true;
			std::cout << "ã�ҽ��ϴ�!\n";

			// ����� �� ����
			const int authorWidth = 20;   // ���� ��� ��
			const int titleWidth = 20;   // å ���� ��� ��

			// ��� ���
			std::cout << std::left << std::setw(authorWidth) << "����"
				<< std::setw(titleWidth) << "å����" << std::endl;
			std::cout << std::string(authorWidth + titleWidth, '-') << std::endl;
		
			
			iter.displayBook();
		}
	}

	//��ã������
	if (find == false)
	{
		//�����ϴ�.
		std::cout << "ã���ô� å�� �����ϴ�.\n";
	}

	std::cout << "\n\n";
}

void BookManager::searchByAuthor(std::string author)
{
	std::cout << "###å �˻���...�۰�: " << author << "###\n";


	//�ѹ��� ��ȸ�ؼ� �÷��� Ű��
	bool find = false;
	for (auto iter : _books)
	{
		if (iter._info.first == author)
			find = true;//ã������	
	}

	if (find ==true)
	{
		// ����� �� ����
		const int authorWidth = 20;   // ���� ��� ��
		const int titleWidth = 20;   // å ���� ��� ��

		// ��� ���
		std::cout << std::left << std::setw(authorWidth) << "����"
			<< std::setw(titleWidth) << "å����" << std::endl;
		std::cout << std::string(authorWidth + titleWidth, '-') << std::endl;
		
		for (auto iter : _books)
		{
			if (iter._info.first == author)
				iter.displayBook();
		}
	}	
	else//��ã������
		std::cout << "ã���ô� å�� �����ϴ�.\n";
	

	std::cout << "\n\n";
}
