#ifndef _ORS_POINTCLOUD_READER_H
#define _ORS_POINTCLOUD_READER_H

/*	离散点数据集读取		create by Tony   09.04.01	happy all fools' day!
*/

#pragma once


#include "orsPointCloud/orsIPointCloud.h"


interface orsIPointCloudReader : public orsIPointCloud
{
public:
	virtual bool open( const char *lasFileName, bool bShared = true ) = 0;
	
	virtual void close() = 0;

	// 重新从第一个点记录开始读取
	virtual void reopen() = 0;	

	// 获取点数
	virtual ors_int32 get_number_of_points() = 0;

	// 获取点的内容掩码，见OpenRS Point Contents Mask
	virtual ors_uint32 get_point_contentMask() const = 0;

	// 获取文件内部的偏移量和缩放比例
	virtual void  get_offset(double offset[3]) = 0;
	virtual void  get_scale_factor(double scale[3]) = 0;

	// 获取坐标点的范围
	virtual void  get_boundary(orsPOINT3D *bbmax, orsPOINT3D *bbmin) = 0;

	// 设置下一个点的读取位置
	virtual bool set_readpos(int ptNum = 0) = 0;
	virtual bool set_readpos(ors_int64  offset) = 0;
	
	// 读点的用户坐标，该坐标已经过转换
	virtual bool read_point(double coordinates[3]) = 0;

	// 读点的内部坐标，未进行转换，转换方法 coord*scale+offset
	virtual bool read_rawpoint(int coordinates[3]) = 0;

	// 针对当前记录的其它信息，必须紧接着read_point，read_rawpoint之后调用
	// 获取当前点回波数
	virtual int get_number_of_returns() = 0;
	// 获取当前点属于第几个回波
	virtual int get_return_number() = 0;	
	// 获取gps时间
	virtual double get_gpstime() = 0;
	// 获取回波强度
	virtual unsigned short get_intensity() = 0;
	// 获取分类号
	virtual unsigned char get_classification() = 0;
	// 获取颜色
	virtual void get_rgb(unsigned short Rgb[3]) = 0;
	// 获取Lidar观测信息
	virtual bool get_point_observed_info(orsPointObservedInfo* info) = 0;

	virtual unsigned char get_scan_direction_flag() = 0;
	virtual unsigned char get_edge_of_flight_line() = 0;
	virtual char get_scan_angle_rank() = 0;
	virtual unsigned char get_user_data() = 0;
	virtual unsigned short get_point_source_ID() = 0;

public:
	ORS_INTERFACE_DEF(orsIPointCloud, _T("reader"))
};


enum orsPointAttributionFlag
{
	PA_ELEVATION = 0,
	PA_INTENSIT