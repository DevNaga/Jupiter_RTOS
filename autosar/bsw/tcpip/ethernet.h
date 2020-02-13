#ifndef __ETHERNET_H__
#define __ETHERNET_H__

#include "autosar_std_types.h"

struct eth_header {
    uint8 srcmac[6];
    uint8 dstmac[6];
    uint16 ethertype;
};

int16 format_ethernet_header(uint8 *dstbuf, uint16 offset, uint8 *src, uint8 *dst, uint16 ethertype);
void send_ethernet_frame(uint8 *dstbuf, uint16 dstbuf_len);

#endif

