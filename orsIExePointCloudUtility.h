#ifndef ORS_EXE_POINTCLOUD_UTILITY_H
#define ORS_EXE_POINTCLOUD_UTILITY_H

#include "orsBase/orsIExe.h"

interface orsIExePointCloudUtility : public orsISimpleExe
{
public:
	ORS_INTERFACE_DEF( orsISimpleExe, "pointCloudUtility");
};


#define ORS_EXE_POINTCLOUD_UTILITY_LAS2PLY	_T("ors.execute.simple.pointCloudUtility.Las2Ply")


#endif