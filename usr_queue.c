#include "usr_queue.h"

/**
	*���г�ʼ��
	*@pram q ��Ҫ��ʼ���Ķ���
	*pArray  �������е�����
**/
Q_Status queue_point_init(Queue_t *q, void **pArray, uint16_t array_size) {
	q->front = 0;
	q->rear = 0;
	q->point_buff = pArray;
	q->size = array_size;

	return Q_OK;
}

Q_Status queue_byte_init(Queue_t *q, uint8_t *pArray, uint16_t array_size) {
	q->front = 0;
	q->rear = 0;
	q->byte_buff = pArray;
	q->size = array_size;

	return Q_OK;
}

uint16_t queue_length(Queue_t q)
{
	return (q.rear + q.size - q.front) % q.size;
}

void queue_clear(Queue_t *q)
{
	q->front = 0;
	q->rear = 0;
}

/**
	*���
**/
Q_Status queue_point_insert(Queue_t *q, void *e) {
    if (q->point_buff == NULL) {
        return Q_ERROR;
    }
	if ((q->rear+1)%q->size == q->front) {
		return Q_ERROR;
	}    

    q->point_buff[q->rear] = e;
	q->rear = (q->rear+1) % q->size;
	
	return Q_OK;
}

/**
	*����
**/
Q_Status queue_point_extract(Queue_t *q, void **e) {
    if (q->point_buff == NULL) {
        return Q_ERROR;
    }    
	if(q->front == q->rear)
	{
		return Q_ERROR;
	}

    *e = q->point_buff[q->front];
	q->front = (q->front+1)%q->size;
	
	return Q_OK;
}


Q_Status queue_byte_insert(Queue_t *q, uint8_t e) {
    if (q->byte_buff == NULL) {
        return Q_ERROR;
    }    
	if ((q->rear+1)%q->size == q->front) {
		return Q_ERROR;
	}

    q->byte_buff[q->rear] = e;
	q->rear = (q->rear+1) % q->size;
	
	return Q_OK;
}

/**
	*����
**/
Q_Status queue_byte_extract(Queue_t *q, uint8_t *e) {
    if (q->byte_buff == NULL) {
        return Q_ERROR;
    }    
    
	if( q->front == q->rear) {
		return Q_ERROR;
	}

    *e = q->byte_buff[q->front];
	q->front = (q->front+1)%q->size;
	
	return Q_OK;
}

