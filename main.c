#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <sys/time.h>

#include "usbHidLib.h"
#define MY_VID 0x0079
#define MY_PID 0x0006

int main()
{
	while(1) {
		int32_t ret,i;
		uint8_t buff[64];
		if(usbOpen((unsigned int)MY_VID,(unsigned int)MY_PID) < 0) {
			printf("Cant open USB.\n");
			return ret;
		}
		if((ret = usbRead(buff)) < 0) {
			printf("Fail USB read.\n");
		}
		else if(ret == 0) {
			sleep(1);
			printf("Zero USB bytes read.\n");
		}
		else {
			for(i=0;i<ret;i++) {
				printf("%02x ",buff[i]);
			}
			printf("\n");
		}
		//usleep(1000);
		ret = 0;
		//sleep(1);
	}//end while(1)
	
}