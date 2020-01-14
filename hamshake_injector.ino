#include <ESP8266WiFi.h>

extern "C" {
#include "user_interface.h"
  typedef void (*freedom_outside_cb_t)(uint8 status);
  int wifi_register_send_pkt_freedom_cb(freedom_outside_cb_t cb);
  void wifi_unregister_send_pkt_freedom_cb(void);
  int wifi_send_pkt_freedom(uint8 *buf, int len, bool sys_seq);
}

uint8_t packet0[] = {
  0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xda, 0xf1, 0x5b, 0x0c, 0xe2,
  0xff, 0xda, 0xf1, 0x5b, 0x0c, 0xe2, 0xff, 0xd0,
  0x36, 0x8a, 0xf5, 0xd3, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x64, 0x00, 0x11, 0x00, 0x00, 0x04, 0x74,
  0x65, 0x73, 0x74, 0x01, 0x08, 0x8b, 0x96, 0x82,
  0x84, 0x0c, 0x18, 0x30, 0x60, 0x03, 0x01, 0x01,
  0x05, 0x04, 0x00, 0x02, 0x00, 0x00, 0x07, 0x06,
  0x43, 0x4e, 0x00, 0x01, 0x0d, 0x14, 0x32, 0x04,
  0x6c, 0x12, 0x24, 0x48, 0xdd, 0x09, 0x18, 0xfe,
  0x34, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x18, 0x01, 0x00, 0x00, 0x0f, 0xac, 0x02, 0x02,
  0x00, 0x00, 0x0f, 0xac, 0x04, 0x00, 0x0f, 0xac,
  0x02, 0x01, 0x00, 0x00, 0x0f, 0xac, 0x02, 0x00,
  0x00 
};

