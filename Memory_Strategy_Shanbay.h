#ifndef MEMORY_STRATEGY_SHANBAY
#define MEMORY_STRATEGY_SHANBAY
#include "Memory_Strategy.h"
class Memory_Strategy_Shanbay: public Memory_Strategy{
public:
	Memory_Strategy_Shanbay(User *temp_user, Database *temp_data);
	Memory_Strategy_Shanbay() = default;
};
#endif
