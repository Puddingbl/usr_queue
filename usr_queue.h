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

//typedef struct
//{
//	uint8_t front;         // �Ѷ�����ָ��
//	uint8_t rear;    			 // ��������ָ��
//	uint8_t count;     		 // �ܹ��ж�������
//	uint8_t size;
//	QElemDataType *data;    
//} Queue_data_t;

/* exported functions ------------------------------------------------------- */
Q_Status queue_init(Queue_t *q, QElemType *pArray, uint8_t array_size, uint16_t item_size);
uint8_t  queue_length(Queue_t q);
void queue_clear(Queue_t *q);
Q_Status queue_insert(Queue_t *q, QElemType e);
Q_Status queue_extract(Queue_t *q, QElemType e);

//Q_Status queue_init_data(Queue_data_t *q, QElemDataType *pArray, uint8_t size);
//uint8_t  queue_length_data(Queue_data_t q);
//void queue_clear_data(Queue_data_t *q);
//Q_Status queue_insert_data(Queue_data_t *q, QElemDataType e);
//Q_Status queue_extract_data(Queue_data_t *q, QElemDataType *e);

#ifdef __cplusplus
}
#endif

#endif
