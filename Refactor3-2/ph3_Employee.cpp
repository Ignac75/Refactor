#include "stdafx.h"
#include "ph3_Employee.h"

/* CEmployee class definition ****************************************************/
/**const string ph2::CEmployee::STR_ENGINEER = "Engineer";**/
/**const string ph2::CEmployee::STR_SALESMAN = "Salesman";**/
/**const string ph2::CEmployee::STR_MANAGER = "Manager";**/

/**static const double BASIC_COMMISSION_FOR_SALESMAN = 500;**/
/**static const double BASIC_BONUS_FOR_MANAGER = 800;**/

ph3::CEmployee::CEmployee(const string& strFirstName,
	const string& strLastName,
	/**int iCompanyStand,**/
	double dMonthlySalary /*= 0.0*/) :
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	/**m_iCompanyStand(iCompanyStand),**/
	m_dMonthlySalary(dMonthlySalary)/**,**/
	/**m_dCommission(0.0),**/
	/**m_dBonus(0.0)**/
{
	/**
	if (m_iCompanyStand == SALESMAN)
	{
		m_dCommission = BASIC_COMMISSION_FOR_SALESMAN;
	}
	else if (m_iCompanyStand == MANAGER)
	{
		m_dBonus = BASIC_BONUS_FOR_MANAGER;
	}
	**/
}

ph3::CEmployee::~CEmployee()
{
}

/**void ph2::CEmployee::SetCommission(double dCommission)
{
	_ASSERT(GetCompanyStand() == SALESMAN);
	if (GetCompanyStand() == SALESMAN)
	{
		m_dCommission = dCommission;
	}
}**/

/**void ph2::CEmployee::SetBonus(double dBonus)
{
	_ASSERT(GetCompanyStand() == MANAGER);
	if (GetCompanyStand() == MANAGER)
	{
		m_dBonus = dBonus;
	}
}**/

/**double ph2::CEmployee::GetPayAmount() const
{
	switch (GetCompanyStand())
	{
		case ENGINEER:
			return m_dMonthlySalary;

		case SALESMAN:
			return m_dMonthlySalary + m_dCommission;

		case MANAGER:
			return m_dMonthlySalary + m_dBonus;

		default:
			_ASSERT(false);
			break;
	}

	return 0.0;
}**/

ostream& ph3::operator <<(ostream& os, const ph3::CEmployee& oEmployee)
{
	os << "First name: " << oEmployee.GetFirstName() << endl;
	os << "Last name: " << oEmployee.GetLastName() << endl;
	os << "Company stand: " << oEmployee.GetCompanyStandAsString() << endl;
	os << "Salary: " << put_money(oEmployee.GetPayAmount(), true) << endl;

	return os;
}

/**string ph2::CEmployee::GetCompanyStandAsString() const
{
	switch (GetCompanyStand())
	{
		case ENGINEER:
			return STR_ENGINEER;

		case SALESMAN:
			return STR_SALESMAN;

		case MANAGER:
			return STR_MANAGER;

		default:
			_ASSERT(false);
			break;
	}

	return "";
}**/


/* CEngineer class definition ****************************************************/
ph3::CEngineer::CEngineer(	const string& strFirstName,
							const string& strLastName,
							/**int iCompanyStand**/ /*= CEmployee::ENGINEER*//**,**/
							double dMonthlySalary /*= 0.0*/) :
	CEmployee(strFirstName, strLastName, /**iCompanyStand,**/ dMonthlySalary)
{
}

ph3::CEngineer::~CEngineer()
{
}

double ph3::CEngineer::GetPayAmount() const
{
	return GetMonthlySalary();
}

string ph3::CEngineer::GetCompanyStandAsString() const
{
	static const string STR_ENGINEER = "Engineer";

	return STR_ENGINEER;
}


/* CSalesman class definition ****************************************************/
const double ph3::CSalesman::BASIC_COMMISSION = 500;

ph3::CSalesman::CSalesman(	const string& strFirstName,
							const string& strLastName,
							/**int iCompanyStand**/ /*= CEmployee::SALESMAN*//**,**/
							double dMonthlySalary /*= 0.0*/) :
	CEmployee(strFirstName, strLastName, /**iCompanyStand,**/ dMonthlySalary),
	m_dCommission(BASIC_COMMISSION)
{
}

ph3::CSalesman::~CSalesman()
{
}

double ph3::CSalesman::GetPayAmount() const
{
	return GetMonthlySalary() + m_dCommission;
}

string ph3::CSalesman::GetCompanyStandAsString() const
{
	static const string STR_SALESMAN = "Salesman";

	return STR_SALESMAN;
}


/* CManager class definition ****************************************************/
const double ph3::CManager::BASIC_BONUS = 800;

ph3::CManager::CManager(	const string& strFirstName,
							const string& strLastName,
							/**int iCompanyStand**/ /*= CEmployee::MANAGER*//**,**/
							double dMonthlySalary /*= 0.0*/) :
	CEngineer(strFirstName, strLastName, /**iCompanyStand,**/ dMonthlySalary),
	m_dBonus(BASIC_BONUS)
{
}

ph3::CManager::~CManager()
{
}

double ph3::CManager::GetPayAmount() const
{
	return GetMonthlySalary() + m_dBonus;
}

string ph3::CManager::GetCompanyStandAsString() const
{
	static const string STR_MANAGER = "Manager";

	return STR_MANAGER;
}