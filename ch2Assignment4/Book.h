#pragma once
#include <string> //��¿�� ���� ��Ŭ���
#include <utility> //tuple �̿� 

class Book
{
public:
	Book() = default;
	Book(std::pair<std::string, std::string> info);
	~Book();
public:
	void displayBook();

public:
	std::pair<std::string, std::string> _info; //���� å�̸�

private:
	//std::string title;
	//std::string author;
};

