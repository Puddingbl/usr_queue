/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __USR_QUEUE_H
#define __USR_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

/* includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <string.h>
#include "SWM341.h"
/* define---------------------------------------------------------------------*/

typedef enum 
{
	Q_ERROR = -1,
	Q_OK    = 0
}	Q_Status;

typedef  void*     QElemType;

typedef uint32_t QElemPointType;
typedef uint8_t QElemDataType;

typedef struct {
	uint16_t front;         // �Ѷ�����ָ��
	uint16_t rear;    		// ��������ָ��
	uint16_t size;          // ���г���
//    uint16_t itemsize;      // ���г�Ա��С
//	QElemType *data;    
    
    uint8_t *byte_buff;     // �ֽڻ���
    void    **point_buff;   // ָ�뻺��
} Queue_t;

typedef struct {

    uint16_t itemsize;      // ���г�Ա��С
	QElemType *data;    
} queue_ex_t;


/* exported functions ------------------------------------------------------- */
Q_Status queue_point_init(Queue_t *q, void **pArray, uint16_t array_size);
uint16_t  queue_length(Queue_t q);
void queue_clear(Queue_t *q);
Q_Status queue_point_insert(Queue_t *q, void *e);
Q_Status queue_point_extract(Queue_t *q, void **e);

Q_Status queue_byte_init(Queue_t *q, uint8_t *pArray, uint16_t array_size);
Q_Status queue_byte_insert(Queue_t *q, uint8_t e);
Q_Status queue_byte_extract(Queue_t *q, uint8_t *e);

#ifdef __cplusplus
}
#endif

#endif
