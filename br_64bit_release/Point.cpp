/*----------------------------------------------------------------------------
 *
 *  Released Software:  BoxRouter 2.0
 *
 *  Copyright (c) 2007 Regents of Univerisity of Texas, Austin 
 *  (developed by UT Design Automation lab)
 *
 *  Authors:         
 *                   Minsik Cho -- thyeros@mail.cerc.utexas.edu
 *
 *                   Kun Yuan -- kyuan@cerc.utexas.edu
 *
 *                   Katrian Lu -- yiotse@cerc.utexas.edu
 *                   
 *                   David Z.Pan -- dpan@ece.utexas.edu
 *
 *                         All Rights Reserved
 *
 *  The Released Software is sent to the recipient upon request.
 *  The recipient agrees the following conditions for receiving and using
 *  the Released Software: 
 *  1. Redistributions of any code, with or without modification (the "Code"),
 *     must be accompanied by any documentation and, each time the resulting 
 *     executable program or a program dependent thereon is launched, a 
 *     prominent display (e.g., splash screen or banner text, of the Author's 
 *     attribution information, which includes:
 *     (a) Minsik Cho, Kun Yuan, Katrina Lu and Dr. David Z. Pan ("AUTHOR"),
 *     (b) The University of Texas at Austin ("PROFESSIONAL IDENTIFICATION"), and
 *     (c) http://www.cerc.utexas.edu/utda/ ("URL").
 *  2. Use is limited to academic research groups only. Users who are 
 *     interested in industry or commercial purposes must notify Author and 
 *     request separate license agreement.
 *  3. Neither the name nor any trademark of the Author may be used to endorse 
 *     or promote products derived from this software without specific prior
 *     written permission.
 *  4. Users are entirely responsible, to the exclusion of the Author and any 
 *     other persons,for compliance with 
 *     (1) regulations set by owners or administrators of employed equipment, 
 *     (2) licensing terms of any other software, and 
 *     (3) local, national, and international regulations regarding use, 
 *     including those regarding import, export, and use of encryption software.
 *  If the recipient is interested in using the software as the part of (or 
 *  as the basis of) any commercial software system or for designing and 
 *  developing commercial products, please contact  Prof. David Z.Pan at the 
 *  following address:
 *
 *  Prof. David Z.Pan
 *  University of Texas,Austin
 *  ACES 5.434
 *  Austin, TX 78741
 *  Tel: 512-471-1436
 *  Fax: 512-471-8967
 *  E.mail:  dpan@ece.utexas.edu
 *
 *
 *  The authors of the Released Software disclaim all warranties with regard
 *  to this software.  In no event shall we be liable for any special,
 *  indirect, or consequential damages or any damages whatsoever resulting
 *  from loss of use, data, or profits.
 *
 *----------------------------------------------------------------------------*/
// Point.cpp: implementation of the CPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "Wire.h"
#include "Point.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//! default value:
//! m_iX = m_iY = m_cZ = -1
CPoint::CPoint()
{
	m_iX		=	-1;
	m_iY		=	-1;
	m_cZ		=	-1;
}

CPoint::~CPoint()
{

}


//! set XYZ in m_iX, m_iY and m_cZ
//! this function would not call CPoint::CreateKey.
void CPoint::SetXYZ(int iX, int iY, int iZ)
{
	m_iX	=	iX;
	m_iY	=	iY;
	m_cZ	=	iZ;
}

//! get parent.
CWire* CPoint::GetParent()
{
	return	(CWire*)m_pParent;
}

//! get Manhattan Distance with given point. 3D version.
int CPoint::GetMDistance(CPoint *pPoint)
{
	return abs(X()-pPoint->X())+abs(Y()-pPoint->Y())+abs(Z()-pPoint->Z());
}

//! get Manhattan Distance with given position. 2D version.
int CPoint::GetMDistance2D(CPoint *pPoint)
{
	return abs(X()-pPoint->X())+abs(Y()-pPoint->Y());
}

//! compare with given point. 2D version.
int CPoint::IsSame2D(CPoint *pPoint)
{
	return	IsSame2D(pPoint->X(),pPoint->Y());
}

//! compare with given position. 2D version.
int CPoint::IsSame2D(int iX, int iY)
{
	return	(X()==iX&&Y()==iY);
}

//! compare with given point. 3D version.
int CPoint::IsSame3D(CPoint *pPoint)
{
	return	IsSame3D(pPoint->X(),pPoint->Y(),pPoint->Z());
}

//! compare with given position. 3D version.
int CPoint::IsSame3D(int iX, int iY, int iZ)
{
	return	(X()==iX&&Y()==iY&&Z()==iZ);
}

//! IsVertical || IsHorizontal
int CPoint::IsFlat(CPoint *pPoint)
{
	return	IsVertical(pPoint)||IsHorizontal(pPoint);
}

