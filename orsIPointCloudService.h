#ifndef _ORS_POINTCLOUD_SERVICE_H_
#define _ORS_POINTCLOUD_SERVICE_H_

#include "orsBase/orsIService.h"
#include "orsBase/orsFileFormat.h"

#include "orsPointCloud/orsIPointCloudReader.h"
#include "orsPointCloud/orsIPointCloudWriter.h"


class orsIPointCloudService : public orsIService
{
public:
//	virtual int SizeOfType(orsDataTYPE type) = 0;

	//得到目前支持的所有的点云文件格式
// 	virtual orsFileFormatList getSupportedPointFormatsForRead() = 0;
// 	virtual orsFileFormatList getSupportedPointFormatsForWrite() = 0;

	//打开一个散点文件，将遍历所有的实现了orsIPointReader的对象来实现
	virtual orsIPointCloudReader *openPointFileForRead( const orsChar *filename, bool bShared = true ) = 0;

	virtual orsIPointCloudWriter *openPointFileForWrite( const char *fileFormat, const char *lasFileName, 
		lasDataFORMAT point_data_format, double xScale, double yScale, double zScale ) = 0;
	

		 
	ORS_INTERFACE_DEF( orsIService, "pointcloud" )
};

#define ORS_SERVICE_POINTCLOUD			"ors.service.pointcloud" 


// 获取日志服务的宏定义
orsIPointCloudService *getPointCloudlService();

#define ORS_GET_POINT_CLOUD_SERVICE_IMPL()	\
	static orsIPointCloudService *s_pointCloudService = NULL;\
	orsIPointCloudService *getPointCloudlService()\
{\
	if( NULL != s_pointCloudService )\
	return s_pointCloudService;\
	\
	s_pointCloudService =\
	ORS_PTR_CAST( orsIPointCloudService, getPlatform()->getService( ORS_SERVICE_POINTCLOUD) );\
	\
	return s_pointCloudService;\
}

#endif	// _ORS_IMAGE_SERVICE_H_