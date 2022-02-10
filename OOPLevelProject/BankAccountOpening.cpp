#include "BankAccountOpening.h"

 BankAccountOpening::BankAccountOpening()
/*:mAccountID(0),
mName(""),
mDepositAmount(0)*/
	:mCount(-1)
{

}

 BankAccountOpening::~BankAccountOpening()
{}

 void BankAccountOpening::MakeAccount()
{
	mCount++;
	//mInfor = new Information;
	mInfor.resize(mCount + 1);
	init();
	err();
	std::cout << "계좌ID:";
	//std::cin >> mAccountID;
	std::cin >> mInfor[mCount]->mAccountID;

	std::cout << std::endl;

	std::cout << "이 름: ";
	std::cin >> mInfor[mCount]->mName;
	//err();
	std::cout << std::endl;

	std::cout << "입금액: ";
	std::cin >> mInfor[mCount]->mDepositAmount;
	//err();
	std::cout << std::endl;

}

 void BankAccountOpening::Deposit()
{
	doPreliminaryWork();

	std::cout << '\n' << "입금액 : " << std::endl;

	unsigned int amount;
	std::cin >> amount;
	if (std::cin.fail())
	{
		assert(false);
	}
	mInfor[mCount]->mDepositAmount += amount;
	std::cout << std::endl;
}

 const unsigned BankAccountOpening::Withdrawal()
{
	doPreliminaryWork();

	std::cout << '\n' << "출금액 : " << std::endl;

	unsigned int amount;
	std::cin >> amount;
	if (std::cin.fail())
	{
		assert(false);
	}
	int result = mInfor[mCount]->mDepositAmount - amount;

	if (result < 0)
	{
		std::cout << "잔고가 부족합니다!" << std::endl;
		return mInfor[mCount]->mDepositAmount;
	}

	mInfor[mCount]->mDepositAmount = result;

	std::cout << std::endl;

	std::cout << "남은잔고 : ";

	return mInfor[mCount]->mDepositAmount;
}

 void BankAccountOpening::Print()
{
	for (unsigned i = 0; i < mCount + 1; i++)
	{
		printIndex(i);
	}

	std::cout << "-------출력완료-------" << std::endl;
	std::cout << '\n' << '\n' << '\n';
}

 void BankAccountOpening::PrintMenu()
{
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

 void BankAccountOpening::SelectMenu(unsigned& selectNum)
{
	std::cout << "선택: ";
	std::cin >> selectNum;
	std::cout << std::endl;
}

 void BankAccountOpening::init()
{
	mInfor[mCount] = new Information;
}

 void BankAccountOpening::printIndex(const unsigned& index)
{
	std::cout << "계좌ID:" << mInfor[index]->mAccountID;
	std::cout << std::endl;

	std::cout << "이 름: " << mInfor[index]->mName;
	std::cout << std::endl;

	std::cout << "입금액: " << mInfor[index]->mDepositAmount;
	std::cout << '\n' << std::endl;
}

 void BankAccountOpening::err()
{
	if (std::cin.fail())
	{
		assert(false);
	}
}

 void BankAccountOpening::doPreliminaryWork()
{
	std::cout << "현재 개설된 개좌갯수: " << mCount + 1 << std::endl;
	for (unsigned i = 0; i < mCount + 1; i++)
	{
		std::cout << i + 1 << " : " << mInfor[i]->mName << std::endl;
	}
	std::cout << "번호를 입력하세요: ";
	unsigned int num;
	std::cin >> num;
	if (std::cin.fail())
	{
		assert(false);
	}
	printIndex(num - 1);
}

 void BankAccountOpening::PrintScreen()
{}

 Information::Information()
	:mAccountID(0),
	mName(""),
	mDepositAmount(0)
{}
