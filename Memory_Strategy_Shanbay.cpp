#include "Memory_Strategy_Shanbay.h"
Memory_Strategy_Shanbay::Memory_Strategy_Shanbay(User *temp_user, Database *temp_data): 
	Memory_Strategy(temp_user, temp_data){
	Current_User = temp_user;
	data = temp_data;
}
void Memory_Strategy_Shanbay::Word_Factory(std::string Temp_Word)
{
	std::cout<<Temp_Word<<std::endl;
	std::cout<<"��ʶ��[Y/N]"<<std::endl;
	std::cout<<"������Y:��ʶ N������ʶ"<<std::endl;
	std::string temp_input;
	getline(std::cin, temp_input);
	while(!(temp_input.size() == 1 && (temp_input[0] == 'Y' || temp_input[0] == 'N')))
	{
		std::cout<<"�����������������"<<std::endl;
		temp_input.clear();
		getline(std::cin, temp_input);
	}
	if(temp_input[0] == 'N')
	{
		int temp_right_times = (Current_User->Get_Memorized_Times(Temp_Word).first);
		int temp_whole_times = (Current_User->Get_Memorized_Times(Temp_Word).second);
		temp_whole_times++;
		Current_User->Change_Memory_times(Temp_Word, temp_right_times, temp_whole_times);
		std::cout<<data->Get_Chinese(Temp_Word)<<std::endl;
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
	else
	{
		Right_Times++;
		int temp_right_times = (Current_User->Get_Memorized_Times(Temp_Word).first);
		int temp_whole_times = (Current_User->Get_Memorized_Times(Temp_Word).second);
		temp_right_times++;
		temp_whole_times++;
		Current_User->Change_Memory_times(Temp_Word, temp_right_times, temp_whole_times);
	}
}
