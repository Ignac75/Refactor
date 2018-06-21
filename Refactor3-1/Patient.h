#pragma once

/*
Wersja finalna bez komentarzy.
*/
#include "BloodGroup.h"

class CPatient
{
public:
	CPatient(const string& strFirstName, const string& strLastName, const CBloodGroup& oBloodGroup);
	virtual ~CPatient();

	string GetFirstName() const
	{
		return m_strFirstName;
	}

	string GetLastName() const
	{
		return m_strLastName;
	}

	void SetBloodGroup(const CBloodGroup& oBloodGroup)
	{
		m_oBloodGroup = oBloodGroup;
	}

	const CBloodGroup& GetBloodGroup() const
	{
		return m_oBloodGroup;
	}

	friend ostream& operator <<(ostream& os, const CPatient& oPatient);

private:
	const string m_strFirstName;
	const string m_strLastName;
	CBloodGroup m_oBloodGroup;
};
