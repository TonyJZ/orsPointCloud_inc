#ifndef	_ORS_POINT_CLOUD_ALGORITHM__INTERFACE_H__
#define _ORS_POINT_CLOUD_ALGORITHM__INTERFACE_H__

#include "lasDef.h"
#include "orsPointStruDef.h"
#include "orsBase/orsIAlgorithm.h"


class orsIPointCloudAlgorithm : public orsIAlgorithm
{
public:
	//…Ë÷√≤Œ ˝
	virtual void setupParameterDlg() = 0;

	virtual bool run() = 0;

	virtual void setInputFile(char *input) = 0;
	virtual	void setOutputFile(char *output) = 0;

	ORS_INTERFACE_DEF( orsIAlgorithm, _T("pointcloud"))
};

#endif