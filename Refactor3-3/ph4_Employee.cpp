#include "stdafx.h"
#include "ph4_Employee.h"


/* CCompanyStand class definition ****************************************************/
unique_ptr<ph4::CCompanyStand> ph4::CCompanyStand::Create(EStand eStand)
{
	switch (eStand)
	{
		case EStand::eEngineer:
			return make_unique<CEngineer>();

		case EStand::eSalesman:
			return make_unique<CSalesman>();

		case EStand::eManager:
			return make_unique<CManager>();

		default:
			_ASSERT(false);
			return nullptr;
	}
}

ph4::CCompanyStand::CCompanyStand()
{
}

ph4::CCompanyStand::~CCompanyStand()
{
}

/* CEngineer class definition ****************************************************/
ph4::CEngineer::CEngineer() :
	CCompanyStand()
{
}

ph4::CEngineer::~CEngineer()
{
}

string ph4::CEngineer::GetCompanyStandAsString() const
{
	static const string STR_ENGINEER = "Engineer";

	return STR_ENGINEER;
}


/* CSalesman class definition ****************************************************/
ph4::CSalesman::CSalesman() :
	CCompanyStand()
{
}

ph4::CSalesman::~CSalesman()
{
}

string ph4::CSalesman::GetCompanyStandAsString() const
{
	static const string STR_SALESMAN = "Salesman";

	return STR_SALESMAN;
}


/* CManager class definition ****************************************************/
ph4::CManager::CManager() :
	CEngineer()
{
}

ph4::CManager::~CManager()
{
}

string ph4::CManager::GetCompanyStandAsString() const
{
	static const string STR_MANAGER = "Manager";

	return STR_MANAGER;
}


/* CEmployee class definition ****************************************************/
/**const string ph4::CEmployee::STR_ENGINEER = "Engineer";
const string ph4::CEmployee::STR_SALESMAN = "Salesman";
const string ph4::CEmployee::STR_MANAGER = "Manager";**/

static const double BASIC_COMMISSION_FOR_SALESMAN = 500;
static const double BASIC_BONUS_FOR_MANAGER = 800;

ph4::CEmployee::CEmployee(	const string& strFirstName,
							const string& strLastName,
							/**int iCompanyStand,**/
							CCompanyStand::EStand eStand,
							double dMonthlySalary /*= 0.0*/) :
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	m_dMonthlySalary(dMonthlySalary),
	m_dCommission(0.0),
	m_dBonus(0.0)
{
	SetCompanyStand(/**iCompanyStand**/eStand);
	/**if (GetCompanyStand() == CCompanyStand::SALESMAN)**/
	if (GetCompanyStand() == CCompanyStand::EStand::eSalesman)
	{
		m_dCommission = BASIC_COMMISSION_FOR_SALESMAN;
	}
	/**else if (GetCompanyStand() == CCompanyStand::MANAGER)**/
	else if (GetCompanyStand() == CCompanyStand::EStand::eManager)
	{
		m_dBonus = BASIC_BONUS_FOR_MANAGER;
	}
}

ph4::CEmployee::~CEmployee()
{
}

void ph4::CEmployee::SetCompanyStand(/**int iCompanyStand**/CCompanyStand::EStand eStand)
{
	/**
	switch (iCompanyStand)
	{
		case CCompanyStand::ENGINEER:
			m_upCompanyStand = make_unique<CEngineer>();
			break;

		case CCompanyStand::SALESMAN:
			m_upCompanyStand = make_unique<CSalesman>();
			break;

		case CCompanyStand::MANAGER:
			m_upCompanyStand = make_unique<CManager>();
			break;

		default:
			_ASSERT(false);
			break;
	}
	**/
	m_upCompanyStand = CCompanyStand::Create(eStand);
}

void ph4::CEmployee::SetCommission(double dCommission)
{
	/**_ASSERT(GetCompanyStand() == CCompanyStand::SALESMAN);
	if (GetCompanyStand() == CCompanyStand::SALESMAN)**/
	_ASSERT(GetCompanyStand() == CCompanyStand::EStand::eSalesman);
	if (GetCompanyStand() == CCompanyStand::EStand::eSalesman)
	{
		m_dCommission = dCommission;
	}
}

void ph4::CEmployee::SetBonus(double dBonus)
{
	/**_ASSERT(GetCompanyStand() == CCompanyStand::MANAGER);
	if (GetCompanyStand() == CCompanyStand::MANAGER)**/
	_ASSERT(GetCompanyStand() == CCompanyStand::EStand::eManager);
	if (GetCompanyStand() == CCompanyStand::EStand::eManager)
	{
		m_dBonus = dBonus;
	}
}

double ph4::CEmployee::GetPayAmount() const
{
	switch (GetCompanyStand())
	{
		case CCompanyStand::EStand::eEngineer:
			return m_dMonthlySalary;

		case CCompanyStand::EStand::eSalesman:
			return m_dMonthlySalary + m_dCommission;

		case CCompanyStand::EStand::eManager:
			return m_dMonthlySalary + m_dBonus;

		default:
			_ASSERT(false);
			return 0.0;
	}
}

ostream& ph4::operator <<(ostream& os, const ph4::CEmployee& oEmployee)
{
	os << "First name: " << oEmployee.GetFirstName() << endl;
	os << "Last name: " << oEmployee.GetLastName() << endl;
	os << "Company stand: " << oEmployee.GetCompanyStandAsString() << endl;
	os << "Salary: " << put_money(oEmployee.GetPayAmount(), true) << endl;

	return os;
}

string ph4::CEmployee::GetCompanyStandAsString() const
{
	/**switch (GetCompanyStand())
	{
		case CCompanyStand::ENGINEER:
			return STR_ENGINEER;

		case CCompanyStand::SALESMAN:
			return STR_SALESMAN;

		case CCompanyStand::MANAGER:
			return STR_MANAGER;

		default:
			_ASSERT(false);
			break;
	}

	return "";**/
	return m_upCompanyStand->GetCompanyStandAsString();
}