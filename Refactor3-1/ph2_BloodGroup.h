#pragma once

/*
Tworzymy klasê zawieraj¹c¹ instancje oryginalnych kodów typu.
Na potrzeby inicjalizowania zmiennych typu CBloodGroup œwiadomie decydujê, aby kompilator
stworzy³ kod konstruktora kopiuj¹cego (nie jest to konieczne, ale wskazuje na intencjê autora kodu).
Tak samo post¹pi³em z destruktorem.
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