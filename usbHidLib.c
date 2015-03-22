#include <hidapi.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
//API do USB
#include "usbHidLib.h"

//Endpoint specifications
#define EP_SIZE 64

static hid_device *hidHandle = NULL;

int32_t usbOpen(unsigned int vid, unsigned int pid)
{	
	hidHandle = hid_open(vid, pid, NULL);
//	printf("vid 0x%04x, pid 0x%04x\n",vid,pid);
	if (!hidHandle) {
		return -1;
	}
	if(hid_set_nonblocking(hidHandle, 1) < 0)
		return -2;
	return 0;
}

int32_t usbWrite(char* buf)
{
	int res;
	res = hid_write(hidHandle, (unsigned char*)buf, EP_SIZE);
	if (res < 0)
		return -1;
	return 0;
}

int32_t usbRead(char* buf)
{
	int res;
	res = hid_read(hidHandle, (unsigned char*)buf, EP_SIZE);
	if (res < 0)
		return res;
	if (res == 0)
		return 0;
	return res;
}

int32_t my_usb_close()
{
	if(hidHandle != NULL)
	{
		hid_close(hidHandle);
	}
	return 0;
}

int32_t printDeviceInfo()
{
	int res;
	#define MAX_STR 255
	wchar_t wstr[MAX_STR];
	
	// Read the Manufacturer String
	wstr[0] = 0x0000;
	res = hid_get_manufacturer_string(hidHandle, wstr, MAX_STR);
	if (res < 0)
		return -1;
	printf("Manufacturer String: %ls\n", wstr);

	// Read the Product String
	wstr[0] = 0x0000;
	res = hid_get_product_string(hidHandle, wstr, MAX_STR);
	if (res < 0)
		return -2;
	printf("Product String: %ls\n", wstr);

	// Read the Serial Number String
	wstr[0] = 0x0000;
	res = hid_get_serial_number_string(hidHandle, wstr, MAX_STR);
	if (res < 0)
		return -3;
	printf("Serial Number String: (%d) %ls\n", wstr[0], wstr);

	// Read Indexed String 1
	wstr[0] = 0x0000;
	res = hid_get_indexed_string(hidHandle, 1, wstr, MAX_STR);
	if (res < 0)
		return -4;
	printf("Indexed String 1: %ls\n", wstr);
	return 0;
}
