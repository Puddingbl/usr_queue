#include "usr_queue.h"

/**
	*队列初始化
	*@pram q 需要初始化的队列
	*			 pArray  传给队列的数组
**/
Q_Status queue_init(Queue_t *q, QElemType *pArray, uint8_t array_size, uint16_t item_size)
{
	q->front = 0;
	q->rear = 0;
	q->data = pArray;
	q->size = array_size;
	q->itemsize = item_size;

	return Q_OK;
}

uint8_t queue_length(Queue_t q)
{
	return (q.rear + q.size - q.front) % q.size;
}

void queue_clear(Queue_t *q)
{
	q->front = 0;
	q->rear = 0;
}

/**
	*入队
**/
Q_Status queue_insert(Queue_t *q, QElemType e)
{
	if((q->rear+1)%q->size == q->front)
	{
		return Q_ERROR;
	}

    memcpy(&q->data[q->rear], e, q->itemsize);
	q->rear = (q->rear+1) % q->size;
	
	return Q_OK;
}

/**
	*出队
**/
Q_Status queue_extract(Queue_t *q, QElemType e)
{
	if(q->front == q->rear)
	{
		return Q_ERROR;
	}

    memcpy(e, &q->data[q->front], q->itemsize);
    // printf("e=%p\r\n", (uint8_t*)e); 
	q->front = (q->front+1)%q->size;
	
	return Q_OK;
}

///**
//	*队列初始化
//	*@pram q 需要初始化的队列
//	*			 pArray  传给队列的数组
//**/
//Q_Status queue_init_data(Queue_data_t *q, QElemDataType *pArray, uint8_t size)
//{
//	q->front = 0;
//	q->rear = 0;
//	q->data = pArray;
//	q->size = size;
//	
//	return Q_OK;
//}

//uint8_t queue_length_data(Queue_data_t q)
//{
//	return (q.rear + q.size - q.front) % q.size;
//}

//void queue_clear_data(Queue_data_t *q)
//{
//	q->front = 0;
//	q->rear = 0;
//}

///**
//	*入队
//**/
//Q_Status queue_insert_data(Queue_data_t *q, QElemDataType e)
//{
//	if((q->rear+1)%q->size == q->front)
//	{
//		return Q_ERROR;
//	}
//	
//	q->data[q->rear] = e;
//	q->rear = (q->rear+1) % q->size;
//	
//	return Q_OK;
//}

///**
//	*出队
//**/
//Q_Status queue_extract_data(Queue_data_t *q, QElemDataType *e)
//{
//	if(q->front == q->rear)
//	{
//		return Q_ERROR;
//	}
//	
//	*e = q->data[q->front];
//	q->front = (q->front+1)%q->size;
//	
//	return Q_OK;
//}
