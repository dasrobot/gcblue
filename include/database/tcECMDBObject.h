/**
**  @file tcECMDBObject.h
*/
/*
**  Copyright (c) 2014, GCBLUE PROJECT
**  All rights reserved.
**
**  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
**
**  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
**
**  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the 
**     documentation and/or other materials provided with the distribution.
**
**  3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from 
**     this software without specific prior written permission.
**
**  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
**  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
**  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
**  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
**  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
**  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _ECMDBOBJECT_H_
#define _ECMDBOBJECT_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "tcSensorDBObject.h"
#include "database/tcSqlReader.h"

namespace database
{
	class tcSqlReader;

	/**
	* Electronic Counter Measures (ECM) modeled as type of "sensor" object
	*/
	class tcECMDBObject : public tcSensorDBObject 
	{
	public:
		std::string ecmType;     ///< "Jammer" "Deception"
		float ERP_dBW;           ///< [dBW] effective radiated power (assume bandwidth matched to target radars)
		float effectivenessRating; ///< 0 - 1.0
		bool isEffectiveVsSurveillance;
		bool isEffectiveVsSeeker;

		virtual tcSensorState* CreateSensor(tcGameObject* parent); ///< factory method
		virtual const char* GetClassName() const {return "ECM";} ///< returns class name of database object
		virtual void PrintToFile(tcFile& file);

        virtual const char* GetTypeDescription() const;

		tcECMDBObject();
		tcECMDBObject(tcECMDBObject& obj); ///< copy constructor
		virtual ~tcECMDBObject();

		static void AddSqlColumns(std::string& columnString);
		void ReadSql(tcSqlReader& entry);
		void WriteSql(std::string& valueString);

	};

} // namespace database

#endif

