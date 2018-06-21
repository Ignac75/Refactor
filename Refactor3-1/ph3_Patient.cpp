#include "stdafx.h"
#include "ph3_Patient.h"

/**const int ph2::CPatient::O = ph2::CBloodGroup::O.GetGroup();**/
/**const int ph2::CPatient::A = ph2::CBloodGroup::A.GetGroup();**/
/**const int ph2::CPatient::B = ph2::CBloodGroup::B.GetGroup();**/
/**const int ph2::CPatient::AB = ph2::CBloodGroup::AB.GetGroup();**/

/**ph2::CPatient::CPatient(const string& strFirstName, const string& strLastName, int iBloodGroup):**/
ph3::CPatient::CPatient(const string& strFirstName, const string& strLastName, const CBloodGroup& oBloodGroup) :

	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	/**m_oBloodGroup(ph2::CBloodGroup::GetBloodGroup(iBloodGroup).GetGroup())**/
	m_oBloodGroup(oBloodGroup)
{
}

ph3::CPatient::~CPatient()
{
}

ostream& ph3::operator <<(ostream& os, const ph3::CPatient& oPatient)
{
	os << "First name: " << oPatient.GetFirstName() << endl;
	os << "Last name: " << oPatient.GetLastName() << endl;
	
	/**if (oPatient.GetBloodGroup() == ph2::CPatient::O)
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
	}**/
	os << "Blood group: " << oPatient.GetBloodGroup().AsString() << endl;

	return os;
}