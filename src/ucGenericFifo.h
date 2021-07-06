#ifndef __UC_GENERIC_FIFO_H__
#define __UC_GENERIC_FIFO_H__

#ifdef __cplusplus 
extern "C" {
#endif 

#include <stdbool.h>
#include <stdint.h>	
#include <stdlib.h>
#include <string.h>


typedef struct {
	int16_t head; 
	int16_t tail;
	uint16_t count; 
	size_t elemSize; 
	uint16_t elemCapacity; 
	void* buf;
} ucGenericFifo_t;

void ucGenericFifo_Init(ucGenericFifo_t *pFifo,  size_t elemSize, uint16_t numElems);
void ucGenericFifo_Init_Static(ucGenericFifo_t *pFifo,  void *buf, size_t elemSize, uint16_t numElems);
void ucGenericFifo_Put(ucGenericFifo_t *pFifo, void* data);
void ucGenericFifo_Get(ucGenericFifo_t *pFifo, void* data);
bool ucGenericFifo_isEmpty(ucGenericFifo_t *pFifo);
bool ucGenericFifo_isFull(ucGenericFifo_t *pFifo);
uint16_t ucGenericFifo_Cnt(ucGenericFifo_t *pFifo);
bool ucGenericFifo_Free(ucGenericFifo_t *pFifo);


#ifdef __cplusplus
}
#endif 


#endif 