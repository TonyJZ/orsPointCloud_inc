#ifndef _ORS_POINTCLOUD_WRITER_H
#define _ORS_POINTCLOUD_WRITER_H

//#include "orsBase/orsIObject.h"
#include "orsPointCloud/orsIPointCloud.h"
//#include "lastools/lasdefinitions.h"


enum lasDataFORMAT	{
	lasPOINT = 0,
		lasPOINT_GPS = 1,
		lasPOINT_RGB = 2,
		lasPOINT_GPS_RGB = 3,
		lasPOINT_ATN = 9,
		lasPOINT_ATN_RGB = 10
};


interface orsIPointCloudWriter: public orsIPointCloud
{
public:
	// 取文件格式名
	virtual orsString get_file_format()	const = 0;

	// 取支持存储的内容
	virtual ors_uint32 getSupportedContents() const = 0;
	
	virtual bool open(const char *lasFileName, lasDataFORMAT point_data_format=lasPOINT,  
		double xScale=0, double yScale=0, double zScale=0) = 0;

// 	virtual bool open(const char *lasFileName, lasDataFORMAT point_data_format,  
// 		double scale[3], double offset[3]) = 0;
	
	virtual void close() = 0;

	virtual bool set_writepos(ors_int64  offset) = 0;

	virtual bool write_point(double* coordinates) = 0;
	virtual bool write_point(double* coordinates, unsigned short intensity, unsigned short* rgb = NULL ) = 0;

	virtual bool write_point(double X, double Y, double Z) = 0;
	virtual bool write_point(double X, double Y, double Z, unsigned short r, unsigned short g, unsigned short b ) = 0;

	virtual bool write_point(double* coordinates, unsigned short intensity,
		unsigned char return_number, unsigned char number_of_returns_of_given_pulse,
		unsigned char scan_direction_flag, unsigned char edge_of_flight_line,
		unsigned char classification, 
		char scan_angle_rank, unsigned char user_data,
		unsigned short point_source_ID, double gps_time = 0, unsigned short* rgb = 0) = 0;

	virtual bool write_point(double* coordinates, unsigned short intensity,
		unsigned char return_number, unsigned char number_of_returns_of_given_pulse,
		unsigned char scan_direction_flag, unsigned char edge_of_flight_line,
		unsigned char classification, 
		char scan_angle_rank, unsigned char user_data,
		unsigned short point_source_ID, double gps_time, orsPointObservedInfo *info,
		unsigned short* rgb = 0) = 0;

public:	
	ORS_INTERFACE_DEF(orsIPointCloud, _T("writer"))
};

#define ORS_INTERFACE_POINTCLOUDSOURCE_WRITER		"ors.pointcloud.writer"
#define ORS_INTERFACE_POINTCLOUDSOURCE_WRITER_LAS	"ors.pointcloud.writer.las"
#define ORS_INTERFACE_POINTCLOUDSOURCE_WRITER_ATN	"ors.pointcloud.writer.atn"


#endif