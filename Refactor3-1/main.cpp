// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ph1_Patient.h"
#include "ph2_Patient.h"
#include "ph3_Patient.h"
#include "Patient.h"

int main()
{
	{
		ph1::CPatient aPatients[] = {
			ph1::CPatient("Jan", "Nowak", ph1::CPatient::AB),
			ph1::CPatient("Marian", "Kowalski", 1)
		};
		for (auto&& oPatient : aPatients)
		{
			cout << oPatient << endl;
		}
		cout << endl;
	}
	{	// Zgodnie z założeniem nie ma zmian w wywołaniach po stronie klientów.
		ph2::CPatient aPatients[] = {
			ph2::CPatient("Jan", "Nowak", ph2::CPatient::AB),
			ph2::CPatient("Marian", "Kowalski", 1)
		};
		for (auto&& oPatient : aPatients)
		{
			cout << oPatient << endl;
		}
		cout << endl;
	}
	{	// Teraz musimy posługiwać się predefiniowanymi grupami krwi.
		ph3::CPatient aPatients[] = {
			ph3::CPatient("Jan", "Nowak", ph3::CBloodGroup::AB),
			ph3::CPatient("Marian", "Kowalski", ph3::CBloodGroup::A)
		};
		for (auto&& oPatient : aPatients)
		{
			cout << oPatient << endl;
		}
		cout << endl;
	}
	{
		CPatient aPatients[] = {
			CPatient("Jan", "Nowak", CBloodGroup::AB),
			CPatient("Marian", "Kowalski", CBloodGroup::A)
		};
		for (auto&& oPatient : aPatients)
		{
			cout << oPatient << endl;
		}
		cout << endl;
	}
	return 0;
}

