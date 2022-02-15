#pragma once
#include "BankAccountOpening.h"

class BankAccountExecution : private BankAccountOpening
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

