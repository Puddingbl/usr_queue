/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __USR_QUEUE_H
#define __USR_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

/* includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <string.h>

/* define---------------------------------------------------------------------*/

typedef enum 
{
	Q_ERROR = -1,
	Q_OK    = 0
}	Q_Status;

typedef  void*     QElemType;
//typedef  uint8_t     QElemDataType;

typedef uint32_t QElemPointType;
typedef uint8_t QElemDataType;

typedef struct
{
	uint8_t front;         // �Ѷ�����ָ��
	uint8_t rear;    			 // ��������ָ��
	uint8_t count;     		 // �ܹ��ж�������
	uint8_t size;         // ���г���
    uint16_t itemsize;    // ���г�Ա��С
	QElemType *data;    
} Queue_t;


/* exported functions ------------------------------------------------------- */
Q_Status queue_init(Queue_t *q, QElemType *pArray, uint8_t array_size, uint16_t item_size);
uint8_t  queue_length(Queue_t q);
void queue_clear(Queue_t *q);
Q_Status queue_insert(Queue_t *q, QElemType e);
Q_Status queue_extract(Queue_t *q, QElemType e);

#ifdef __cplusplus
}
#endif

#endif
