#pragma once

/*
Usuwamy kody liczbowe.
*/
#include "ph3_BloodGroup.h"

namespace ph3
{
	class CPatient
	{
	public:
		/**static const int O;**/
		/**static const int A;**/
		/**static const int B;**/
		/**static const int AB;**/

		/**CPatient(const string& strFirstName, const string& strLastName, int iBloodGroup);**/
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

		/**void SetBloodGroup(int iBloodGroup)
		{
			m_oBloodGroup = ph2::CBloodGroup::GetBloodGroup(iBloodGroup);
		}**/
		void SetBloodGroup(const CBloodGroup& oBloodGroup)
		{
			m_oBloodGroup = oBloodGroup;
		}

		/**int GetBloodGroup() const
		{
			return m_oBloodGroup.GetGroup();
		}**/
		const CBloodGroup& GetBloodGroup() const
		{
			return m_oBloodGroup;
		}

		friend ostream& operator <<(ostream& os, const ph3::CPatient& oPatient);

	private:
		const string m_strFirstName;
		const string m_strLastName;
		CBloodGroup m_oBloodGroup;
	};
}