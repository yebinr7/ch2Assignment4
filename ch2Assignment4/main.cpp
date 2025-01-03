#include "BookManager.h"
#include "Book.h"
int main(void)
{
	BookManager::GetInstance();//�����Ϳ����� �ϸŴ��� �����
	Book book1(std::make_pair(("��������"), ("����")));
	Book book2(std::make_pair(("�Ѱ�"), ("ä��������")));
	Book book3(std::make_pair(("�Ѱ�"), ("�ҳ��� �´�")));
	Book book4(std::make_pair(("�츣�� �켼"), ("���̾�")));

	BookManager::GetInstance()->addBook(book1);
	BookManager::GetInstance()->addBook(book2);
	BookManager::GetInstance()->addBook(book3);
	BookManager::GetInstance()->addBook(book4);

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
	return 0;
}
