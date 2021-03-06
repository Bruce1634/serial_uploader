#ifndef __PACKET_H
#define	__PACKET_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define FW_HEAD_BYTE_1                         0X55
#define FW_HEAD_BYTE_2                         0XAA
#define FW_END_BYTE_1                          0XA5
#define FW_END_BYTE_2		                   0X5A

#define	FW_START1_POS                         0
#define	FW_START2_POS	                      1
#define	FW_DST_POS  	                      2
#define	FW_SRC_POS   	                      3
#define	FW_LEN_L_POS 	                      4
#define	FW_LEN_H_POS	                      5
#define	FW_CMD_POS   	                      6
#define	FW_DATA_POS   	                      7

#define	FW_CRC1_POS  	                      7
#define	FW_CRC2_POS  	                      8
#define	FW_END1_POS  	                      9
#define	FW_END2_POS  	                      10

#define FW_PAKET_TAIL_LEN  				 		4    
#define FW_PAKET_HEAD_LEN   					7    


#define FW_HEAD                                 0
#define FW_LEN                    1
#define FW_END                    2 

#define	FW_DATA	         	                   1
#define FW_DATA_CRC_TAIL    								2 
#define FW_PAKET_TAIL_LEN   4    
#define FW_PAKET_HEAD_LEN   7    
#define FW_PAKET_BUF_SIZE   200   
#define IAP_CONFIG_PACKET_BUFSIZE 		      600

#define IAP_FW_DATA_LEN  512
 enum {
     FW_UPDATE_REQ           =  	          1,
     FW_UPDATE_ACK	        = 	          2,
     FW_UPDATE_DATA 	  	    = 	          3,
     FW_UPDATE_ERROR  		=	          4,
     FW_UPDATE_OK     	    =             5,
     FW_UPDATE_VERREQ  	    =             6,
     FW_UPDATE_VERREPLY      =             7,
     FW_UPDATE_ACCOUNT_INFO_SET    =       8,
     FW_UPDATE_ACCOUNT_INFO_GET    =		  9,
     FW_UPDATE_ACCOUNT_INFO_REPLY  = 	  10,

     SPEED_INIT_CODE       = 0X13,
     SPEED_RUN_CODE	      = 0X14,
     ADD_SPEED_TIME_CODE   = 0X15,
     LIMIT_SWITCH_CODE     = 0X16,
     PULSE_SET_CODE        = 0X17,
     CONNITUE_RUN_CODE     = 0X18,
     STOP_CODE             = 0X19,
     STATE_POLL_CODE       = 0X1A,
     STATE_POLL_REPLY_CODE = 0X81,
     SENSOR_TRIGGER_CODE    = 0X21,

     CMD_LED_COLOR         =   0x31,
 };

#pragma pack(push, 1)
typedef struct  {
    uint8_t head0;
    uint8_t head1;
    uint8_t dest;
    uint8_t src;
    uint16_t length;
    uint8_t data[512];
    uint16_t crc;
    uint8_t  tail0;
    uint8_t  tail1;
}packet_desc_t;
#pragma pack(pop)

struct fw_update_s {
	bool app_update_req;
	bool  update_req;
	bool update_data;
	bool new_packet;
	uint8_t parse_packet_step;
	uint8_t update_step;
	uint16_t time_cnt;
	bool time_start;
	uint16_t rx_error;
	uint16_t crc_error;
} ;
typedef struct fw_update_s  fw_update_t;

#pragma pack(push, 1)
typedef struct {
    uint16_t total_block;
    uint16_t cur_block;
    uint16_t block_len;
    uint8_t data[IAP_FW_DATA_LEN];
} fw_packet_t;
#pragma pack(pop)

int packet_creat_address(uint8_t src, uint8_t dest);
void pakect_send(uint8_t cmd, uint8_t *playload, uint16_t length, uint8_t *buf, uint16_t *new_len);
bool packet_parse_data_callback(char data_char, packet_desc_t *packet);

#ifdef __cplusplus
}
#endif

#endif /* __PACKET_H */
