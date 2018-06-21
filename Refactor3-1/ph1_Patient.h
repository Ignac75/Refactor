#pragma once

/*
Pacjent posiada grupê krwi zamodelowan¹ z u¿yciem kodu typu. 
Opisowa nazwa numerycznego kodu typu (poni¿ej grupy krwi) jest czytelna.
Problem polega na tym, ¿e nazwa jest tylko aliasem - kompilator wci¹¿ widzi liczbê i to
w oparciu o ni¹ wci¹¿ sprawdza typ.
Metody pobieraj¹ce kod typu jako parametr (np. konstruktor poni¿ej) musz¹ go deklarowaæ jako
parametr typu liczbowego.
Nic nie zmusza programisty do zastosowania aliasu, co mo¿e staæ sie przyczyn¹ b³êdu
(np. w konstruktorze nie ma sprawdzenia poprawnoœci przekazanej z zewn¹trz wartoœci).

Przyk³ad deklaracji obiektów:

CPatient oPatient("Piotr", "Nowak", CPatientVer1::B); // OK

CPatient oPatient("Jan", "Kowalski", 3); // U¿ycie liczby "magicznej".

int iBloodGroup = DbFindBloodGroup("Jan", "Kowalski");
CPatient oPatient3("Jan", "Kowalski", iBloodGroup); // Brak kontroli nad wartoœci¹.

Rozwi¹zania:
1. Mo¿na zastosowaæ typ: enum class - to rozwi¹zuje problem sprawdzania wartoœci.
   Jednak¿e rodzi sie pytanie: dlaczego klasa pacjent dysponuje informacjami o wszystkich
   grupach krwi?
2. Mo¿na wynieœæ grupê krwi do osobnej klasy (patrz ph2::CBloodGroup).
   Je¿elikod typupozostaje bez wp³ywuna zachowanie, to mo¿emy zastosowaæ zast¹pienie kodu typu klas¹.
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