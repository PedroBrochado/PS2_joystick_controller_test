#ifndef __USBHIDLIB_H__
#define __USBHIDLIB_H__

#include <stdint.h>

//Prototypes
int32_t usbOpen(unsigned int vid, unsigned int pid);
int32_t usbRead(char* buf);
int32_t usbWrite(char* buf);
int32_t my_usb_close(void);
int32_t printDeviceInfo();

#endif //USBHIDLIB_H
