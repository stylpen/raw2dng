/* Copyright (C) 2015 Fimagena

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#pragma once

#include "../negativeProcessor.h"


class DNGprocessor : public NegativeProcessor {
friend class NegativeProcessor;

public:
   void setDNGPropertiesFromRaw();
   void setCameraProfile(const char *dcpFilename);
   void setExifFromRaw(const dng_date_time_info &dateTimeNow, const dng_string &appNameVersion);
   void setXmpFromRaw(const dng_date_time_info &dateTimeNow, const dng_string &appNameVersion);
   void backupProprietaryData();
   void buildDNGImage();

protected:
   DNGprocessor(AutoPtr<dng_host> &host, LibRaw *rawProcessor, Exiv2::Image::AutoPtr &rawImage);
};
