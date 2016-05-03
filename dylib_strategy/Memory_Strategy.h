#ifndef MEMORY_STRATEGY
#define MEMORY_STRATEGY
#include <User.h>
#include <Database.h>
#include <ctime>
#include <queue>
#include <cstdlib>
#include <cmath>
class Memory_Strategy{
	std::queue<std::string> Wanted_Words;     //�洢�˴α�������Ҫ���ĵ��� 
	std::queue<int> Whether_Used;       //�洢�õ����Ƿ񱳹�      1��ʾ�������ֵ��г��ֹ��� 0��ʾδ���ֹ� 
	std::queue<int> Amount_Recited_Times;    //�õ��ʱ��д��� 
	int Word_Num;          //�û���Ҫ�ĵ��ʸ���
	int Difficulty;           //�û��趨�Ѷ� 
	std::vector<std::string> get_out_console;
public:
	float Recited_Times;
	float Right_Times;
	User *Current_User;
	Database *data;
	void Get_Words_Queue();         //���Ҫ�����ʵĶ��� 
	virtual void Word_Factory(std::string Temp_Word) = 0;        //�Ե��ʽ��д��� 
	void After_Factory();           //�Ըõ��ʽ��и�����Ϣ�Ķ� 
	void Run();
	Memory_Strategy(User *temp_user, Database *temp_data);
	Memory_Strategy() = default;
};
#endif
