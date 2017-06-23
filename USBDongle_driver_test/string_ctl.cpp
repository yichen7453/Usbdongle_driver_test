#include "stdafx.h"
#include "string_ctl.h"

char* getResult(int number)
{
	char *result = NULL;

	switch (number)
	{
		case 0:
			result = "S_OK";
			break;
		case 1:
			result = "S_FALSE";
			break;
		default:
			break;
	}

	return result;
}

char* getSensorStatus(int number)
{
	char *status = NULL;

	switch (number)
	{
		case 0:
			status = "WINBIO_SENSOR_STATUS_UNKNOWN";
			break;
		case 1:
			status = "WINBIO_SENSOR_ACCEPT";
			break;
		case 2:
			status = "WINBIO_SENSOR_REJECT";
			break;
		case 3:
			status = "WINBIO_SENSOR_READY";
			break;
		case 4:
			status = "WINBIO_SENSOR_BUSY";
			break;
		case 5:
			status = "WINBIO_SENSOR_NOT_CALIBRATED";
			break;
		case 6:
			status = "WINBIO_SENSOR_FAILURE";
			break;
		default:
			break;
	}
	return status;
}

char* getType(int number)
{
	char* type = NULL;

	switch (number)
	{
		case 8:
			type = "FINGERPRINT";
			break;
		default:
			type = "UNKNOWN";
			break;
	}
	return type;
}

char* getSubType(int number)
{
	char *subtype = NULL;

	switch (number)
	{
		case 0:
			subtype = "UNKNOWN";
			break;
		case 1:
			subtype = "SWIPE";
			break;
		case 2:
			subtype = "TOUCH";
			break;
		default:
			subtype = "UNKNOWN";
			break;
	}
	return subtype;
}

char* getCapabilities(int number) 
{
	char *capabilities = NULL;

	switch (number)
	{	
		case 1:
			capabilities = "SENSOR";
			break;
		case 2:
			capabilities = "MATCHING";
			break;
		case 4:
			capabilities = "DATABASE";
			break;
		case 8:
			capabilities = "PROCESSING";
			break;
		case 10:
			capabilities = "ENCRYPTION";
			break;
		case 20:
			capabilities = "NAVIGATION";
			break;
		case 40:
			capabilities = "INDICATOR";
			break;
		default:
			capabilities = "UNKNOWN";
			break;
	}
	return capabilities;
}
