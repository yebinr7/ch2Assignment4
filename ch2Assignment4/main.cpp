#include "BookManager.h"
#include "BorrowManager.h"
#include "Book.h"
int main(void)
{
	BookManager::GetInstance();//�����Ϳ����� �ϸŴ��� �����
	Book book1(std::make_pair(("��������"), ("����")));
	Book book2(std::make_pair(("�Ѱ�"), ("ä��������")));
	Book book3(std::make_pair(("�Ѱ�"), ("�ҳ��� �´�")));
	Book book4(std::make_pair(("�츣�� �켼"), ("���̾�")));


	// �ϸŴ����� ���
	BookManager::GetInstance()->addBook(book1);
	BookManager::GetInstance()->addBook(book2);
	BookManager::GetInstance()->addBook(book3);
	BookManager::GetInstance()->addBook(book4);

	// �ٷο�Ŵ����� ���� ���� map���� ���� 3���ʱⰪ
	BorrowManager::GetInstance()->initializeStock(book1);
	BorrowManager::GetInstance()->initializeStock(book2);
	BorrowManager::GetInstance()->initializeStock(book3);
	BorrowManager::GetInstance()->initializeStock(book4);



	//��� å �����ֱ�
	BookManager::GetInstance()->displayAllBooks();


	//å ã��
	BookManager::GetInstance()->searchByTitle("����");

	//���� å
	BookManager::GetInstance()->searchByTitle("c++���α׷���");

	//�۰��� å ã��
	BookManager::GetInstance()->searchByAuthor("�Ѱ�");

	//���� �۰��� å ã��
	BookManager::GetInstance()->searchByAuthor("������");


	//å ������
	BorrowManager::GetInstance()->borrowBook("c++���α׷���");


	BorrowManager::GetInstance()->borrowBook("����");
	BorrowManager::GetInstance()->borrowBook("����");
	BorrowManager::GetInstance()->borrowBook("����");
	BorrowManager::GetInstance()->borrowBook("����");
	BorrowManager::GetInstance()->displayStock();


	BorrowManager::GetInstance()->returnBook("����");
	BorrowManager::GetInstance()->displayStock();

	return 0;
}
