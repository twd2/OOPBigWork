#include "Memory_Strategy_Towords.h"
Memory_Strategy_Towords::Memory_Strategy_Towords(User *temp_user, Database *temp_data): 
Memory_Strategy(temp_user, temp_data){
	Current_User = temp_user;
	data = temp_data;
}
void Memory_Strategy_Towords::Word_Factory(std::string Temp_Word)
{
	std::cout<<Temp_Word<<std::endl;
	int index[3] = {0};
	for(int i = 0; i < 3; i++)
	{
		int temp_flag = 0;
		do
		{
			index[i] = rand() % data->Get_Words_Size();
			for(int j = 0; j < temp_flag; j++)
			{
				if(index[j] == index[i] || data->Get_English(index[j]) == Temp_Word)
					temp_flag = 1;
			}
		}while(temp_flag != 0);
	}
	int seq = rand() % 4;
	for(int i = 0; i < 4; i++)
	{
		if(i == seq)
			std::cout<<char(65 + i)<<'.'<<data->Get_Chinese(Temp_Word)<<std::endl;
		else
			std::cout<<char(65 + i)<<'.'<<data->Get_Chinese(data->Get_English(index[i]))<<std::endl;	
	}
	std::string temp_input;
	temp_input.clear();
	getline(std::cin, temp_input);
	while(!(temp_input.size() == 1 && 'A' <= temp_input[0] && 'D' >= temp_input[0]))
	{
		std::cout<<"�������, ����������"<<std::endl;
		temp_input.clear();
		getline(std::cin, temp_input);
	}
	if(int(temp_input[0] - 'A') != seq)   //right
	{
		int temp_right_times = (Current_User->Get_Memorized_Times(Temp_Word).first);
		int temp_whole_times = (Current_User->Get_Memorized_Times(Temp_Word).second);
		temp_whole_times++;
		Current_User->Change_Memory_times(Temp_Word, temp_right_times, temp_whole_times);
		std::cout<<"��ȷ����:"<<char(seq + 65)<<std::endl;
		std::cout<<"����"<<data->Get_Chinese(Temp_Word)<<std::endl;
		std::cout<<"����"<<std::endl;
		for(int i = 0; i < (int)data->Get_Examples(Temp_Word).size(); i++)
			std::cout<<data->Get_Examples(Temp_Word)[i]<<std::endl;
		std::cout<<"�Ƿ�ϣ����������[Y/N] Y:ϣ�� N����ϣ��"<<std::endl;
		temp_input.clear();
		getline(std::cin, temp_input);
		while(!(temp_input.size() == 1 && (temp_input[0] == 'Y' || temp_input[0] == 'N')))
		{
			std::cout<<"�����������������"<<std::endl;
			temp_input.clear();
			getline(std::cin, temp_input);
		}
		if(temp_input[0] == 'Y')
		{
			temp_input.clear();
			std::cout<<"����������"<<std::endl;
			getline(std::cin, temp_input);
			data->Add_Example(Temp_Word, temp_input);
			Current_User->Add_Example(Temp_Word, temp_input);
		}
	}
	else    //wrong
	{
		std::cout<<"�����ˣ�"<<std::endl;
		Right_Times++;
		int temp_right_times = (Current_User->Get_Memorized_Times(Temp_Word).first);
		int temp_whole_times = (Current_User->Get_Memorized_Times(Temp_Word).second);
		temp_right_times++;
		temp_whole_times++;
		Current_User->Change_Memory_times(Temp_Word, temp_right_times, temp_whole_times);
	}
}
