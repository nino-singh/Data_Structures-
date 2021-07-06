#include "ucByteFifo.h"


void ucByteFifo_Init(ucByteFifo_t *pFifo,  size_t elemSize, uint16_t numElems) {

	if((pFifo != NULL) && (elemSize > 0) && numElems > 0) {
		pFifo->head = 0;
		pFifo->tail = 0; 
		pFifo->buf = (uint8_t*)malloc(elemSize*numElems);
		pFifo->elemCapacity = numElems; 
		pFifo->count = 0; 
	}
}

void ucByteFifo_Init_Static(ucByteFifo_t *pFifo,  uint8_t *buf, size_t elemSize, uint16_t numElems) {
	
	if((pFifo != NULL) && (elemSize > 0) && numElems > 0) {
		pFifo->head = 0;
		pFifo->tail = 0; 
		pFifo->buf = buf;
		pFifo->elemCapacity = numElems; 
		pFifo->count = 0; 
	}
}

void ucByteFifo_Put(ucByteFifo_t *pFifo, uint8_t data) {
	//If full, don't add anything
	if(pFifo->count == pFifo->elemCapacity) {
		return;

	} 
	//If we're at last element spot in the buffer, add elem and wrap tail index
	//back to zero 
	else if (pFifo->tail == pFifo->elemCapacity-1) {
		pFifo->buf[pFifo->tail * pFifo->elemSize] = data; 
		pFifo->tail = 0; 
		pFifo->count++; 
	//Fifo has spaces and we're not at the end of the buffer yet 	
	} else {
		pFifo->buf[pFifo->tail * pFifo->elemSize] = data; 
		pFifo->tail++; 
		pFifo->count++; 
	}
}

void ucByteFifo_Get(ucByteFifo_t *pFifo, uint8_t* data) {
	//Fifo is empty, nothing to get
	if(pFifo->count == 0) {
		return;
	//Element to retreive is at last spot in the buffer, wrap head index
	//back to zero after getting it	
	} else if(pFifo->head == pFifo->elemCapacity-1) {
		*data = pFifo->buf[pFifo->head*pFifo->elemSize]; 
		pFifo->head = 0; 
		pFifo->count--; 
	//We're somewhere in middle of buffer, keep retreiving and increment head 
	//index	
	}  else {
		*data = pFifo->buf[pFifo->head*pFifo->elemSize]; 
		pFifo->head++; 
		pFifo->count--; 
	}
}

bool ucByteFifo_isEmpty(ucByteFifo_t *pFifo) {
	return (pFifo->count == 0);
}

bool ucByteFifo_isFull(ucByteFifo_t *pFifo) {
	return (pFifo->count == pFifo->elemCapacity); 
}

uint16_t ucByteFifo_Cnt(ucByteFifo_t *pFifo) {
	return pFifo->count; 
}

void ucByteFifo_Free(ucByteFifo_t *pFifo) {

}
