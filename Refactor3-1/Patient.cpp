#include "stdafx.h"
#include "Patient.h"

CPatient::CPatient(const string& strFirstName, const string& strLastName, const CBloodGroup& oBloodGroup):
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	m_oBloodGroup(oBloodGroup)
{
}

CPatient::~CPatient()
{
}

ostream& operator <<(ostream& os, const CPatient& oPatient)
{
	os << "First name: " << oPatient.GetFirstName() << endl;
	os << "Last name: " << oPatient.GetLastName() << endl;
	os << "Blood group: " << oPatient.GetBloodGroup().AsString() << endl;

	return os;
}
