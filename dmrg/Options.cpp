#include "stdafx.h"

#include "dmrg.h"
#include "Options.h"


Options::Options()
	: model(0), sites(60), states(10), sweeps(4),
	bigTicksX(6),
	bigTicksY(5),
	smallTicksX(2),
	smallTicksY(2),
	minEnergy(-0.7),
	maxEnergy(-0.2)
{
}


Options::~Options()
{
}


double Options::GetDouble(LPCTSTR param, double defval)
{
	double val = defval;

	UINT sz = 0;
	LPBYTE buf = NULL;

	if (theApp.GetProfileBinary(L"options", param, &buf, &sz))
	{
		if (sizeof(double) == sz) val = *((double*)buf);
		delete[] buf;
	}

	return val;
}

void Options::Load()
{
	model = theApp.GetProfileInt(L"options", L"model", 0);
	sites = theApp.GetProfileInt(L"options", L"sites", 60);
	states = theApp.GetProfileInt(L"options", L"states", 10);
	sweeps = theApp.GetProfileInt(L"options", L"sweeps", 4);

	bigTicksX = theApp.GetProfileInt(L"options", L"bigTicksX", 6);
	bigTicksY = theApp.GetProfileInt(L"options", L"bigTicksY", 5);
	smallTicksX = theApp.GetProfileInt(L"options", L"smallTicksX", 2);
	smallTicksY = theApp.GetProfileInt(L"options", L"smallTicksY", 2);

	minEnergy = GetDouble(L"minEnergy", -0.7);
	maxEnergy = GetDouble(L"maxEnergy", -0.2);
}

void Options::Save()
{
	theApp.WriteProfileInt(L"options", L"model", model);
	theApp.WriteProfileInt(L"options", L"sites", sites);
	theApp.WriteProfileInt(L"options", L"states", states);
	theApp.WriteProfileInt(L"options", L"sweeps", sweeps);

	theApp.WriteProfileInt(L"options", L"bigTicksX", bigTicksX);
	theApp.WriteProfileInt(L"options", L"bigTicksY", bigTicksY);
	theApp.WriteProfileInt(L"options", L"smallTicksX", smallTicksX);
	theApp.WriteProfileInt(L"options", L"smallTicksY", smallTicksY);

	theApp.WriteProfileBinary(L"options", L"minEnergy", (LPBYTE)&minEnergy, sizeof(double));
	theApp.WriteProfileBinary(L"options", L"maxEnergy", (LPBYTE)&maxEnergy, sizeof(double));
}