uint8_t packet1[] = {
  0x08, 0x02, 0x3a, 0x01, 0xbc, 0xdd, 0xc2,
  0xb2, 0xc0, 0xab, 0xda, 0xf1, 0x5b, 0x0c, 0xe2,
  0xff, 0xda, 0xf1, 0x5b, 0x0c, 0xe2, 0xff, 0x00,
  0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x88,
  0x8e, 0x02, 0x03, 0x00, 0x5f, 0x02, 0x00, 0x8a,
  0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0xa3, 0x16, 0xe8, 0xc7, 0x81, 0xa0,
  0x4f, 0xfe, 0x9d, 0xab, 0x1c, 0x6c, 0xba, 0xc0,
  0xc8, 0xf2, 0x71, 0xce, 0x9f, 0xf4, 0x11, 0x56,
  0xf1, 0x0f, 0x33, 0x5b, 0x31, 0x71, 0xae, 0x8c,
  0xa5, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

uint8_t packet2[] = {
  0x08, 0x01, 0x3a, 0x01, 0xda, 0xf1, 0x5b,
  0x0c, 0xe2, 0xff, 0xbc, 0xdd, 0xc2, 0xb2, 0xc0,
  0xab, 0xda, 0xf1, 0x5b, 0x0c, 0xe2, 0xff, 0x00,
  0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x88,
  0x8e, 0x01, 0x03, 0x00, 0x75, 0x02, 0x01, 0x0a,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0xdb, 0x6a, 0x19, 0x1d, 0x59, 0x75,
  0xbf, 0x01, 0x0c, 0x7c, 0xb4, 0x41, 0xd6, 0xfb,
  0x2b, 0xcb, 0xf3, 0xf5, 0xfb, 0x21, 0x6b, 0x50,
  0xd8, 0xfb, 0xa6, 0x57, 0xb6, 0xef, 0xc9, 0x1a,
  0x4c, 0xc8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x23, 0x98, 0xca, 0x33, 0x5e, 0x53,
  0x26, 0x8a, 0x12, 0xe2, 0xea, 0x47, 0xd4, 0x6e,
  0xcb, 0x0f, 0x00, 0x16, 0x30, 0x14, 0x01, 0x00,
  0x00, 0x0f, 0xac, 0x02, 0x01, 0x00, 0x00, 0x0f,
  0xac, 0x04, 0x01, 0x00, 0x00, 0x0f, 0xac, 0x02,
  0x00, 0x00
};

uint8_t packet3[] = { 
  0x08, 0x02, 0x3a, 0x01, 0xbc, 0xdd, 0xc2,
  0xb2, 0xc0, 0xab, 0xda, 0xf1, 0x5b, 0x0c, 0xe2,
  0xff, 0xda, 0xf1, 0x5b, 0x0c, 0xe2, 0xff, 0x10,
  0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x88,
  0x8e, 0x02, 0x03, 0x00, 0xaf, 0x02, 0x13, 0xca,
  0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x02, 0xa3, 0x16, 0xe8, 0xc7, 0x81, 0xa0,
  0x4f, 0xfe, 0x9d, 0xab, 0x1c, 0x6c, 0xba, 0xc0,
  0xc8, 0xf2, 0x71, 0xce, 0x9f, 0xf4, 0x11, 0x56,
  0xf1, 0x0f, 0x33, 0x5b, 0x31, 0x71, 0xae, 0x8c,
  0xa5, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x61, 0x40, 0xb2, 0xb8, 0x81, 0xf6,
  0xd2, 0xc0, 0x2f, 0x92, 0x8a, 0x63, 0x36, 0x04,
  0x68, 0xc4, 0x00, 0x50, 0x67, 0x1c, 0x65, 0xee,
  0xc4, 0xba, 0xf0, 0x2d, 0xe9, 0x0e, 0xfe, 0x58,
  0x65, 0x7d, 0xfc, 0xab, 0xe9, 0x8e, 0x99, 0x0f,
  0xcf, 0x04, 0x39, 0x3b, 0x20, 0x3c, 0x17, 0xc6,
  0xec, 0xd9, 0x2a, 0xda, 0x31, 0xa6, 0xd8, 0x42,
  0xfd, 0x66, 0x8e, 0x09, 0x47, 0xeb, 0x0d, 0x1c,
  0x0a, 0x5f, 0x69, 0x47, 0xdf, 0x68, 0xf7, 0xf0,
  0x98, 0xa9, 0xb0, 0x8c, 0xa7, 0x61, 0x45, 0x60,
  0xb2, 0x09, 0xce, 0x99, 0xae, 0xba, 0xb5, 0xea,
  0xba, 0x4c, 0xc0, 0x76, 0xe7, 0x4b, 0x8e, 0x01,
  0x06, 0x9c, 0x9c, 0x43
};
uint8_t packet4[] = {
  0x08, 0x01, 0x3a, 0x01, 0xda, 0xf1, 0x5b,
  0x0c, 0xe2, 0xff, 0xbc, 0xdd, 0xc2, 0xb2, 0xc0,
  0xab, 0xda, 0xf1, 0x5b, 0x0c, 0xe2, 0xff, 0x10,
  0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x88,
  0x8e, 0x01, 0x03, 0x00, 0x5f, 0x02, 0x03, 0x0a,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xb5, 0x84, 0x9b, 0x18, 0x61, 0x0b,
  0xd3, 0x76, 0x1d, 0x79, 0x21, 0xdd, 0x0a, 0xcf,
  0x2d, 0x00, 0x00, 0x00
};

void setup() {
  Serial.begin(115200);
  Serial.println();

  // start WiFi
  WiFi.mode(WIFI_OFF);
  wifi_set_opmode(STATION_MODE);

  // set channel
  wifi_set_channel(11);
}

void loop() {
  int i=0;
  i += wifi_send_pkt_freedom(packet0, sizeof(packet0), 0);
  delay(100);
  i += wifi_send_pkt_freedom(packet1, sizeof(packet1), 0);
  delay(100);
  i += wifi_send_pkt_freedom(packet2, sizeof(packet2), 0);
  delay(100);
  i += wifi_send_pkt_freedom(packet3, sizeof(packet3), 0);
  delay(100);
  i += wifi_send_pkt_freedom(packet4, sizeof(packet4), 0);
  delay(100);
  Serial.println(i);
  delay(500);
}