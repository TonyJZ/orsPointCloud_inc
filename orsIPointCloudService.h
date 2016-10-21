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

	//�õ�Ŀǰ֧�ֵ����еĵ����ļ���ʽ
// 	virtual orsFileFormatList getSupportedPointFormatsForRead() = 0;
// 	virtual orsFileFormatList getSupportedPointFormatsForWrite() = 0;

	//��һ��ɢ���ļ������������е�ʵ����orsIPointReader�Ķ�����ʵ��
	virtual orsIPointCloudReader *openPointFileForRead( const orsChar *filename, bool bShared = true ) = 0;

	virtual orsIPointCloudWriter *openPointFileForWrite( const char *fileFormat, const char *lasFileName, 
		lasDataFORMAT point_data_format, double xScale, double yScale, double zScale ) = 0;
	

		 
	ORS_INTERFACE_DEF( orsIService, "pointcloud" )
};

#define ORS_SERVICE_POINTCLOUD			"ors.service.pointcloud" 


// ��ȡ��־����ĺ궨��
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