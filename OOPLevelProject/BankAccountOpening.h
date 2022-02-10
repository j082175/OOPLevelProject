#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>

class Information
{
	friend class BankAccountOpening;
	unsigned int mAccountID;
	std::string mName;
	unsigned int mDepositAmount;

public:
	Information();
};

class BankAccountOpening
{
public:
	BankAccountOpening();
	virtual ~BankAccountOpening();

	void MakeAccount();

	void Deposit();

	const unsigned Withdrawal();

	void Print();

	void PrintMenu();

	void SelectMenu(unsigned& selectNum);

private:
	void init();

	void printIndex(const unsigned& index);

	void err();

	void doPreliminaryWork();

	virtual void PrintScreen() = 0;



private:
	//Information* mInfor;
	std::vector<Information*> mInfor;
	unsigned int mCount;
};

