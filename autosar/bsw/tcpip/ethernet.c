#include <ethernet.h>

int16 format_ethernet_header(uint8 *dstbuf, uint16 offset, uint8 *src, uint8 *dst, uint16 ethertype)
{
    memcpy(dstbuf + offset, src, 6);
    offset += 6;

    memcpy(dstbuf + offset, dst, 6);
    offset += 6;

    memcpy(dstbuf + offset, &ethertype, 2);
    offset += 2;

    return offset;
}

void send_ethernet_frame(uint8 *dstbuf, uint16 dstbuf_len)
{
    Serial.write(dstbuf, dstbuf_len);
}
