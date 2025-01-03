#include <iostream>
#include <iomanip>
#include "Book.h"
using namespace std;
Book::Book(std::pair<std::string, std::string> info)
	:_info(info)//info.first,info.second
{
}

Book::~Book()
{
}

void Book::displayBook()
{	// ����� �� ����
	const int authorWidth = 20;   // ���� ��� ��
	const int titleWidth = 20;   // å ���� ��� ��

	// ������ ���
	std::cout << std::left << std::setw(authorWidth) << _info.first
		<< std::setw(titleWidth) << _info.second << std::endl;
}
