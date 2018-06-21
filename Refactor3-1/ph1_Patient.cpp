#include "stdafx.h"
#include "ph1_Patient.h"

ph1::CPatient::CPatient(const string& strFirstName, const string& strLastName, int iBloodGroup):
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	m_iBloodGroup(iBloodGroup)
{
}

ph1::CPatient::~CPatient()
{
}

ostream& ph1::operator <<(ostream& os, const ph1::CPatient& oPatient)
{
	os << "First name: " << oPatient.GetFirstName() << endl;
	os << "Last name: " << oPatient.GetLastName() << endl;
	
	switch (oPatient.GetBloodGroup())
	{
		case ph1::CPatient::O:
			os << "Blood group: 0" << endl;
			break;

		case ph1::CPatient::A:
			os << "Blood group: A" << endl;
			break;

		case ph1::CPatient::B:
			os << "Blood group: B" << endl;
			break;

		case ph1::CPatient::AB:
			os << "Blood group: AB" << endl;
			break;

		default:
			_ASSERT(false);
			break;
	}

	return os;
}