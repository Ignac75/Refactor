#pragma once

/*
Zast�pujemy kody liczbowe klas� CBloodGroup.
Naszym pierwszym celem jest uzyskanie kompiluj�cego si� kodu bez zmian w interfejsie
publicznym.
Zmieniane fragmenty kodu oznaczam komentarzem z **.
*/
#include "ph2_BloodGroup.h"

namespace ph2
{
	class CPatient
	{
	public:
		/**static const int O = 0;**/
		static const int O;
		/**static const int A = 1;**/
		static const int A;
		/**static const int B = 2;**/
		static const int B;
		/**static const int AB = 3;**/
		static const int AB;

		CPatient(const string& strFirstName, const string& strLastName, int iBloodGroup);
		virtual ~CPatient();

		string GetFirstName() const
		{
			return m_strFirstName;
		}

		string GetLastName() const
		{
			return m_strLastName;
		}

		void SetBloodGroup(int iBloodGroup)
		{
			/**m_iBloodGroup = iBloodGroup;**/
			m_oBloodGroup = ph2::CBloodGroup::GetBloodGroup(iBloodGroup);
		}

		int GetBloodGroup() const
		{
			/**return m_iBloodGroup;**/
			return m_oBloodGroup.GetGroup();
		}

		friend ostream& operator <<(ostream& os, const ph2::CPatient& oPatient);

	private:
		const string m_strFirstName;
		const string m_strLastName;
		/**int m_iBloodGroup;**/
		CBloodGroup m_oBloodGroup;
	};
}