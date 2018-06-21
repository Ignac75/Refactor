#pragma once

/*
Tworzymy klas� zawieraj�c� instancje oryginalnych kod�w typu.
Na potrzeby inicjalizowania zmiennych typu CBloodGroup �wiadomie decyduj�, aby kompilator
stworzy� kod konstruktora kopiuj�cego (nie jest to konieczne, ale wskazuje na intencj� autora kodu).
Tak samo post�pi�em z destruktorem.
*/

namespace ph2
{
	class CBloodGroup
	{
	public:
		static const CBloodGroup O;
		static const CBloodGroup A;
		static const CBloodGroup B;
		static const CBloodGroup AB;

		CBloodGroup(int iGroup);
		CBloodGroup(const CBloodGroup& oBloodGroup) = default;
		~CBloodGroup() = default;

		int GetGroup() const
		{
			return m_iGroup;
		}

		static const CBloodGroup& GetBloodGroup(int iGroup);

	private:
		int m_iGroup;
	};
}