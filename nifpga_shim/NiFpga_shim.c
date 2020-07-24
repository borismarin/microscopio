#include "NiFpga.h"
#include <stdio.h>

NiFpga_Bool NiFpgaDll_IsError(const NiFpga_Status status) {
	printf("NiFpga_IsError\n");
	printf("\tstatus = %d\n", status);
	return NiFpga_Status_Success;
}

NiFpga_Bool NiFpgaDll_IsNotError(const NiFpga_Status status) {
	printf("NiFpga_IsNotError\n");
	printf("\tstatus = %d\n", status);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_MergeStatus(NiFpga_Status *const status, const NiFpga_Status newStatus) {
	printf("NiFpga_MergeStatus\n");
	printf("\tstatus = %p\n", status);
	printf("\tnewStatus = %d\n", newStatus);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_Initialize() {
	printf("NiFpga_Initialize\n");
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_Finalize() {
	printf("NiFpga_Finalize\n");
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_Open(const char * bitfile, const char * signature, const char * resource, uint32_t attribute, NiFpga_Session * session) {
	printf("NiFpga_Open\n");
	printf("\tbitfile = %p\n", bitfile);
	printf("\tsignature = %p\n", signature);
	printf("\tresource = %p\n", resource);
	printf("\tattribute = %d\n", attribute);
	printf("\tsession = %p\n", session);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_Close(NiFpga_Session session, uint32_t attribute) {
	printf("NiFpga_Close\n");
	printf("\tsession = %d\n", session);
	printf("\tattribute = %d\n", attribute);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_Run(NiFpga_Session session, uint32_t attribute) {
	printf("NiFpga_Run\n");
	printf("\tsession = %d\n", session);
	printf("\tattribute = %d\n", attribute);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_Abort(NiFpga_Session session) {
	printf("NiFpga_Abort\n");
	printf("\tsession = %d\n", session);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_Reset(NiFpga_Session session) {
	printf("NiFpga_Reset\n");
	printf("\tsession = %d\n", session);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_Download(NiFpga_Session session) {
	printf("NiFpga_Download\n");
	printf("\tsession = %d\n", session);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadBool(NiFpga_Session session, uint32_t indicator, NiFpga_Bool * value) {
	printf("NiFpga_ReadBool\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadI8(NiFpga_Session session, uint32_t indicator, int8_t * value) {
	printf("NiFpga_ReadI8\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadU8(NiFpga_Session session, uint32_t indicator, uint8_t * value) {
	printf("NiFpga_ReadU8\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadI16(NiFpga_Session session, uint32_t indicator, int16_t * value) {
	printf("NiFpga_ReadI16\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadU16(NiFpga_Session session, uint32_t indicator, uint16_t * value) {
	printf("NiFpga_ReadU16\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadI32(NiFpga_Session session, uint32_t indicator, int32_t * value) {
	printf("NiFpga_ReadI32\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadU32(NiFpga_Session session, uint32_t indicator, uint32_t * value) {
	printf("NiFpga_ReadU32\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadI64(NiFpga_Session session, uint32_t indicator, int64_t * value) {
	printf("NiFpga_ReadI64\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadU64(NiFpga_Session session, uint32_t indicator, uint64_t * value) {
	printf("NiFpga_ReadU64\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadSgl(NiFpga_Session session, uint32_t indicator, float * value) {
	printf("NiFpga_ReadSgl\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadDbl(NiFpga_Session session, uint32_t indicator, double * value) {
	printf("NiFpga_ReadDbl\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tvalue = %p\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteBool(NiFpga_Session session, uint32_t control, NiFpga_Bool value) {
	printf("NiFpga_WriteBool\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteI8(NiFpga_Session session, uint32_t control, int8_t value) {
	printf("NiFpga_WriteI8\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteU8(NiFpga_Session session, uint32_t control, uint8_t value) {
	printf("NiFpga_WriteU8\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteI16(NiFpga_Session session, uint32_t control, int16_t value) {
	printf("NiFpga_WriteI16\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteU16(NiFpga_Session session, uint32_t control, uint16_t value) {
	printf("NiFpga_WriteU16\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteI32(NiFpga_Session session, uint32_t control, int32_t value) {
	printf("NiFpga_WriteI32\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteU32(NiFpga_Session session, uint32_t control, uint32_t value) {
	printf("NiFpga_WriteU32\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteI64(NiFpga_Session session, uint32_t control, int64_t value) {
	printf("NiFpga_WriteI64\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteU64(NiFpga_Session session, uint32_t control, uint64_t value) {
	printf("NiFpga_WriteU64\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %d\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteSgl(NiFpga_Session session, uint32_t control, float value) {
	printf("NiFpga_WriteSgl\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %f\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteDbl(NiFpga_Session session, uint32_t control, double value) {
	printf("NiFpga_WriteDbl\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tvalue = %f\n", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayBool(NiFpga_Session session, uint32_t indicator, NiFpga_Bool * array, int size) {
	printf("NiFpga_ReadArrayBool\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayI8(NiFpga_Session session, uint32_t indicator, int8_t * array, int size) {
	printf("NiFpga_ReadArrayI8\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayU8(NiFpga_Session session, uint32_t indicator, uint8_t * array, int size) {
	printf("NiFpga_ReadArrayU8\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayI16(NiFpga_Session session, uint32_t indicator, int16_t * array, int size) {
	printf("NiFpga_ReadArrayI16\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayU16(NiFpga_Session session, uint32_t indicator, uint16_t * array, int size) {
	printf("NiFpga_ReadArrayU16\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayI32(NiFpga_Session session, uint32_t indicator, int32_t * array, int size) {
	printf("NiFpga_ReadArrayI32\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayU32(NiFpga_Session session, uint32_t indicator, uint32_t * array, int size) {
	printf("NiFpga_ReadArrayU32\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayI64(NiFpga_Session session, uint32_t indicator, int64_t * array, int size) {
	printf("NiFpga_ReadArrayI64\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayU64(NiFpga_Session session, uint32_t indicator, uint64_t * array, int size) {
	printf("NiFpga_ReadArrayU64\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArraySgl(NiFpga_Session session, uint32_t indicator, float * array, int size) {
	printf("NiFpga_ReadArraySgl\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadArrayDbl(NiFpga_Session session, uint32_t indicator, double * array, int size) {
	printf("NiFpga_ReadArrayDbl\n");
	printf("\tsession = %d\n", session);
	printf("\tindicator = %d\n", indicator);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayBool(NiFpga_Session session, uint32_t control, const NiFpga_Bool * array, int size) {
	printf("NiFpga_WriteArrayBool\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayI8(NiFpga_Session session, uint32_t control, const int8_t * array, int size) {
	printf("NiFpga_WriteArrayI8\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayU8(NiFpga_Session session, uint32_t control, const uint8_t * array, int size) {
	printf("NiFpga_WriteArrayU8\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayI16(NiFpga_Session session, uint32_t control, const int16_t * array, int size) {
	printf("NiFpga_WriteArrayI16\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayU16(NiFpga_Session session, uint32_t control, const uint16_t * array, int size) {
	printf("NiFpga_WriteArrayU16\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayI32(NiFpga_Session session, uint32_t control, const int32_t * array, int size) {
	printf("NiFpga_WriteArrayI32\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayU32(NiFpga_Session session, uint32_t control, const uint32_t * array, int size) {
	printf("NiFpga_WriteArrayU32\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayI64(NiFpga_Session session, uint32_t control, const int64_t * array, int size) {
	printf("NiFpga_WriteArrayI64\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayU64(NiFpga_Session session, uint32_t control, const uint64_t * array, int size) {
	printf("NiFpga_WriteArrayU64\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArraySgl(NiFpga_Session session, uint32_t control, const float * array, int size) {
	printf("NiFpga_WriteArraySgl\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteArrayDbl(NiFpga_Session session, uint32_t control, const double * array, int size) {
	printf("NiFpga_WriteArrayDbl\n");
	printf("\tsession = %d\n", session);
	printf("\tcontrol = %d\n", control);
	printf("\tarray = %p\n", array);
	printf("\tsize = %d\n", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReserveIrqContext(NiFpga_Session session, NiFpga_IrqContext * context) {
	printf("NiFpga_ReserveIrqContext\n");
	printf("\tsession = %d\n", session);
	printf("\tcontext = %p\n", context);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_UnreserveIrqContext(NiFpga_Session session, NiFpga_IrqContext context) {
	printf("NiFpga_UnreserveIrqContext\n");
	printf("\tsession = %d\n", session);
	printf("\tcontext = %d\n", context);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WaitOnIrqs(NiFpga_Session session, NiFpga_IrqContext context, uint32_t irqs, uint32_t timeout, uint32_t * irqsAsserted, NiFpga_Bool * timedOut) {
	printf("NiFpga_WaitOnIrqs\n");
	printf("\tsession = %d\n", session);
	printf("\tcontext = %d\n", context);
	printf("\tirqs = %d\n", irqs);
	printf("\ttimeout = %d\n", timeout);
	printf("\tirqsAsserted = %p\n", irqsAsserted);
	printf("\ttimedOut = %p\n", timedOut);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcknowledgeIrqs(NiFpga_Session session, uint32_t irqs) {
	printf("NiFpga_AcknowledgeIrqs\n");
	printf("\tsession = %d\n", session);
	printf("\tirqs = %d\n", irqs);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ConfigureFifo(NiFpga_Session session, uint32_t fifo, int depth) {
	printf("NiFpga_ConfigureFifo\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdepth = %d\n", depth);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ConfigureFifo2(NiFpga_Session session, uint32_t fifo, int requestedDepth, int * actualDepth) {
	printf("NiFpga_ConfigureFifo2\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\trequestedDepth = %d\n", requestedDepth);
	printf("\tactualDepth = %p\n", actualDepth);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_StartFifo(NiFpga_Session session, uint32_t fifo) {
	printf("NiFpga_StartFifo\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_StopFifo(NiFpga_Session session, uint32_t fifo) {
	printf("NiFpga_StopFifo\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoBool\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoI8(NiFpga_Session session, uint32_t fifo, int8_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoI8\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoU8(NiFpga_Session session, uint32_t fifo, uint8_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoU8\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoI16(NiFpga_Session session, uint32_t fifo, int16_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoI16\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoU16(NiFpga_Session session, uint32_t fifo, uint16_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoU16\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoI32(NiFpga_Session session, uint32_t fifo, int32_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoI32\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoU32(NiFpga_Session session, uint32_t fifo, uint32_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoU32\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoI64(NiFpga_Session session, uint32_t fifo, int64_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoI64\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoU64(NiFpga_Session session, uint32_t fifo, uint64_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoU64\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoSgl(NiFpga_Session session, uint32_t fifo, float * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoSgl\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReadFifoDbl(NiFpga_Session session, uint32_t fifo, double * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	printf("NiFpga_ReadFifoDbl\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoBool(NiFpga_Session session, uint32_t fifo, const NiFpga_Bool * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoBool\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoI8(NiFpga_Session session, uint32_t fifo, const int8_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoI8\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoU8(NiFpga_Session session, uint32_t fifo, const uint8_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoU8\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoI16(NiFpga_Session session, uint32_t fifo, const int16_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoI16\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoU16(NiFpga_Session session, uint32_t fifo, const uint16_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoU16\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoI32(NiFpga_Session session, uint32_t fifo, const int32_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoI32\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoU32(NiFpga_Session session, uint32_t fifo, const uint32_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoU32\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoI64(NiFpga_Session session, uint32_t fifo, const int64_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoI64\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoU64(NiFpga_Session session, uint32_t fifo, const uint64_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoU64\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoSgl(NiFpga_Session session, uint32_t fifo, const float * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoSgl\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_WriteFifoDbl(NiFpga_Session session, uint32_t fifo, const double * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoDbl\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tdata = %p\n", data);
	printf("\tnumberOfElements = %d\n", numberOfElements);
	printf("\ttimeout = %d\n", timeout);
	printf("\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsBool\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsI8(NiFpga_Session session, uint32_t fifo, int8_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsI8\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsU8(NiFpga_Session session, uint32_t fifo, uint8_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsU8\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsI16(NiFpga_Session session, uint32_t fifo, int16_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsI16\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsU16(NiFpga_Session session, uint32_t fifo, uint16_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsU16\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsI32(NiFpga_Session session, uint32_t fifo, int32_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsI32\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsU32(NiFpga_Session session, uint32_t fifo, uint32_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsU32\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsI64(NiFpga_Session session, uint32_t fifo, int64_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsI64\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsU64(NiFpga_Session session, uint32_t fifo, uint64_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsU64\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsSgl(NiFpga_Session session, uint32_t fifo, float ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsSgl\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoReadElementsDbl(NiFpga_Session session, uint32_t fifo, double ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsDbl\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsBool\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsI8(NiFpga_Session session, uint32_t fifo, int8_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsI8\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsU8(NiFpga_Session session, uint32_t fifo, uint8_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsU8\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsI16(NiFpga_Session session, uint32_t fifo, int16_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsI16\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsU16(NiFpga_Session session, uint32_t fifo, uint16_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsU16\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsI32(NiFpga_Session session, uint32_t fifo, int32_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsI32\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsU32(NiFpga_Session session, uint32_t fifo, uint32_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsU32\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsI64(NiFpga_Session session, uint32_t fifo, int64_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsI64\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsU64(NiFpga_Session session, uint32_t fifo, uint64_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsU64\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsSgl(NiFpga_Session session, uint32_t fifo, float ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsSgl\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsDbl(NiFpga_Session session, uint32_t fifo, double ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsDbl\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %p\n", elements);
	printf("\telementsRequested = %d\n", elementsRequested);
	printf("\ttimeout = %d\n", timeout);
	printf("\telementsAcquired = %p\n", elementsAcquired);
	printf("\telementsRemaining = %p\n", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ReleaseFifoElements(NiFpga_Session session, uint32_t fifo, int elements) {
	printf("NiFpga_ReleaseFifoElements\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\telements = %d\n", elements);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_GetPeerToPeerFifoEndpoint(NiFpga_Session session, uint32_t fifo, uint32_t * endpoint) {
	printf("NiFpga_GetPeerToPeerFifoEndpoint\n");
	printf("\tsession = %d\n", session);
	printf("\tfifo = %d\n", fifo);
	printf("\tendpoint = %p\n", endpoint);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_GetBitfileContents() {
    return NiFpga_Status_Success;
}

NiFpga_Status NiFpgaDll_ClientFunctionCall() {
    return NiFpga_Status_Success;
}
