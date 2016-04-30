#ifndef CONSOLE_H
#define CONSOLE_H
#include"database.h"
class Console{
private:
	database *data;
	User *Current_User;
	Memory_Strategy *memory_strategy;       //������� 1��ʾ�ȱ�ģʽ��2��ʾ�ٴ�նģʽ 
	NewWords_Strategy *newwords_strategy;		//����ͳ�ƽ��Ͳ���
	Test_Words_Strategy *test_strategy;       //���ߵ��ʲ��Բ��� 
	
	void ChangeReciteStrategy();
	
	std::string Get_Word(std::string Temp_Word);      //��õ�������
	void Show_Search_History();     //��ʾ��ѯ��ʷ
	void Search();   //��search�У������û�Ҫ���������ʾ��ѯ��ʷ���ǲ鵥�� 
	
	Console(database *temp_data, User *temp_user); 
	Console() = default;
public:
	void Run();
};
#endif
