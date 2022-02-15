#include "BankAccountExecution.h"

 BankAccountExecution::BankAccountExecution()
	:mSelectNum(0),
	mLoop(0)
{

}

  void BankAccountExecution::Execute()
 {
	 Loop();
 }

 void BankAccountExecution::PrintScreen()
{
	std::cout << "-----Menu-----" << std::endl;

	PrintMenu();
	SelectMenu(mSelectNum);
	unsigned int inputNum(0);
	switch (mSelectNum)
	{
	case static_cast<unsigned>(eKind::MakeAccount):
		MakeAccount();
		break;
	case static_cast<unsigned>(eKind::Deposit):
		Deposit();
		break;
	case static_cast<unsigned>(eKind::Withdrawal):
		/*	std::cout << "출금액 : " << std::endl;

		std::cin >> inputNum;
		std::cout << std::endl;*/
		std::cout << Withdrawal() << std::endl;
		break;
	case static_cast<unsigned>(eKind::Print):
		Print();
		break;
	case static_cast<unsigned>(eKind::EXIT):
		mLoop = -1;
		break;
	default:
		std::cout << "다시 입력해주세요" << std::endl;
		break;
	}
}

 void BankAccountExecution::Loop()
{
	while (mLoop != -1)
	{
		PrintScreen();
	}
	std::cout << "종료" << std::endl;
}
