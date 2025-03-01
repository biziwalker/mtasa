/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/deathmatch/logic/Utils.h
*  PURPOSE:     Miscellaneous utility functions
*  DEVELOPERS:  Christian Myhre Lundheim <>
*               Cecill Etheredge <>
*               Kevin Whiteside <>
*               aru <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __UTILS_H
#define __UTILS_H

#include <CVector.h>
#include <CVector2D.h>
#include <net/bitstream.h>
#include <cmath>
#include "CCommon.h"
#include "CPad.h"

bool            CheckNickProvided           ( const char* szNick );
float           DistanceBetweenPoints2D     ( const CVector& vecPosition1, const CVector& vecPosition2 );
float           DistanceBetweenPoints2D     ( const CVector2D& vecPosition1, const CVector2D& vecPosition2 );
float           DistanceBetweenPoints3D     ( const CVector& vecPosition1, const CVector& vecPosition2 );
bool            IsPointNearPoint2D          ( const CVector& vecPosition1, const CVector& vecPosition2, float fDistance );
bool            IsPointNearPoint3D          ( const CVector& vecPosition1, const CVector& vecPosition2, float fDistance );

void            ReplaceCharactersInString   ( char* szString, char cWhat, char cWith );
void            ReplaceOccurrencesInString  ( std::string &s, const char *a, const char *b );

bool            DoesDirectoryExist          ( const char* szPath );

bool            IsIn                        ( const char* szShortText, const char* szLongText );
char*           uppercase                   ( char* s );
void            stripString                 ( char* szString );
void            stripControlCodes           ( char* szString );
bool            StringBeginsWith            ( const char* szText, const char* szBegins );
bool            IsNumericString             ( const char* szString );
bool            IsNumericString             ( const char* szString, size_t sizeString );

void            DisconnectPlayer            ( class CGame* pGame, class CPlayer& Player, const char* szMessage );
void            DisconnectPlayer            ( class CGame* pGame, class CPlayer& Player, CPlayerDisconnectedPacket::ePlayerDisconnectType eDisconnectType,  const char* szMessage = "" );
void            DisconnectPlayer            ( class CGame* pGame, class CPlayer& Player, CPlayerDisconnectedPacket::ePlayerDisconnectType eDisconnectType,  time_t BanDuration, const char* szMessage = "" );
void            DisconnectConnectionDesync  ( class CGame* pGame, class CPlayer& Player, unsigned int uiCode );

bool            InitializeSockets           ( void );
bool            CleanupSockets              ( void );

float           GetRandomFloat              ( void );
double          GetRandomDouble             ( void );
int             GetRandom                   ( int iLow, int iHigh );

bool            IsValidFilePath             ( const char* szPath );
bool            IsValidOrganizationPath     ( const char* szPath );

unsigned int    HexToInt                    ( const char* szHex );
bool            XMLColorToInt               ( const char* szColor, unsigned long& ulColor );
bool            XMLColorToInt               ( const char* szColor, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue, unsigned char& ucAlpha );


inline unsigned long GetTime ( void )
{
    return GetTickCount32 ();
}

inline float WrapAround ( float fValue, float fHigh )
{
    return fValue - ( fHigh * floor ( static_cast < float > ( fValue / fHigh ) ) );
}

// Radians to degrees and vice versa
inline float ConvertRadiansToDegrees ( float fRotation )
{
    return WrapAround ( static_cast < float > ( fRotation * 180.0f / PI + 360.0f ), 360.0f );
}

inline float ConvertRadiansToDegreesNoWrap ( float fRotation )
{
    return static_cast < float > ( fRotation * 180.0f / PI);
}

inline void ConvertRadiansToDegrees ( CVector2D& vecRotation )
{
    vecRotation.fX = ConvertRadiansToDegrees ( vecRotation.fX );
    vecRotation.fY = ConvertRadiansToDegrees ( vecRotation.fY );
}

inline void ConvertRadiansToDegreesNoWrap ( CVector2D& vecRotation )
{
    vecRotation.fX = ConvertRadiansToDegreesNoWrap ( vecRotation.fX );
    vecRotation.fY = ConvertRadiansToDegreesNoWrap ( vecRotation.fY );
}

inline void ConvertRadiansToDegrees ( CVector& vecRotation )
{
    vecRotation.fX = ConvertRadiansToDegrees ( vecRotation.fX );
    vecRotation.fY = ConvertRadiansToDegrees ( vecRotation.fY );
    vecRotation.fZ = ConvertRadiansToDegrees ( vecRotation.fZ );
}

