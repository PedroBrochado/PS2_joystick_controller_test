CC = gcc
CFLAGS = -g -O2 -Wall -c
INCPATH = -I./include
TARGET = support_hid_lib.a
AR = ar cru
RANLIB = ranlib
USB_OBJS = hid.o

all: $(USB_OBJS)
	$(AR) $(TARGET) $(USB_OBJS)
	$(RANLIB) $(TARGET)

$(USB_OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(INCPATH) $< -o $@

clean:
	rm *.o $(TARGET)
