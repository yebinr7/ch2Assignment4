#pragma once
#include <string> //어쩔수 없이 인클루드
#include <utility> //tuple 이용 

class Book
{
public:
	Book() = default;
	Book(std::pair<std::string, std::string> info);
	~Book();
public:
	void displayBook();

public:
	std::pair<std::string, std::string> _info; //저자 책이름

private:
	//std::string title;
	//std::string author;
};

