// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#include <IOTOFBase/GeometryTGeo.h>
#include <TGeoManager.h>

namespace o2
{
namespace iotof
{
std::unique_ptr<o2::iotof::GeometryTGeo> GeometryTGeo::sInstance;

// Common i/oTOF
std::string GeometryTGeo::sIOTOFVolumeName = "IOTOFV";

// Inner TOF
std::string GeometryTGeo::sITOFLayerName = "ITOFLayer";
std::string GeometryTGeo::sITOFChipName = "ITOFChip";
std::string GeometryTGeo::sITOFSensorName = "ITOFSensor";

// Outer TOF
std::string GeometryTGeo::sOTOFLayerName = "OTOFLayer";
std::string GeometryTGeo::sOTOFChipName = "OTOFChip";
std::string GeometryTGeo::sOTOFSensorName = "OTOFSensor";

// Forward TOF
std::string GeometryTGeo::sFTOFLayerName = "FTOFLayer";
std::string GeometryTGeo::sFTOFChipName = "FTOFChip";
std::string GeometryTGeo::sFTOFSensorName = "FTOFSensor";

// Backward TOF
std::string GeometryTGeo::sBTOFLayerName = "BTOFLayer";
std::string GeometryTGeo::sBTOFChipName = "BTOFChip";
std::string GeometryTGeo::sBTOFSensorName = "BTOFSensor";

GeometryTGeo::GeometryTGeo(bool build, int loadTrans) : DetMatrixCache()
{
  if (sInstance) {
    LOGP(fatal, "Invalid use of public constructor: o2::iotof::GeometryTGeo instance exists");
  }
  if (build) {
    Build(loadTrans);
  }
}

void GeometryTGeo::Build(int loadTrans)
{
  if (isBuilt()) {
    LOGP(warning, "Already built");
    return; // already initialized
  }

  if (!gGeoManager) {
    LOGP(fatal, "Geometry is not loaded");
  }

  fillMatrixCache(loadTrans);
}

void GeometryTGeo::fillMatrixCache(int mask)
{
}

GeometryTGeo* GeometryTGeo::Instance()
{
  if (!sInstance) {
    sInstance = std::unique_ptr<GeometryTGeo>(new GeometryTGeo(true, 0));
  }
  return sInstance.get();
}

} // namespace iotof
} // namespace o2
