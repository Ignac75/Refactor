#pragma once

/*
Wersja finalna po usuniêciu komentarzy.
*/

class CBloodGroup
{
public:
	static const CBloodGroup O;
	static const CBloodGroup A;
	static const CBloodGroup B;
	static const CBloodGroup AB;

	string AsString() const
	{
		return DESCR[static_cast<int>(m_eCode)];
	}

	CBloodGroup(const CBloodGroup&) = default;
	~CBloodGroup() = default;

private:
	enum class ECode
	{
		e0 = 0,
		eA,
		eB,
		eAB
	};

	static const string DESCR[];

	CBloodGroup(ECode eCode);

	ECode m_eCode;
};

