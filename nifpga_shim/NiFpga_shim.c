#include <stdio.h>

#include "NiFpga.h"

NiFpga_Status NiFpga_Initialize() {
	printf("NiFpga_Initialize");
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_Finalize() {
	printf("NiFpga_Finalize");
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_Open(const char * bitfile, const char * signature, const char * resource, uint32_t attribute, NiFpga_Session * session) {
	printf("NiFpga_Open");
	printf("\tbitfile = %p", bitfile);
	printf("\tsignature = %p", signature);
	printf("\tresource = %p", resource);
	printf("\tattribute = %d", attribute);
	printf("\tsession = %p", session);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_Close(NiFpga_Session session, uint32_t attribute) {
	printf("NiFpga_Close");
	printf("\tsession = %d", session);
	printf("\tattribute = %d", attribute);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_Run(NiFpga_Session session, uint32_t attribute) {
	printf("NiFpga_Run");
	printf("\tsession = %d", session);
	printf("\tattribute = %d", attribute);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_Abort(NiFpga_Session session) {
	printf("NiFpga_Abort");
	printf("\tsession = %d", session);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_Reset(NiFpga_Session session) {
	printf("NiFpga_Reset");
	printf("\tsession = %d", session);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_Download(NiFpga_Session session) {
	printf("NiFpga_Download");
	printf("\tsession = %d", session);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadBool(NiFpga_Session session, uint32_t indicator, NiFpga_Bool * value) {
	printf("NiFpga_ReadBool");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadI8(NiFpga_Session session, uint32_t indicator, int8_t * value) {
	printf("NiFpga_ReadI8");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadU8(NiFpga_Session session, uint32_t indicator, uint8_t * value) {
	printf("NiFpga_ReadU8");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadI16(NiFpga_Session session, uint32_t indicator, int16_t * value) {
	printf("NiFpga_ReadI16");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadU16(NiFpga_Session session, uint32_t indicator, uint16_t * value) {
	printf("NiFpga_ReadU16");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadI32(NiFpga_Session session, uint32_t indicator, int32_t * value) {
	printf("NiFpga_ReadI32");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadU32(NiFpga_Session session, uint32_t indicator, uint32_t * value) {
	printf("NiFpga_ReadU32");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadI64(NiFpga_Session session, uint32_t indicator, int64_t * value) {
	printf("NiFpga_ReadI64");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadU64(NiFpga_Session session, uint32_t indicator, uint64_t * value) {
	printf("NiFpga_ReadU64");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadSgl(NiFpga_Session session, uint32_t indicator, float * value) {
	printf("NiFpga_ReadSgl");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadDbl(NiFpga_Session session, uint32_t indicator, double * value) {
	printf("NiFpga_ReadDbl");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tvalue = %p", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteBool(NiFpga_Session session, uint32_t control, NiFpga_Bool value) {
	printf("NiFpga_WriteBool");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteI8(NiFpga_Session session, uint32_t control, int8_t value) {
	printf("NiFpga_WriteI8");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteU8(NiFpga_Session session, uint32_t control, uint8_t value) {
	printf("NiFpga_WriteU8");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteI16(NiFpga_Session session, uint32_t control, int16_t value) {
	printf("NiFpga_WriteI16");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteU16(NiFpga_Session session, uint32_t control, uint16_t value) {
	printf("NiFpga_WriteU16");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteI32(NiFpga_Session session, uint32_t control, int32_t value) {
	printf("NiFpga_WriteI32");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteU32(NiFpga_Session session, uint32_t control, uint32_t value) {
	printf("NiFpga_WriteU32");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteI64(NiFpga_Session session, uint32_t control, int64_t value) {
	printf("NiFpga_WriteI64");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteU64(NiFpga_Session session, uint32_t control, uint64_t value) {
	printf("NiFpga_WriteU64");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %d", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteSgl(NiFpga_Session session, uint32_t control, float value) {
	printf("NiFpga_WriteSgl");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %f", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteDbl(NiFpga_Session session, uint32_t control, double value) {
	printf("NiFpga_WriteDbl");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tvalue = %f", value);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayBool(NiFpga_Session session, uint32_t indicator, NiFpga_Bool * array, size_t size) {
	printf("NiFpga_ReadArrayBool");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayI8(NiFpga_Session session, uint32_t indicator, int8_t * array, size_t size) {
	printf("NiFpga_ReadArrayI8");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayU8(NiFpga_Session session, uint32_t indicator, uint8_t * array, size_t size) {
	printf("NiFpga_ReadArrayU8");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayI16(NiFpga_Session session, uint32_t indicator, int16_t * array, size_t size) {
	printf("NiFpga_ReadArrayI16");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayU16(NiFpga_Session session, uint32_t indicator, uint16_t * array, size_t size) {
	printf("NiFpga_ReadArrayU16");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayI32(NiFpga_Session session, uint32_t indicator, int32_t * array, size_t size) {
	printf("NiFpga_ReadArrayI32");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayU32(NiFpga_Session session, uint32_t indicator, uint32_t * array, size_t size) {
	printf("NiFpga_ReadArrayU32");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayI64(NiFpga_Session session, uint32_t indicator, int64_t * array, size_t size) {
	printf("NiFpga_ReadArrayI64");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayU64(NiFpga_Session session, uint32_t indicator, uint64_t * array, size_t size) {
	printf("NiFpga_ReadArrayU64");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArraySgl(NiFpga_Session session, uint32_t indicator, float * array, size_t size) {
	printf("NiFpga_ReadArraySgl");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadArrayDbl(NiFpga_Session session, uint32_t indicator, double * array, size_t size) {
	printf("NiFpga_ReadArrayDbl");
	printf("\tsession = %d", session);
	printf("\tindicator = %d", indicator);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayBool(NiFpga_Session session, uint32_t control, const NiFpga_Bool * array, size_t size) {
	printf("NiFpga_WriteArrayBool");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayI8(NiFpga_Session session, uint32_t control, const int8_t * array, size_t size) {
	printf("NiFpga_WriteArrayI8");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayU8(NiFpga_Session session, uint32_t control, const uint8_t * array, size_t size) {
	printf("NiFpga_WriteArrayU8");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayI16(NiFpga_Session session, uint32_t control, const int16_t * array, size_t size) {
	printf("NiFpga_WriteArrayI16");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayU16(NiFpga_Session session, uint32_t control, const uint16_t * array, size_t size) {
	printf("NiFpga_WriteArrayU16");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayI32(NiFpga_Session session, uint32_t control, const int32_t * array, size_t size) {
	printf("NiFpga_WriteArrayI32");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayU32(NiFpga_Session session, uint32_t control, const uint32_t * array, size_t size) {
	printf("NiFpga_WriteArrayU32");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayI64(NiFpga_Session session, uint32_t control, const int64_t * array, size_t size) {
	printf("NiFpga_WriteArrayI64");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayU64(NiFpga_Session session, uint32_t control, const uint64_t * array, size_t size) {
	printf("NiFpga_WriteArrayU64");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArraySgl(NiFpga_Session session, uint32_t control, const float * array, size_t size) {
	printf("NiFpga_WriteArraySgl");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteArrayDbl(NiFpga_Session session, uint32_t control, const double * array, size_t size) {
	printf("NiFpga_WriteArrayDbl");
	printf("\tsession = %d", session);
	printf("\tcontrol = %d", control);
	printf("\tarray = %p", array);
	printf("\tsize = %d", size);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReserveIrqContext(NiFpga_Session session, NiFpga_IrqContext * context) {
	printf("NiFpga_ReserveIrqContext");
	printf("\tsession = %d", session);
	printf("\tcontext = %p", context);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_UnreserveIrqContext(NiFpga_Session session, NiFpga_IrqContext context) {
	printf("NiFpga_UnreserveIrqContext");
	printf("\tsession = %d", session);
	printf("\tcontext = %d", context);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WaitOnIrqs(NiFpga_Session session, NiFpga_IrqContext context, uint32_t irqs, uint32_t timeout, uint32_t * irqsAsserted, NiFpga_Bool * timedOut) {
	printf("NiFpga_WaitOnIrqs");
	printf("\tsession = %d", session);
	printf("\tcontext = %d", context);
	printf("\tirqs = %d", irqs);
	printf("\ttimeout = %d", timeout);
	printf("\tirqsAsserted = %p", irqsAsserted);
	printf("\ttimedOut = %p", timedOut);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcknowledgeIrqs(NiFpga_Session session, uint32_t irqs) {
	printf("NiFpga_AcknowledgeIrqs");
	printf("\tsession = %d", session);
	printf("\tirqs = %d", irqs);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ConfigureFifo(NiFpga_Session session, uint32_t fifo, size_t depth) {
	printf("NiFpga_ConfigureFifo");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdepth = %d", depth);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ConfigureFifo2(NiFpga_Session session, uint32_t fifo, size_t requestedDepth, size_t * actualDepth) {
	printf("NiFpga_ConfigureFifo2");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\trequestedDepth = %d", requestedDepth);
	printf("\tactualDepth = %p", actualDepth);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_StartFifo(NiFpga_Session session, uint32_t fifo) {
	printf("NiFpga_StartFifo");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_StopFifo(NiFpga_Session session, uint32_t fifo) {
	printf("NiFpga_StopFifo");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoBool");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoI8(NiFpga_Session session, uint32_t fifo, int8_t * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoI8");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoU8(NiFpga_Session session, uint32_t fifo, uint8_t * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoU8");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoI16(NiFpga_Session session, uint32_t fifo, int16_t * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoI16");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoU16(NiFpga_Session session, uint32_t fifo, uint16_t * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoU16");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoI32(NiFpga_Session session, uint32_t fifo, int32_t * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoI32");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoU32(NiFpga_Session session, uint32_t fifo, uint32_t * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoU32");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoI64(NiFpga_Session session, uint32_t fifo, int64_t * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoI64");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoU64(NiFpga_Session session, uint32_t fifo, uint64_t * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoU64");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoSgl(NiFpga_Session session, uint32_t fifo, float * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoSgl");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReadFifoDbl(NiFpga_Session session, uint32_t fifo, double * data, size_t numberOfElements, uint32_t timeout, size_t * elementsRemaining) {
	printf("NiFpga_ReadFifoDbl");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoBool(NiFpga_Session session, uint32_t fifo, const NiFpga_Bool * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoBool");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoI8(NiFpga_Session session, uint32_t fifo, const int8_t * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoI8");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoU8(NiFpga_Session session, uint32_t fifo, const uint8_t * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoU8");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoI16(NiFpga_Session session, uint32_t fifo, const int16_t * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoI16");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoU16(NiFpga_Session session, uint32_t fifo, const uint16_t * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoU16");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoI32(NiFpga_Session session, uint32_t fifo, const int32_t * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoI32");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoU32(NiFpga_Session session, uint32_t fifo, const uint32_t * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoU32");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoI64(NiFpga_Session session, uint32_t fifo, const int64_t * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoI64");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoU64(NiFpga_Session session, uint32_t fifo, const uint64_t * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoU64");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoSgl(NiFpga_Session session, uint32_t fifo, const float * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoSgl");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_WriteFifoDbl(NiFpga_Session session, uint32_t fifo, const double * data, size_t numberOfElements, uint32_t timeout, size_t * emptyElementsRemaining) {
	printf("NiFpga_WriteFifoDbl");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tdata = %p", data);
	printf("\tnumberOfElements = %d", numberOfElements);
	printf("\ttimeout = %d", timeout);
	printf("\temptyElementsRemaining = %p", emptyElementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsBool");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsI8(NiFpga_Session session, uint32_t fifo, int8_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsI8");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsU8(NiFpga_Session session, uint32_t fifo, uint8_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsU8");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsI16(NiFpga_Session session, uint32_t fifo, int16_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsI16");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsU16(NiFpga_Session session, uint32_t fifo, uint16_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsU16");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsI32(NiFpga_Session session, uint32_t fifo, int32_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsI32");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsU32(NiFpga_Session session, uint32_t fifo, uint32_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsU32");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsI64(NiFpga_Session session, uint32_t fifo, int64_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsI64");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsU64(NiFpga_Session session, uint32_t fifo, uint64_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsU64");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsSgl(NiFpga_Session session, uint32_t fifo, float ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsSgl");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoReadElementsDbl(NiFpga_Session session, uint32_t fifo, double ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoReadElementsDbl");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsBool");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsI8(NiFpga_Session session, uint32_t fifo, int8_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsI8");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsU8(NiFpga_Session session, uint32_t fifo, uint8_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsU8");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsI16(NiFpga_Session session, uint32_t fifo, int16_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsI16");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsU16(NiFpga_Session session, uint32_t fifo, uint16_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsU16");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsI32(NiFpga_Session session, uint32_t fifo, int32_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsI32");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsU32(NiFpga_Session session, uint32_t fifo, uint32_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsU32");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsI64(NiFpga_Session session, uint32_t fifo, int64_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsI64");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsU64(NiFpga_Session session, uint32_t fifo, uint64_t ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsU64");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsSgl(NiFpga_Session session, uint32_t fifo, float ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsSgl");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_AcquireFifoWriteElementsDbl(NiFpga_Session session, uint32_t fifo, double ** elements, size_t elementsRequested, uint32_t timeout, size_t * elementsAcquired, size_t * elementsRemaining) {
	printf("NiFpga_AcquireFifoWriteElementsDbl");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %p", elements);
	printf("\telementsRequested = %d", elementsRequested);
	printf("\ttimeout = %d", timeout);
	printf("\telementsAcquired = %p", elementsAcquired);
	printf("\telementsRemaining = %p", elementsRemaining);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_ReleaseFifoElements(NiFpga_Session session, uint32_t fifo, size_t elements) {
	printf("NiFpga_ReleaseFifoElements");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\telements = %d", elements);
	return NiFpga_Status_Success;
}

NiFpga_Status NiFpga_GetPeerToPeerFifoEndpoint(NiFpga_Session session, uint32_t fifo, uint32_t * endpoint) {
	printf("NiFpga_GetPeerToPeerFifoEndpoint");
	printf("\tsession = %d", session);
	printf("\tfifo = %d", fifo);
	printf("\tendpoint = %p", endpoint);
	return NiFpga_Status_Success;
}

