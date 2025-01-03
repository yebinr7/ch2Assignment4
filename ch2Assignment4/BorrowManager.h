#pragma once
#include <string>//어쩔수없음
#include <unordered_map>

class Book;//링커야 알아서 찾아라
class BorrowManager
{
public:
	BorrowManager();
	~BorrowManager();
public:
	//객체랑 관련 없는 static클래스 함수 
	static BorrowManager* GetInstance() //이 함수로 데이터 영역에 존재하는 객체의 주소 항상 얻어 올 수 있다.
	{
		static BorrowManager bm;//데이터 영역에 존재하는 객체 
		return &bm;
	}

public:
	//초기책 물량 설정
	void initializeStock(Book book, int quantity=3);
	
	//책 이름 대여 여부 검색& 대여
	void borrowBook(std::string title);

	//책 작가 대여 여부 검색& 대여
	void borrowBookAuthor(std::string author);

	//책 반납 이름으로
	void returnBook(std::string title);

	//모든 책의 대여 여부 확인
	void displayStock();



private:
	//책이름, 책개수
	std::unordered_map<std::string, int> _stock;


};


