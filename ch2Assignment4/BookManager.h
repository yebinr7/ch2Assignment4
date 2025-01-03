#pragma once
#include <iostream>//어쩔수 없이..
#include <vector>
#include <utility> //tuple 이용 

class Book;//전방선언 링커가 알아서 찾아서 연결해라

class BookManager
{
public:
	BookManager();
	~BookManager();

public:
	//객체랑 관련 없는 static클래스 함수 
	static BookManager* GetInstance() //이 함수로 데이터 영역에 존재하는 객체의 주소 항상 얻어 올 수 있다.
	{
		static BookManager bm;//데이터 영역에 존재하는 객체 
		return &bm;
	}


public:
	//벡터에 책추가
	 void addBook(Book book);
	 
	 //벡터가 관리하는 모든 책 나타내기
	 void displayAllBooks();
	 
	 //제목으로 찾아내기: 있으면 있다. 제목,작가 출력
	 void searchByTitle(std::string title);

	 //작가로 찾아내기: 있으면 있다, 제목, 작가 출력, 같은작가면 작까꺼 모두출력 
	 void searchByAuthor(std::string author);

private:
	std::vector<Book> _books;
};

