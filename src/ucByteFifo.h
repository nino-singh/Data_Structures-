#ifndef __UC_BYTE_FIFO_H__
#define __UC_BYTE_FIFO_H__

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
	uint8_t* buf;
} ucByteFifo_t;

void ucByteFifo_Init(ucByteFifo_t *pFifo,  size_t elemSize, uint16_t numElems);
void ucByteFifo_Init_Static(ucByteFifo_t *pFifo,  uint8_t *buf, size_t elemSize, uint16_t numElems);
void ucByteFifo_Put(ucByteFifo_t *pFifo, uint8_t data);
void ucByteFifo_Get(ucByteFifo_t *pFifo, uint8_t* data);
bool ucByteFifo_isEmpty(ucByteFifo_t *pFifo);
bool ucByteFifo_isFull(ucByteFifo_t *pFifo);
uint16_t ucByteFifo_Cnt(ucByteFifo_t *pFifo);
void ucByteFifo_Free(ucByteFifo_t *pFifo);


#ifdef __cplusplus
}
#endif 
#endif