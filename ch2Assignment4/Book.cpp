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
{	// 출력의 폭 설정
	const int authorWidth = 20;   // 저자 출력 폭
	const int titleWidth = 20;   // 책 제목 출력 폭

	// 데이터 출력
	std::cout << std::left << std::setw(authorWidth) << _info.first
		<< std::setw(titleWidth) << _info.second << std::endl;
}
