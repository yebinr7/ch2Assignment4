#include <utility> //tuple 이용 
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
	_stock.insert(std::make_pair(book._info.second/*책이름*/, quantity));
}
//
void BorrowManager::borrowBook(std::string title)
{
	////1. 책이름 인경우

	////2. 작가로 빌리는 경우 -> 분기처리 무슨책 빌릴래? 


	//auto &m = _stock; //원본
	////대여 했는지 확인 (책 이름이 하나라서 가능) 

	//auto it = std::find(m.begin(), m.end(),title );//map이라 이방식 x
	auto it = _stock.find(title);

	if (it != _stock.end())
	{
		//찾았다면

		//1. 재고 체크
		if (it->second > 0)//재고가 있다면
		{

			//2. 재고 있으면 제고-1 빌렸습니다 출력
			it->second -= 1;
			std::cout << "대여 됐습니다. 대여된 책이름: " << it->first << "\n";
		}
		else //재고 가 0이라면..
		{
			//3. 재고가 없다면 재고가 없습니다. 
			std::cout << "죄송합니다. 모두 대여됐습니다...모두 대여된 책이름: " << it->first << "\n";
		}
	}
	else
	{
		//아예 없는 
		//존재하지 않는 책입니다. 출력 

		std::cout << title<<"은 존재하지 않는 책입니다..\n";
	}

	std::cout << "\n\n";

}

void BorrowManager::borrowBookAuthor(std::string author)
{
	//1. 

}

void BorrowManager::returnBook(std::string title)
{
	//auto& m = _stock; //원본
	//책반납하기
	auto it = _stock.find(title);

	if (it != _stock.end())//도서관에 있는 책이라면...
	{
		//1. 재고 체크 3미만인 경우
		if (it->second < 3)
		{
			it->second += 1;
			std::cout << "반납됐습니다. 반납된 책이름: " << it->first << "\n";
		}
		else//2. 재고 체크 3초과 인경우
		{
			std::cout<<"이미 책재고가 꽉 찼습니다.. 다른 곳에서 반납해주세요. 반납한 책이름: " 
				     << it->first << "\n";
		}
	}
	else
	{
		//아예 없는 
		//존재하지 않는 책입니다. 출력 
		std::cout << " 존재하지 않는 책입니다.. 다른 도서관을 찾아가세요.\n";
	}
	std::cout << "\n\n";
}

void BorrowManager::displayStock()
{

	// 출력의 폭 설정
	const int authorWidth = 20;   // 저자 출력 폭
	const int titleWidth = 20;   // 책 제목 출력 폭
	const int stockWidth = 20;

	std::cout << "###대여 목록###\n";

	// 헤더 출력
	std::cout /*<< std::left << std::setw(authorWidth) << "저자"*/
			  << std::setw(titleWidth) << "책제목"
			  << std::setw(stockWidth) << "남은책 개수" << std::endl;
	std::cout << std::string(/*authorWidth +*/ titleWidth + stockWidth, '-') << std::endl;

	for (auto info : _stock)
	{
		std::cout << std::left << std::setw(authorWidth) << info.first
			<< std::setw(titleWidth) << info.second << std::endl;
	}

	std::cout << "\n\n";

	////const auto vec = BookManager::GetInstance()->getBmVector();
	//const std::vector<Book>& _books = BookManager::GetInstance()->getBmVector();

	//책 목록, 남은 개수



	std::cout << "\n\n";


}

