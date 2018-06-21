#include "stdafx.h"
#include "ph2_Patient.h"

const int ph2::CPatient::O = ph2::CBloodGroup::O.GetGroup();
const int ph2::CPatient::A = ph2::CBloodGroup::A.GetGroup();
const int ph2::CPatient::B = ph2::CBloodGroup::B.GetGroup();
const int ph2::CPatient::AB = ph2::CBloodGroup::AB.GetGroup();

ph2::CPatient::CPatient(const string& strFirstName, const string& strLastName, int iBloodGroup):
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	/**m_iBloodGroup(iBloodGroup)**/
	m_oBloodGroup(ph2::CBloodGroup::GetBloodGroup(iBloodGroup).GetGroup())
{
}

ph2::CPatient::~CPatient()
{
}

ostream& ph2::operator <<(ostream& os, const ph2::CPatient& oPatient)
{
	os << "First name: " << oPatient.GetFirstName() << endl;
	os << "Last name: " << oPatient.GetLastName() << endl;
	
	/**
	switch (oPatient.GetBloodGroup())
	{
		case ph2::CPatient::O:
			os << "Blood group: 0" << endl;
			break;

		case ph2::CPatient::A:
			os << "Blood group: A" << endl;
			break;

		case ph2::CPatient::B:
			os << "Blood group: B" << endl;
			break;

		case ph2::CPatient::AB:
			os << "Blood group: AB" << endl;
			break;

		default:
			_ASSERT(false);
			break;
	}
	**/
	if (oPatient.GetBloodGroup() == ph2::CPatient::O)
	{
		os << "Blood group: 0" << endl;
	}
	else if (oPatient.GetBloodGroup() == ph2::CPatient::A)
	{
		os << "Blood group: A" << endl;
	}
	else if (oPatient.GetBloodGroup() == ph2::CPatient::B)
	{
		os << "Blood group: B" << endl;
	}
	else if (oPatient.GetBloodGroup() == ph2::CPatient::AB)
	{
		os << "Blood group: AB" << endl;
	}
	else
	{
		_ASSERT(false);
	}

	return os;
}