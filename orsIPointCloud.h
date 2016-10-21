#ifndef _ORS_POINTCLOUD_INTERFACE_H
#define _ORS_POINTCLOUD_INTERFACE_H

#include "orsBase/orsIObject.h"
#include "orsBase/orsString.h"


// OpenRS Point Contents Mask

#define ORS_PCM_XYZ					1L
#define ORS_PCM_INTENSITY			2L 
#define ORS_PCM_CLASS				4L
#define ORS_PCM_GPSTIME				8L
#define ORS_PCM_RGB					16L
#define ORS_PCM_NUM_RETURNS			32L
#define ORS_PCM_OBSINFO				64L

struct orsPointObservedInfo
{
	orsPOINT3D pos;	
	double roll;		
	double pitch;		
	double heading;		
	double scanAngle;	
	double range;		
};


interface orsIPointCloud : public orsIObject
{
public:
	ORS_INTERFACE_DEF(orsIObject, _T("pointcloud"))
};


#endif