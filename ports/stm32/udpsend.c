#include "udpsend.h"
/************************************************************
 * UDP SEND PAYLOAD
 * Send a payload to port 9000 through UDP
************************************************************/
err_t senderr;

void mp_init_udp(udp_send_obj_t *UDP){

    UDP->pcb = udp_new();
    
    UDP->port = 9000;
    
    IP4_ADDR(&UDP->destip,192,168,4,16);

}


err_t mp_send_udp(struct udp_pcb *udppcb ,const u32_t *payload, ip_addr_t *dest_ip, u16_t port, u16_t payloadsize){


    struct pbuf *p;

    p = pbuf_alloc(PBUF_TRANSPORT, payloadsize, PBUF_RAM);

    if (p!=NULL){

        pbuf_take(p, (char*)payload , p->tot_len);

        senderr = udp_sendto(udppcb, p, dest_ip, port);

        pbuf_free(p);

    }

    return senderr;

}