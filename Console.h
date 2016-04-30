#ifndef CONSOLE_H
#define CONSOLE_H
#include"database.h"
class Console{
private:
	database *data;
	User *Current_User;
	ReciteStrategy *recite_strategy;       //������� 
	NewWordsStrategy *newwords_strategy;		//����ͳ�ƽ��Ͳ���
	TestWordsStrategy *test_strategy;       //���ߵ��ʲ��Բ��� 
	void ChangeReciteStrategy();
	
	int GetWord(std::string query);      //��õ�������
	void Show_Search_History();     //��ʾ��ѯ��ʷ
	void Search();   //��search�У������û�Ҫ���������ʾ��ѯ��ʷ���ǲ鵥�� 
	
	Console(database *temp_data, User *temp_user); 
	Console() = default;
public:
	void Run();
};
#endif
