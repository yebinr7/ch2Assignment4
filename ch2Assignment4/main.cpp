#include "BookManager.h"
#include "Book.h"
int main(void)
{
	BookManager::GetInstance();//데이터영역에 북매니저 만들기
	Book book1(std::make_pair(("베르나르"), ("개미")));
	Book book2(std::make_pair(("한강"), ("채식주의자")));
	Book book3(std::make_pair(("한강"), ("소년이 온다")));
	Book book4(std::make_pair(("헤르만 헤세"), ("데미안")));

	BookManager::GetInstance()->addBook(book1);
	BookManager::GetInstance()->addBook(book2);
	BookManager::GetInstance()->addBook(book3);
	BookManager::GetInstance()->addBook(book4);

	//모든 책 보여주기
	BookManager::GetInstance()->displayAllBooks();


	//책 찾기
	BookManager::GetInstance()->searchByTitle("개미");

	//없는 책
	BookManager::GetInstance()->searchByTitle("c++프로그래밍");

	//작가의 책 찾기
	BookManager::GetInstance()->searchByAuthor("한강");

	//없는 작가의 책 찾기
	BookManager::GetInstance()->searchByAuthor("윤성우");
	return 0;
}
