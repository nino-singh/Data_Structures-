#include "ucGenericFifo.h"

/** 
* Add element to rear and remove element from front
* If front or rear indices reach end of buffer, wrap around to the
* beginning of the buffer to keep adding new elements or removing
* if fifo is full, we can't add new elements, if fifo is empty, 
* we cannot get an element 
*/

void ucGenericFifo_Init(ucGenericFifo_t *pFifo,  size_t elemSize, uint16_t numElems) {

	if(pFifo != NULL && (elemSize > 0) && numElems > 0) {
		pFifo->head = 0; 
		pFifo->tail = 0; 
		pFifo->count = 0; 
		pFifo->elemSize = elemSize; 
		pFifo->elemCapacity = numElems; 
		pFifo->buf = malloc(elemSize*numElems);
	}
}
void ucGenericFifo_Init_Static(ucGenericFifo_t *pFifo, void* buf, size_t elemSize, uint16_t numElems) {

	if(pFifo != NULL && buf != NULL && (elemSize > 0) && numElems > 0) {
		pFifo->head = 0; 
		pFifo->tail = 0; 
		pFifo->count = 0; 
		pFifo->elemSize = elemSize; 
		pFifo->elemCapacity = numElems; 
		pFifo->buf = buf; 
	}
}

void ucGenericFifo_Put(ucGenericFifo_t *pFifo, void* data) {

	//If full, don't add anything
	if(pFifo->count == pFifo->elemCapacity) {
		return;

	} 
	//If we're at last element spot in the buffer, add elem and wrap tail index
	//back to zero 
	else if (pFifo->tail == pFifo->elemCapacity-1) {
		memcpy(&pFifo->buf[pFifo->tail * pFifo->elemSize], data, pFifo->elemSize); 
		pFifo->tail = 0; 
		pFifo->count++; 
	//Fifo has spaces and we're not at the end of the buffer yet 	
	} else {
		memcpy(&pFifo->buf[pFifo->tail * pFifo->elemSize], data, pFifo->elemSize); 
		pFifo->tail++; 
		pFifo->count++; 
	}
}

void ucGenericFifo_Get(ucGenericFifo_t *pFifo, void* data) {

	//Fifo is empty, nothing to get
	if(pFifo->count == 0) {
		return;
	//Element to retreive is at last spot in the buffer, wrap head index
	//back to zero after getting it	
	} else if(pFifo->head == pFifo->elemCapacity-1) {
		memcpy(data, &pFifo->buf[pFifo->head*pFifo->elemSize], pFifo->elemSize);
		pFifo->head = 0; 
		pFifo->count--; 
	//We're somewhere in middle of buffer, keep retreiving and increment head 
	//index	
	}  else {
		memcpy(data, &pFifo->buf[pFifo->head*pFifo->elemSize], pFifo->elemSize);
		pFifo->head++; 
		pFifo->count--; 
	}
}
bool ucGenericFifo_isEmpty(ucGenericFifo_t *pFifo) {
	return (pFifo->count == 0);
}
bool ucGenericFifo_isFull(ucGenericFifo_t *pFifo) {
	return (pFifo->count == pFifo->elemCapacity); 
}	
uint16_t ucGenericFifo_Cnt(ucGenericFifo_t *pFifo) {
	return pFifo->count; 
}