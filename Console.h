#ifndef CONSOLE_H
#define CONSOLE_H
#include "database.h"
#include "User.h"
class Console{
private:
	Database *data;
	User *Current_User;
	Memory_Strategy *memory_strategy;       //������� 1��ʾ�ȱ�ģʽ��2��ʾ�ٴ�նģʽ 
	NewWords_Strategy *newwords_strategy;		//����ͳ�ƽ��Ͳ���
	Test_Strategy *test_strategy;       //���ߵ��ʲ��Բ��� 1.�ж��⣬2.ѡ���� 
	
	void Change_Memory_Strategy();
	
	std::string Get_Word(std::string Temp_Word);      //��õ�������
	void Show_Search_History();     //��ʾ��ѯ��ʷ
	void Search();   //��search�У������û�Ҫ���������ʾ��ѯ��ʷ���ǲ鵥�� 
	void Test();	//ѡ�����ģʽ������ 1.�ж��� 2.ѡ����  
	
	Console(Database *temp_data, User *temp_user); 
	Console() = default;
public:
	void Run();
};
#endif
