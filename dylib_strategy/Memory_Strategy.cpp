#include "Memory_Strategy.h"
Memory_Strategy::Memory_Strategy(User *temp_user, Database *temp_data): Current_User(temp_user), data(temp_data){
	Difficulty = Current_User->Get_Difficulty();
	Word_Num = 0;
	Recited_Times = 0;
	Right_Times = 0;
}
void Memory_Strategy::Get_Words_Queue()
{
	auto Record_Map = Current_User->Whole_Memorized_Words();
	auto iter = Record_Map.begin();
	int Reviewed_Words_Num = 0;
	int Temp_Word_Num = Word_Num;
	std::vector<int> prevent_repeat;
	prevent_repeat.clear();
	for(; iter != Record_Map.end(); iter++)
	{
		int element = iter->second.first;   //分子 
		int denominator = iter->second.second;    //分母
		if(!(1.0 * element / denominator >= 0.6 && denominator >= 5))     //加入队列条件
		{
			Wanted_Words.push(iter->first);
			Whether_Used.push(1);
			Amount_Recited_Times.push(0);
			Reviewed_Words_Num++;
		}
		if(Reviewed_Words_Num >= (Temp_Word_Num * 0.6))
			break; 
	}
	Temp_Word_Num -= Reviewed_Words_Num;
	int flag = 0;
	while(flag < Temp_Word_Num)
	{
		int index = rand() % data->Get_Words_Size();
		int temp_flag = 0;
		for(auto iter = prevent_repeat.begin(); iter != prevent_repeat.end(); iter++)
			if(*iter == index)
				temp_flag = 1;
		if(temp_flag == 1)
			continue;
		std::string Word_By_Index = data->Get_English(index);
		if(data->Get_Difficulty(Word_By_Index) == Difficulty || data->Get_Difficulty(Word_By_Index) == Difficulty + 1)
		{
			if(Current_User->Get_Memorized_Times(Word_By_Index).first == 0 && 
			Current_User->Get_Memorized_Times(Word_By_Index).second == 0)
			{
				prevent_repeat.push_back(index);
				Wanted_Words.push(Word_By_Index);
				Whether_Used.push(0);
				Amount_Recited_Times.push(0);
				flag++;
			}
		}
	}
}
void Memory_Strategy::After_Factory()
{
	std::string temp_first_word = Wanted_Words.front();
	int temp_first_used = Whether_Used.front();
	int temp_first_amount = Amount_Recited_Times.front();
	Wanted_Words.pop();
	Whether_Used.pop();
	Amount_Recited_Times.pop();
	if(temp_first_used == 0 && temp_first_amount < 3)
	{
		temp_first_amount++;
		Wanted_Words.push(temp_first_word);
		Whether_Used.push(0);
		Amount_Recited_Times.push(temp_first_amount);
	}
}
void Memory_Strategy::Run()
{
	if(Right_Times >= (Recited_Times * 0.9))
	{
		if(Difficulty < 5)
		{
			int Temp_Difficulty = Difficulty + 1;
			Current_User->Change_Difficulty_Of_User(Temp_Difficulty);
			Difficulty = Temp_Difficulty;
		}
	}
	if(Right_Times <= (Recited_Times * 0.5))
	{
		if(Difficulty > 1)
		{
			int Temp_Difficulty = Difficulty - 1;
			Current_User->Change_Difficulty_Of_User(Temp_Difficulty);
			Difficulty = Temp_Difficulty;
		}	
	}
}
void Memory_Strategy::Init(int Temp){
	Recited_Times = 0;
	Right_Times = 0;
	Word_Num = Temp;
	Get_Words_Queue();
}
bool Memory_Strategy::Exist(){
	return !Wanted_Words.empty();
}
std::string Memory_Strategy::First_Word()
{
	return Wanted_Words.front();
}
Memory_Strategy::~Memory_Strategy(){}
