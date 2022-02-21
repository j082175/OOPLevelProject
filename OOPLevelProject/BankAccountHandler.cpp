#include "BankAccountHandler.h"

 BankAccountHandler::BankAccountHandler()
/*:mAccountID(0),
mName(""),
mDepositAmount(0)*/
	:mCount(-1)
{

}

 BankAccountHandler::~BankAccountHandler()
{}

 void BankAccountHandler::MakeAccount()
{
	mCount++;
	//mInfor = new Information;
	mInfor.resize(mCount + 1);
	init();
	err();
	std::cout << "����ID:";
	//std::cin >> mAccountID;
	std::cin >> mInfor[mCount]->mAccountID;

	std::cout << std::endl;

	std::cout << "�� ��: ";
	std::cin >> mInfor[mCount]->mName;
	//err();
	std::cout << std::endl;

	std::cout << "�Աݾ�: ";
	std::cin >> mInfor[mCount]->mDepositAmount;
	//err();
	std::cout << std::endl;

}

 void BankAccountHandler::Deposit()
{
	doPreliminaryWork();

	std::cout << '\n' << "�Աݾ� : " << std::endl;

	unsigned int amount;
	std::cin >> amount;
	if (std::cin.fail())
	{
		assert(false);
	}
	mInfor[mCount]->mDepositAmount += amount;
	std::cout << std::endl;
}

 const unsigned BankAccountHandler::Withdrawal()
{
	doPreliminaryWork();

	std::cout << '\n' << "��ݾ� : " << std::endl;

	unsigned int amount;
	std::cin >> amount;
	if (std::cin.fail())
	{
		assert(false);
	}
	int result = mInfor[mCount]->mDepositAmount - amount;

	if (result < 0)
	{
		std::cout << "�ܰ��� �����մϴ�!" << std::endl;
		return mInfor[mCount]->mDepositAmount;
	}

	mInfor[mCount]->mDepositAmount = result;

	std::cout << std::endl;

	std::cout << "�����ܰ� : ";

	return mInfor[mCount]->mDepositAmount;
}

 void BankAccountHandler::Print()
{
	for (unsigned i = 0; i < mCount + 1; i++)
	{
		printIndex(i);
	}

	std::cout << "-------��¿Ϸ�-------" << std::endl;
	std::cout << '\n' << '\n' << '\n';
}

 void BankAccountHandler::PrintMenu()
{
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}

 void BankAccountHandler::SelectMenu(unsigned& selectNum)
{
	std::cout << "����: ";
	std::cin >> selectNum;
	std::cout << std::endl;
}

 void BankAccountHandler::init()
{
	mInfor[mCount] = new Information;
}

 void BankAccountHandler::printIndex(const unsigned& index)
{
	std::cout << "����ID:" << mInfor[index]->mAccountID;
	std::cout << std::endl;

	std::cout << "�� ��: " << mInfor[index]->mName;
	std::cout << std::endl;

	std::cout << "�Աݾ�: " << mInfor[index]->mDepositAmount;
	std::cout << '\n' << std::endl;
}

 void BankAccountHandler::err()
{
	if (std::cin.fail())
	{
		assert(false);
	}
}

 void BankAccountHandler::doPreliminaryWork()
{
	std::cout << "���� ������ ���°���: " << mCount + 1 << std::endl;
	for (unsigned i = 0; i < mCount + 1; i++)
	{
		std::cout << i + 1 << " : " << mInfor[i]->mName << std::endl;
	}
	std::cout << "��ȣ�� �Է��ϼ���: ";
	unsigned int num;
	std::cin >> num;
	if (std::cin.fail())
	{
		assert(false);
	}
	printIndex(num - 1);
}

 void BankAccountHandler::PrintScreen()
{}

 Information::Information()
	:mAccountID(0),
	mName(""),
	mDepositAmount(0)
{}