inline void ConvertRadiansToDegreesNoWrap ( CVector& vecRotation )
{
    vecRotation.fX = ConvertRadiansToDegreesNoWrap ( vecRotation.fX );
    vecRotation.fY = ConvertRadiansToDegreesNoWrap ( vecRotation.fY );
    vecRotation.fZ = ConvertRadiansToDegreesNoWrap ( vecRotation.fZ );
}

inline float ConvertDegreesToRadians ( float fRotation )
{
    return WrapAround ( static_cast < float > ( fRotation * PI / 180.0f + 2*PI ), static_cast < float > ( 2*PI ) );
}

inline float ConvertDegreesToRadiansNoWrap ( float fRotation )
{
    return static_cast < float > ( fRotation * PI / 180.0f );
}

inline void ConvertDegreesToRadians ( CVector2D& vecRotation )
{
    vecRotation.fX = ConvertDegreesToRadians ( vecRotation.fX );
    vecRotation.fY = ConvertDegreesToRadians ( vecRotation.fY );
}

inline void ConvertDegreesToRadiansNoWrap ( CVector2D& vecRotation )
{
    vecRotation.fX = ConvertDegreesToRadiansNoWrap ( vecRotation.fX );
    vecRotation.fY = ConvertDegreesToRadiansNoWrap ( vecRotation.fY );
}

inline void ConvertDegreesToRadians ( CVector& vecRotation )
{
    vecRotation.fX = ConvertDegreesToRadians ( vecRotation.fX );
    vecRotation.fY = ConvertDegreesToRadians ( vecRotation.fY );
    vecRotation.fZ = ConvertDegreesToRadians ( vecRotation.fZ );
}

inline void ConvertDegreesToRadiansNoWrap ( CVector& vecRotation )
{
    vecRotation.fX = ConvertDegreesToRadiansNoWrap ( vecRotation.fX );
    vecRotation.fY = ConvertDegreesToRadiansNoWrap ( vecRotation.fY );
    vecRotation.fZ = ConvertDegreesToRadiansNoWrap ( vecRotation.fZ );
}

// Assuming fValue is the result of a difference calculation, calculate
// the shortest positive distance after wrapping
inline float GetSmallestWrapUnsigned ( float fValue, float fHigh )
{
    float fWrapped =  fValue - ( fHigh * floor ( static_cast < float > ( fValue / fHigh ) ) );
    if ( fWrapped > fHigh / 2 )
        fWrapped = fHigh - fWrapped;
    return fWrapped;
}

// Escapes the HTML characters <, >, &, " and '. Don't forget to remove your buffer to avoid memory leaks.
const char* HTMLEscapeString ( const char *szSource );

bool ReadSmallKeysync ( CControllerState& ControllerState, NetBitStreamInterface& BitStream );
void WriteSmallKeysync ( const CControllerState& ControllerState, NetBitStreamInterface& BitStream );
bool ReadFullKeysync ( CControllerState& ControllerState, NetBitStreamInterface& BitStream );
void WriteFullKeysync ( const CControllerState& ControllerState, NetBitStreamInterface& BitStream );
void ReadCameraOrientation ( const CVector& vecBasePosition, NetBitStreamInterface& BitStream, CVector& vecOutCamPosition, CVector& vecOutCamFwd );


// Validation funcs
bool            IsNickValid                 ( const char* szNick );
bool            IsNametagValid              ( const char* szNick );
void            RotateVector                ( CVector& vecLine, const CVector& vecRotation );

// Network funcs
SString         LongToDottedIP              ( unsigned long ulIP );


inline bool IsVisibleCharacter ( unsigned char c )
{
    // 32..126 are visible characters
    return c >= 32 && c <= 126;
}

inline SString SQLEscape ( const SString& strEscapeString, bool bSingleQuotes, bool bDoubleQuotes )
{
    SString strParsedQuery = "";
    for ( unsigned int k = 0; k < strEscapeString.length (); k++ ) {
        if ( bSingleQuotes && strEscapeString[k] == '\'' )
            strParsedQuery += '\'';
        if ( bDoubleQuotes && strEscapeString[k] == '\"' )
            strParsedQuery += '\"';

        strParsedQuery += strEscapeString[k];
    }
    return strParsedQuery;
}

// Maths utility functions
CVector             ConvertEulerRotationOrder   ( const CVector& a_vRotation, eEulerRotationOrder a_eSrcOrder, eEulerRotationOrder a_eDstOrder );

// Clear list of object pointers
template < class T >
void DeletePointersAndClearList ( T& elementList )
{
    T cloneList = elementList;
    elementList.clear ();

    typename T::const_iterator iter = cloneList.begin ();
    for ( ; iter != cloneList.end () ; iter++ )
    {
        delete *iter;
    }
}

#endif
