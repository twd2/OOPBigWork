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
public:
	int Recited_Times;
	int Right_Times;
	User *Current_User;
	Database *data;
	void Get_Words_Queue();         //���Ҫ�����ʵĶ��� 
	void After_Factory();           //�Ըõ��ʽ��и�����Ϣ�Ķ� 
	void Run();
	
	void Init(int Temp);
	bool Exist();
	virtual std::string Get_Query() = 0;
	virtual bool Check(std::string Temp) = 0;
	virtual std::string Work(std::string Ans) = 0;
	Memory_Strategy(User *temp_user, Database *temp_data);
	Memory_Strategy() = default;
	std::string First_Word();
};
#endif