//! If has same X and Z but different Y
int CPoint::IsVertical(CPoint *pPoint)
{
	return	Z()==pPoint->Z()&&X()==pPoint->X()&&Y()!=pPoint->Y();
}

//! If has same Y and Z but different X
int CPoint::IsHorizontal(CPoint *pPoint)
{
	return	Z()==pPoint->Z()&&X()!=pPoint->X()&&Y()==pPoint->Y();
}

//! If has same X and Y but different Z
int CPoint::IsPerpendicular(CPoint *pPoint)
{
	return	Z()!=pPoint->Z()&&X()==pPoint->X()&&Y()==pPoint->Y();
}

//! Initialize this point;
//! call CPoint::SetXYZ and CPoint::CreatKey.
void CPoint::Initialize(int iX, int iY, int iZ, CWire *pParent)
{
	SetXYZ(iX,iY,iZ);

	m_pParent	=	(CObject*)pParent;

	CreateKey();
}

//! Set Z value in m_cZ.
//! This function would call CPoint::CreateKey.
void CPoint::SetZ(int iZ)
{
	m_cZ	=	iZ;

	CreateKey();
}

//! Generate this object's key with its position.
//! from lowest bit, 1 - 8 is Z, 9 - 20 is Y, 21 - 32 is X.
KEY CPoint::MakeKey(int iX, int iY, int iZ)
{
	return	iX<<20 | iY<<8 | iZ;
}

//! call CPoint::MakeKey and store key in m_Key.
void CPoint::CreateKey()
{
	//thyeros- key [6/16/2006]
	//thyeros- 12bits for X, 12bits for Y, 8bit for Z[6/16/2006]
	m_Key = MakeKey(X(),Y(),Z());
}

//! get X position from given Key
int CPoint::X(KEY Key)
{
	return	0xFFF & (Key>>20);
}

//! get Y position from given Key
int CPoint::Y(KEY Key)
{
	return	0xFFF & (Key>>8);
}

//! get Z position from given Key
int CPoint::Z(KEY Key)
{
	return	0xFF & (Key);
}

//! get the direction of given point.
//! return DIR_HORIZONTAL or DIR_VERTICAL or DIR_PERPENDICULAR or DIR_DIAGONAL
int CPoint::GetDirection(CPoint *pPoint)
{
	if (IsHorizontal(pPoint))		return	DIR_HORIZONTAL;
	if (IsVertical(pPoint))			return	DIR_VERTICAL;
	if (IsPerpendicular(pPoint))	return	DIR_PERPENDICULAR;

	return	DIR_DIAGONAL;
}

//! Set X value in m_iX.
//! This function would call CPoint::CreateKey.
void CPoint::SetX(int iX)
{
	m_iX	=	iX;

	CreateKey();
}

//! Set Y value in m_iY.
//! This function would call CPoint::CreateKey.
void CPoint::SetY(int iY)
{
	m_iY	=	iY;

	CreateKey();
}

//! Search the net which this point belong to, 
//! and compare each pin with the point.
int CPoint::IsPin()
{
	assert(GetParent());
	CNet*	pNet	=	GetParent()->GetParent();
	assert(pNet);

	// pin is in ZERO layer [7/7/2006 thyeros]
	for (int i=0;i<pNet->GetNumPin();++i)
	{
		if(IsSame2D(pNet->GetPin(i)))	return	TRUE;
	}

	return	FALSE;
}


//! Print information of this point to pFile.
//! iMode: PRINT_MODE_GNUPLOT | PRINT_MODE_GNUPLOT3D |
//! PRINT_MODE_MATLAB | PRINT_MODE_MATLAB3D | PRINT_MODE_TEXT
void CPoint::Print(FILE *pFile, int iMode)
{
	if(pFile==NULL)	return;

	switch(iMode){
	case PRINT_MODE_GNUPLOT:
		fprintf(pFile,"plot '-' w points pt 4 ps 1.5\n %d %d\n %d %d\ne\n",
			X(),Y(),
			X(),Y());
		break;
	case PRINT_MODE_GNUPLOT3D:
		fprintf(pFile,"splot '-' w points pt 4 ps 1.5\n %d %d %d\n %d %d %d\ne\n",
			X(),Y(),Z(),
			X(),Y(),Z());
		break;
	case PRINT_MODE_MATLAB:
		fprintf(pFile,"plot([%d,%d],[%d,%d],'.');\n",
			X(),X(),
			Y(),Y());
		break;
	case PRINT_MODE_MATLAB3D:
		fprintf(pFile,"plot3([%d,%d],[%d,%d],[%d,%d],'.');\n",
			X(),X(),
			Y(),Y(),
			Z(),Z());
		break;
	case PRINT_MODE_TEXT:
		fprintf(pFile,"p(%d,%d,%d)\n",
			X(),Y(),Z());
		break;
	default:
		assert(FALSE);
		break;
	}

	fflush(pFile);
}

