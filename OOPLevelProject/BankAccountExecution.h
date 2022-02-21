#pragma once
#include "BankAccountHandler.h"

class BankAccountExecution : private BankAccountHandler
{
	unsigned int mSelectNum;
	int mLoop;
	enum class eKind
	{
		MakeAccount = 1,
		Deposit,
		Withdrawal,
		Print,
		EXIT
	};
public:
	BankAccountExecution();

	void Execute();

private:
	void PrintScreen();

private:
	void Loop();
};

