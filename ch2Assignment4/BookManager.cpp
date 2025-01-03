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
	std::cout << "###도서관에 있는 책 목록###\n";
	// 출력의 폭 설정
	const int authorWidth = 20;   // 저자 출력 폭
	const int titleWidth = 20;   // 책 제목 출력 폭

	// 헤더 출력
	std::cout << std::left << std::setw(authorWidth) << "저자"
		<< std::setw(titleWidth) << "책제목" << std::endl;
	std::cout << std::string(authorWidth + titleWidth, '-') << std::endl;

	// 책 출력
	for (auto book : _books)
		book.displayBook();

	std::cout << "\n\n";
}

void BookManager::searchByTitle(std::string title)
{
	std::cout << "###책 검색중...제목: "<<title<<"###\n";


	bool find = false;
	for (auto iter : _books)
	{
		if (iter._info.second == title)
		{
			//찾았을때
			find = true;
			std::cout << "찾았습니다!\n";

			// 출력의 폭 설정
			const int authorWidth = 20;   // 저자 출력 폭
			const int titleWidth = 20;   // 책 제목 출력 폭

			// 헤더 출력
			std::cout << std::left << std::setw(authorWidth) << "저자"
				<< std::setw(titleWidth) << "책제목" << std::endl;
			std::cout << std::string(authorWidth + titleWidth, '-') << std::endl;
		
			
			iter.displayBook();
		}
	}

	//못찾았을때
	if (find == false)
	{
		//없습니다.
		std::cout << "찾으시는 책이 없습니다.\n";
	}

	std::cout << "\n\n";
}

void BookManager::searchByAuthor(std::string author)
{
	std::cout << "###책 검색중...작가: " << author << "###\n";


	//한바퀴 순회해서 플래그 키기
	bool find = false;
	for (auto iter : _books)
	{
		if (iter._info.first == author)
			find = true;//찾았을때	
	}

	if (find ==true)
	{
		// 출력의 폭 설정
		const int authorWidth = 20;   // 저자 출력 폭
		const int titleWidth = 20;   // 책 제목 출력 폭

		// 헤더 출력
		std::cout << std::left << std::setw(authorWidth) << "저자"
			<< std::setw(titleWidth) << "책제목" << std::endl;
		std::cout << std::string(authorWidth + titleWidth, '-') << std::endl;
		
		for (auto iter : _books)
		{
			if (iter._info.first == author)
				iter.displayBook();
		}
	}	
	else//못찾았을때
		std::cout << "찾으시는 책이 없습니다.\n";
	

	std::cout << "\n\n";
}
