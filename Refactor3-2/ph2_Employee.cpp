#include "stdafx.h"
#include "ph2_Employee.h"

/* CEmployee class definition ****************************************************/
const string ph2::CEmployee::STR_ENGINEER = "Engineer";
const string ph2::CEmployee::STR_SALESMAN = "Salesman";
const string ph2::CEmployee::STR_MANAGER = "Manager";

static const double BASIC_COMMISSION_FOR_SALESMAN = 500;
static const double BASIC_BONUS_FOR_MANAGER = 800;

ph2::CEmployee::CEmployee(	const string& strFirstName,
							const string& strLastName,
							int iCompanyStand,
							double dMonthlySalary /*= 0.0*/) :
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	m_iCompanyStand(iCompanyStand),
	m_dMonthlySalary(dMonthlySalary),
	m_dCommission(0.0),
	m_dBonus(0.0)
{
	// W konstruktorze nie mo¿na u¿yæ GetCompanyStand poniewa¿ wirtualizacja na poziomie konstruktora
	// nie dzia³a.
	if (m_iCompanyStand == SALESMAN)
	{
		m_dCommission = BASIC_COMMISSION_FOR_SALESMAN;
	}
	else if (m_iCompanyStand == MANAGER)
	{
		m_dBonus = BASIC_BONUS_FOR_MANAGER;
	}
}

ph2::CEmployee::~CEmployee()
{
}

void ph2::CEmployee::SetCommission(double dCommission)
{
	/**_ASSERT(m_iCompanyStand == SALESMAN);**/
	_ASSERT(GetCompanyStand() == SALESMAN);
	/**if (m_iCompanyStand == SALESMAN)**/
	if (GetCompanyStand() == SALESMAN)
	{
		m_dCommission = dCommission;
	}
}

void ph2::CEmployee::SetBonus(double dBonus)
{
	/**_ASSERT(m_iCompanyStand == MANAGER);**/
	_ASSERT(GetCompanyStand() == MANAGER);
	/**if (m_iCompanyStand == MANAGER)**/
	if (GetCompanyStand() == MANAGER)
	{
		m_dBonus = dBonus;
	}
}

double ph2::CEmployee::GetPayAmount() const
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
}

ostream& ph2::operator <<(ostream& os, const ph2::CEmployee& oEmployee)
{
	os << "First name: " << oEmployee.GetFirstName() << endl;
	os << "Last name: " << oEmployee.GetLastName() << endl;
	os << "Company stand: " << oEmployee.GetCompanyStandAsString() << endl;
	os << "Salary: " << put_money(oEmployee.GetPayAmount(), true) << endl;

	return os;
}

string ph2::CEmployee::GetCompanyStandAsString() const
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
}


/* CEngineer class definition ****************************************************/
ph2::CEngineer::CEngineer(	const string& strFirstName,
							const string& strLastName,
							int iCompanyStand /*= CEmployee::ENGINEER*/,
							double dMonthlySalary /*= 0.0*/) :
	CEmployee(strFirstName, strLastName, iCompanyStand, dMonthlySalary)
{
}

ph2::CEngineer::~CEngineer()
{
}


/* CSalesman class definition ****************************************************/
ph2::CSalesman::CSalesman(	const string& strFirstName,
							const string& strLastName,
							int iCompanyStand /*= CEmployee::SALESMAN*/,
							double dMonthlySalary /*= 0.0*/) :
	CEmployee(strFirstName, strLastName, iCompanyStand, dMonthlySalary)
{
}

ph2::CSalesman::~CSalesman()
{
}


/* CManager class definition ****************************************************/
ph2::CManager::CManager(	const string& strFirstName,
							const string& strLastName,
							int iCompanyStand /*= CEmployee::MANAGER*/,
							double dMonthlySalary /*= 0.0*/) :
	CEngineer(strFirstName, strLastName, iCompanyStand, dMonthlySalary)
{
}

ph2::CManager::~CManager()
{
}