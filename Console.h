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
	
	int GetWord(string query);
	void ChangeReciteStrategy();
	void SearchWords();
	void TestWords();
	Console(database *temp_data, User *temp_user, ); 
	Console() = default;
public:
	void Run();
};
#endif
