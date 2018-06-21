#pragma once

/*
Pacjent posiada grup� krwi zamodelowan� z u�yciem kodu typu. 
Opisowa nazwa numerycznego kodu typu (poni�ej grupy krwi) jest czytelna.
Problem polega na tym, �e nazwa jest tylko aliasem - kompilator wci�� widzi liczb� i to
w oparciu o ni� wci�� sprawdza typ.
Metody pobieraj�ce kod typu jako parametr (np. konstruktor poni�ej) musz� go deklarowa� jako
parametr typu liczbowego.
Nic nie zmusza programisty do zastosowania aliasu, co mo�e sta� sie przyczyn� b��du
(np. w konstruktorze nie ma sprawdzenia poprawno�ci przekazanej z zewn�trz warto�ci).

Przyk�ad deklaracji obiekt�w:

CPatient oPatient("Piotr", "Nowak", CPatientVer1::B); // OK

CPatient oPatient("Jan", "Kowalski", 3); // U�ycie liczby "magicznej".

int iBloodGroup = DbFindBloodGroup("Jan", "Kowalski");
CPatient oPatient3("Jan", "Kowalski", iBloodGroup); // Brak kontroli nad warto�ci�.

Rozwi�zania:
1. Mo�na zastosowa� typ: enum class - to rozwi�zuje problem sprawdzania warto�ci.
   Jednak�e rodzi sie pytanie: dlaczego klasa pacjent dysponuje informacjami o wszystkich
   grupach krwi?
2. Mo�na wynie�� grup� krwi do osobnej klasy (patrz ph2::CBloodGroup).
   Je�elikod typupozostaje bez wp�ywuna zachowanie, to mo�emy zastosowa� zast�pienie kodu typu klas�.
*/

namespace ph1
{
	class CPatient
	{
	public:
		static const int O = 0;
		static const int A = 1;
		static const int B = 2;
		static const int AB = 3;

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
			m_iBloodGroup = iBloodGroup;
		}

		int GetBloodGroup() const
		{
			return m_iBloodGroup;
		}

		friend ostream& operator <<(ostream& os, const CPatient& oPatient);

	private:
		const string m_strFirstName;
		const string m_strLastName;
		int m_iBloodGroup;
	};
}