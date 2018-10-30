#include "xboxthread.h"
extern "C" {
#include <hidapi/hidapi.h>
}

void XboxThread::run() {
  if (hid_init()) //初始化
    return;
  int res;
  unsigned char buf[64];

  hid_device *handle;
  // Open the device using the VID, PID,
  // and optionally the Serial number.
  handle = hid_open(0x045e, 0x028e, NULL);
  if (handle == NULL) {
    return;
  }
  hid_set_nonblocking(handle, 1);
  while (isRunning) {

    res = hid_read(handle, buf, 64);
    if (res != 0) {

      p.buttonUp = buf[2] & 0x01;
      p.buttonDown = (buf[2] >> 1) & 0x01;
      p.buttonLeft = (buf[2] >> 2) & 0x01;
      p.buttonRight = (buf[2] >> 3) & 0x01;
      p.buttonStart = (buf[2] >> 4) & 0x01;
      p.buttonBack = (buf[2] >> 5) & 0x01;
      p.buttonLS = (buf[2] >> 6) & 0x01;
      p.buttonRS = (buf[2] >> 7) & 0x01;

      p.buttonLB = buf[3] & 0x01; //第二组按键
      p.buttonRB = (buf[3] >> 1) & 0x01;
      p.buttonXBox = (buf[3] >> 2) & 0x01;
      p.buttonA = (buf[3] >> 4) & 0x01;
      p.buttonB = (buf[3] >> 5) & 0x01;
      p.buttonX = (buf[3] >> 6) & 0x01;
      p.buttonY = (buf[3] >> 7) & 0x01;

      p.SLValue = buf[4]; //滑杆
      p.SRValue = buf[5];

      p.LSXValue = buf[7];
      p.LSYValue = buf[9];

      p.RSXValue = buf[11];
      p.RSYValue = buf[13];

      emit resultReady(p);
    }
  }

  hid_close(handle);

  /* Free static HIDAPI objects. */
  hid_exit();
}

void XboxThread::setrun(bool set) { isRunning = set; }
