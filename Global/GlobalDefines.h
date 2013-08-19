//  Powiter
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
*Created by Alexandre GAUTHIER-FOICHAT on 6/1/2012. 
*contact: immarespond at gmail dot com
*
*/

 

 



#ifndef PowiterOsX_powiterFn_h
#define PowiterOsX_powiterFn_h
#include "Global/Enums.h"
#include <string>
#include <utility>
#ifdef __APPLE__
#define __POWITER_OSX__
#define __POWITER_UNIX__
#elif  defined(_WIN32)
#define __POWITER_WIN32__
#define NOMINMAX ///< Qt5 bug workaround with qdatetime.h
#include <windows.h>
#define OPENEXR_DLL
#elif defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
#define __POWITER_UNIX__
#define __POWITER_LINUX__
#endif


#define ROOT "/"
#define CACHE_ROOT_PATH "./"
#define IMAGES_PATH ":/Resources/Images/"
#define PLUGINS_PATH ROOT"Plugins"


// debug flag
#define PW_DEBUG

#ifndef Q_MOC_RUN
#include <boost/cstdint.hpp>
#endif
typedef boost::uint32_t U32;
typedef boost::uint64_t U64;
typedef boost::uint8_t U8;
typedef boost::uint16_t U16;


#include <QtCore/QForeachContainer>
#undef foreach
#define foreach Q_FOREACH





namespace PowiterWindows{
    
#ifdef __POWITER_WIN32__

	/*Converts a std::string to wide string*/
    inline std::wstring s2ws(const std::string& s)
    {
        int len;
        int slength = (int)s.length() + 1;
        len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
        wchar_t* buf = new wchar_t[len];
        MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
        std::wstring r(buf);
        delete[] buf;
        return r;
    }

#endif

}

#endif
