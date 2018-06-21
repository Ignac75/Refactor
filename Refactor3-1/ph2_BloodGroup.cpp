#include "stdafx.h"
#include "ph2_BloodGroup.h"

const ph2::CBloodGroup ph2::CBloodGroup::O(0);
const ph2::CBloodGroup ph2::CBloodGroup::A(1);
const ph2::CBloodGroup ph2::CBloodGroup::B(2);
const ph2::CBloodGroup ph2::CBloodGroup::AB(3);

ph2::CBloodGroup::CBloodGroup(int iGroup):
	m_iGroup(iGroup)
{
}

const ph2::CBloodGroup& ph2::CBloodGroup::GetBloodGroup(int iGroup)
{
	switch (iGroup)
	{
		case 0:
			return O;

		case 1:
			return A;

		case 2:
			return B;

		case 3:
			return AB;

		default:
			_ASSERT(false);
			return O;
	}
}
 