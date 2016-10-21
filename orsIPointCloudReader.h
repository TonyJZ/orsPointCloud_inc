#ifndef _ORS_POINTCLOUD_READER_H
#define _ORS_POINTCLOUD_READER_H

/*	��ɢ�����ݼ���ȡ		create by Tony   09.04.01	happy all fools' day!
*/

#pragma once


#include "orsPointCloud/orsIPointCloud.h"


interface orsIPointCloudReader : public orsIPointCloud
{
public:
	virtual bool open( const char *lasFileName, bool bShared = true ) = 0;
	
	virtual void close() = 0;

	// ���´ӵ�һ�����¼��ʼ��ȡ
	virtual void reopen() = 0;	

	// ��ȡ����
	virtual ors_int32 get_number_of_points() = 0;

	// ��ȡ����������룬��OpenRS Point Contents Mask
	virtual ors_uint32 get_point_contentMask() const = 0;

	// ��ȡ�ļ��ڲ���ƫ���������ű���
	virtual void  get_offset(double offset[3]) = 0;
	virtual void  get_scale_factor(double scale[3]) = 0;

	// ��ȡ�����ķ�Χ
	virtual void  get_boundary(orsPOINT3D *bbmax, orsPOINT3D *bbmin) = 0;

	// ������һ����Ķ�ȡλ��
	virtual bool set_readpos(int ptNum = 0) = 0;
	virtual bool set_readpos(ors_int64  offset) = 0;
	
	// ������û����꣬�������Ѿ���ת��
	virtual bool read_point(double coordinates[3]) = 0;

	// ������ڲ����꣬δ����ת����ת������ coord*scale+offset
	virtual bool read_rawpoint(int coordinates[3]) = 0;

	// ��Ե�ǰ��¼��������Ϣ�����������read_point��read_rawpoint֮�����
	// ��ȡ��ǰ��ز���
	virtual int get_number_of_returns() = 0;
	// ��ȡ��ǰ�����ڵڼ����ز�
	virtual int get_return_number() = 0;	
	// ��ȡgpsʱ��
	virtual double get_gpstime() = 0;
	// ��ȡ�ز�ǿ��
	virtual unsigned short get_intensity() = 0;
	// ��ȡ�����
	virtual unsigned char get_classification() = 0;
	// ��ȡ��ɫ
	virtual void get_rgb(unsigned short Rgb[3]) = 0;
	// ��ȡLidar�۲���Ϣ
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