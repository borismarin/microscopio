
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <dlfcn.h>
#endif
#include "NiFpga.h"

static FILE *outfile;
static int initialized = 0;

#ifdef _WIN32
static HMODULE handle;
#else
static void *handle;
#endif

static void _proxy_load_fns();

static void _proxy_init() {
    char* tmp = getenv("TEMP");
    size_t tmp_len = strlen(tmp);
    char outfile_path[tmp_len + 25];
    sprintf(outfile_path, "%s/NiFpga_Proxy.log", tmp);

    outfile = fopen(outfile_path, "a");
    fprintf(outfile, "===== LOADING PROXY =====\n");

#ifdef _WIN32
    handle = LoadLibraryA("NiFpga.real.dll");
#else
    handle = dlopen("libNiFpga.real.so", RTLD_LAZY);
#endif

    _proxy_load_fns();
}

static void _proxy_deinit() {
    fclose(outfile);
#ifdef WIN32
    FreeLibrary(handle);
#else
    dlclose(handle);
#endif
}

typedef NiFpga_Bool (*_real_NiFpga_IsError_t)(const NiFpga_Status);
typedef NiFpga_Bool (*_real_NiFpga_IsNotError_t)(const NiFpga_Status);
typedef NiFpga_Status (*_real_NiFpga_MergeStatus_t)(NiFpga_Status *const, const NiFpga_Status);
typedef NiFpga_Status (*_real_NiFpga_Initialize_t)(void);
typedef NiFpga_Status (*_real_NiFpga_Finalize_t)(void);
typedef NiFpga_Status (*_real_NiFpga_Open_t)(const char *, const char *, const char *, uint32_t, NiFpga_Session *);
typedef NiFpga_Status (*_real_NiFpga_Close_t)(NiFpga_Session, uint32_t);
typedef NiFpga_Status (*_real_NiFpga_Run_t)(NiFpga_Session, uint32_t);
typedef NiFpga_Status (*_real_NiFpga_Abort_t)(NiFpga_Session);
typedef NiFpga_Status (*_real_NiFpga_Reset_t)(NiFpga_Session);
typedef NiFpga_Status (*_real_NiFpga_Download_t)(NiFpga_Session);
typedef NiFpga_Status (*_real_NiFpga_ReadBool_t)(NiFpga_Session, uint32_t, NiFpga_Bool *);
typedef NiFpga_Status (*_real_NiFpga_ReadI8_t)(NiFpga_Session, uint32_t, int8_t *);
typedef NiFpga_Status (*_real_NiFpga_ReadU8_t)(NiFpga_Session, uint32_t, uint8_t *);
typedef NiFpga_Status (*_real_NiFpga_ReadI16_t)(NiFpga_Session, uint32_t, int16_t *);
typedef NiFpga_Status (*_real_NiFpga_ReadU16_t)(NiFpga_Session, uint32_t, uint16_t *);
typedef NiFpga_Status (*_real_NiFpga_ReadI32_t)(NiFpga_Session, uint32_t, int32_t *);
typedef NiFpga_Status (*_real_NiFpga_ReadU32_t)(NiFpga_Session, uint32_t, uint32_t *);
typedef NiFpga_Status (*_real_NiFpga_ReadI64_t)(NiFpga_Session, uint32_t, int64_t *);
typedef NiFpga_Status (*_real_NiFpga_ReadU64_t)(NiFpga_Session, uint32_t, uint64_t *);
typedef NiFpga_Status (*_real_NiFpga_ReadSgl_t)(NiFpga_Session, uint32_t, float *);
typedef NiFpga_Status (*_real_NiFpga_ReadDbl_t)(NiFpga_Session, uint32_t, double *);
typedef NiFpga_Status (*_real_NiFpga_WriteBool_t)(NiFpga_Session, uint32_t, NiFpga_Bool);
typedef NiFpga_Status (*_real_NiFpga_WriteI8_t)(NiFpga_Session, uint32_t, int8_t);
typedef NiFpga_Status (*_real_NiFpga_WriteU8_t)(NiFpga_Session, uint32_t, uint8_t);
typedef NiFpga_Status (*_real_NiFpga_WriteI16_t)(NiFpga_Session, uint32_t, int16_t);
typedef NiFpga_Status (*_real_NiFpga_WriteU16_t)(NiFpga_Session, uint32_t, uint16_t);
typedef NiFpga_Status (*_real_NiFpga_WriteI32_t)(NiFpga_Session, uint32_t, int32_t);
typedef NiFpga_Status (*_real_NiFpga_WriteU32_t)(NiFpga_Session, uint32_t, uint32_t);
typedef NiFpga_Status (*_real_NiFpga_WriteI64_t)(NiFpga_Session, uint32_t, int64_t);
typedef NiFpga_Status (*_real_NiFpga_WriteU64_t)(NiFpga_Session, uint32_t, uint64_t);
typedef NiFpga_Status (*_real_NiFpga_WriteSgl_t)(NiFpga_Session, uint32_t, float);
typedef NiFpga_Status (*_real_NiFpga_WriteDbl_t)(NiFpga_Session, uint32_t, double);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayBool_t)(NiFpga_Session, uint32_t, NiFpga_Bool *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayI8_t)(NiFpga_Session, uint32_t, int8_t *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayU8_t)(NiFpga_Session, uint32_t, uint8_t *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayI16_t)(NiFpga_Session, uint32_t, int16_t *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayU16_t)(NiFpga_Session, uint32_t, uint16_t *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayI32_t)(NiFpga_Session, uint32_t, int32_t *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayU32_t)(NiFpga_Session, uint32_t, uint32_t *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayI64_t)(NiFpga_Session, uint32_t, int64_t *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayU64_t)(NiFpga_Session, uint32_t, uint64_t *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArraySgl_t)(NiFpga_Session, uint32_t, float *, int);
typedef NiFpga_Status (*_real_NiFpga_ReadArrayDbl_t)(NiFpga_Session, uint32_t, double *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayBool_t)(NiFpga_Session, uint32_t, const NiFpga_Bool *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayI8_t)(NiFpga_Session, uint32_t, const int8_t *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayU8_t)(NiFpga_Session, uint32_t, const uint8_t *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayI16_t)(NiFpga_Session, uint32_t, const int16_t *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayU16_t)(NiFpga_Session, uint32_t, const uint16_t *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayI32_t)(NiFpga_Session, uint32_t, const int32_t *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayU32_t)(NiFpga_Session, uint32_t, const uint32_t *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayI64_t)(NiFpga_Session, uint32_t, const int64_t *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayU64_t)(NiFpga_Session, uint32_t, const uint64_t *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArraySgl_t)(NiFpga_Session, uint32_t, const float *, int);
typedef NiFpga_Status (*_real_NiFpga_WriteArrayDbl_t)(NiFpga_Session, uint32_t, const double *, int);
typedef NiFpga_Status (*_real_NiFpga_ReserveIrqContext_t)(NiFpga_Session, NiFpga_IrqContext *);
typedef NiFpga_Status (*_real_NiFpga_UnreserveIrqContext_t)(NiFpga_Session, NiFpga_IrqContext);
typedef NiFpga_Status (*_real_NiFpga_WaitOnIrqs_t)(NiFpga_Session, NiFpga_IrqContext, uint32_t, uint32_t, uint32_t *, NiFpga_Bool *);
typedef NiFpga_Status (*_real_NiFpga_AcknowledgeIrqs_t)(NiFpga_Session, uint32_t);
typedef NiFpga_Status (*_real_NiFpga_ConfigureFifo_t)(NiFpga_Session, uint32_t, int);
typedef NiFpga_Status (*_real_NiFpga_ConfigureFifo2_t)(NiFpga_Session, uint32_t, int, int *);
typedef NiFpga_Status (*_real_NiFpga_StartFifo_t)(NiFpga_Session, uint32_t);
typedef NiFpga_Status (*_real_NiFpga_StopFifo_t)(NiFpga_Session, uint32_t);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoBool_t)(NiFpga_Session, uint32_t, NiFpga_Bool *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoI8_t)(NiFpga_Session, uint32_t, int8_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoU8_t)(NiFpga_Session, uint32_t, uint8_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoI16_t)(NiFpga_Session, uint32_t, int16_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoU16_t)(NiFpga_Session, uint32_t, uint16_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoI32_t)(NiFpga_Session, uint32_t, int32_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoU32_t)(NiFpga_Session, uint32_t, uint32_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoI64_t)(NiFpga_Session, uint32_t, int64_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoU64_t)(NiFpga_Session, uint32_t, uint64_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoSgl_t)(NiFpga_Session, uint32_t, float *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_ReadFifoDbl_t)(NiFpga_Session, uint32_t, double *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoBool_t)(NiFpga_Session, uint32_t, const NiFpga_Bool *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoI8_t)(NiFpga_Session, uint32_t, const int8_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoU8_t)(NiFpga_Session, uint32_t, const uint8_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoI16_t)(NiFpga_Session, uint32_t, const int16_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoU16_t)(NiFpga_Session, uint32_t, const uint16_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoI32_t)(NiFpga_Session, uint32_t, const int32_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoU32_t)(NiFpga_Session, uint32_t, const uint32_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoI64_t)(NiFpga_Session, uint32_t, const int64_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoU64_t)(NiFpga_Session, uint32_t, const uint64_t *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoSgl_t)(NiFpga_Session, uint32_t, const float *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_WriteFifoDbl_t)(NiFpga_Session, uint32_t, const double *, int, uint32_t, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsBool_t)(NiFpga_Session, uint32_t, NiFpga_Bool **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsI8_t)(NiFpga_Session, uint32_t, int8_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsU8_t)(NiFpga_Session, uint32_t, uint8_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsI16_t)(NiFpga_Session, uint32_t, int16_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsU16_t)(NiFpga_Session, uint32_t, uint16_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsI32_t)(NiFpga_Session, uint32_t, int32_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsU32_t)(NiFpga_Session, uint32_t, uint32_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsI64_t)(NiFpga_Session, uint32_t, int64_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsU64_t)(NiFpga_Session, uint32_t, uint64_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsSgl_t)(NiFpga_Session, uint32_t, float **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoReadElementsDbl_t)(NiFpga_Session, uint32_t, double **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsBool_t)(NiFpga_Session, uint32_t, NiFpga_Bool **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsI8_t)(NiFpga_Session, uint32_t, int8_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsU8_t)(NiFpga_Session, uint32_t, uint8_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsI16_t)(NiFpga_Session, uint32_t, int16_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsU16_t)(NiFpga_Session, uint32_t, uint16_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsI32_t)(NiFpga_Session, uint32_t, int32_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsU32_t)(NiFpga_Session, uint32_t, uint32_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsI64_t)(NiFpga_Session, uint32_t, int64_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsU64_t)(NiFpga_Session, uint32_t, uint64_t **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsSgl_t)(NiFpga_Session, uint32_t, float **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_AcquireFifoWriteElementsDbl_t)(NiFpga_Session, uint32_t, double **, int, uint32_t, int *, int *);
typedef NiFpga_Status (*_real_NiFpga_ReleaseFifoElements_t)(NiFpga_Session, uint32_t, int);
typedef NiFpga_Status (*_real_NiFpga_GetPeerToPeerFifoEndpoint_t)(NiFpga_Session, uint32_t, uint32_t *);
typedef NiFpga_Status (*_real_NiFpga_GetBitfileContents_t)(NiFpga_Session, const char **);
typedef NiFpga_Status (*_real_NiFpga_ClientFunctionCall_t)(NiFpga_Session, uint32_t, uint32_t, const void *, int, void *, int);

static _real_NiFpga_IsError_t _real_NiFpga_IsError = NULL;
static _real_NiFpga_IsNotError_t _real_NiFpga_IsNotError = NULL;
static _real_NiFpga_MergeStatus_t _real_NiFpga_MergeStatus = NULL;
static _real_NiFpga_Initialize_t _real_NiFpga_Initialize = NULL;
static _real_NiFpga_Finalize_t _real_NiFpga_Finalize = NULL;
static _real_NiFpga_Open_t _real_NiFpga_Open = NULL;
static _real_NiFpga_Close_t _real_NiFpga_Close = NULL;
static _real_NiFpga_Run_t _real_NiFpga_Run = NULL;
static _real_NiFpga_Abort_t _real_NiFpga_Abort = NULL;
static _real_NiFpga_Reset_t _real_NiFpga_Reset = NULL;
static _real_NiFpga_Download_t _real_NiFpga_Download = NULL;
static _real_NiFpga_ReadBool_t _real_NiFpga_ReadBool = NULL;
static _real_NiFpga_ReadI8_t _real_NiFpga_ReadI8 = NULL;
static _real_NiFpga_ReadU8_t _real_NiFpga_ReadU8 = NULL;
static _real_NiFpga_ReadI16_t _real_NiFpga_ReadI16 = NULL;
static _real_NiFpga_ReadU16_t _real_NiFpga_ReadU16 = NULL;
static _real_NiFpga_ReadI32_t _real_NiFpga_ReadI32 = NULL;
static _real_NiFpga_ReadU32_t _real_NiFpga_ReadU32 = NULL;
static _real_NiFpga_ReadI64_t _real_NiFpga_ReadI64 = NULL;
static _real_NiFpga_ReadU64_t _real_NiFpga_ReadU64 = NULL;
static _real_NiFpga_ReadSgl_t _real_NiFpga_ReadSgl = NULL;
static _real_NiFpga_ReadDbl_t _real_NiFpga_ReadDbl = NULL;
static _real_NiFpga_WriteBool_t _real_NiFpga_WriteBool = NULL;
static _real_NiFpga_WriteI8_t _real_NiFpga_WriteI8 = NULL;
static _real_NiFpga_WriteU8_t _real_NiFpga_WriteU8 = NULL;
static _real_NiFpga_WriteI16_t _real_NiFpga_WriteI16 = NULL;
static _real_NiFpga_WriteU16_t _real_NiFpga_WriteU16 = NULL;
static _real_NiFpga_WriteI32_t _real_NiFpga_WriteI32 = NULL;
static _real_NiFpga_WriteU32_t _real_NiFpga_WriteU32 = NULL;
static _real_NiFpga_WriteI64_t _real_NiFpga_WriteI64 = NULL;
static _real_NiFpga_WriteU64_t _real_NiFpga_WriteU64 = NULL;
static _real_NiFpga_WriteSgl_t _real_NiFpga_WriteSgl = NULL;
static _real_NiFpga_WriteDbl_t _real_NiFpga_WriteDbl = NULL;
static _real_NiFpga_ReadArrayBool_t _real_NiFpga_ReadArrayBool = NULL;
static _real_NiFpga_ReadArrayI8_t _real_NiFpga_ReadArrayI8 = NULL;
static _real_NiFpga_ReadArrayU8_t _real_NiFpga_ReadArrayU8 = NULL;
static _real_NiFpga_ReadArrayI16_t _real_NiFpga_ReadArrayI16 = NULL;
static _real_NiFpga_ReadArrayU16_t _real_NiFpga_ReadArrayU16 = NULL;
static _real_NiFpga_ReadArrayI32_t _real_NiFpga_ReadArrayI32 = NULL;
static _real_NiFpga_ReadArrayU32_t _real_NiFpga_ReadArrayU32 = NULL;
static _real_NiFpga_ReadArrayI64_t _real_NiFpga_ReadArrayI64 = NULL;
static _real_NiFpga_ReadArrayU64_t _real_NiFpga_ReadArrayU64 = NULL;
static _real_NiFpga_ReadArraySgl_t _real_NiFpga_ReadArraySgl = NULL;
static _real_NiFpga_ReadArrayDbl_t _real_NiFpga_ReadArrayDbl = NULL;
static _real_NiFpga_WriteArrayBool_t _real_NiFpga_WriteArrayBool = NULL;
static _real_NiFpga_WriteArrayI8_t _real_NiFpga_WriteArrayI8 = NULL;
static _real_NiFpga_WriteArrayU8_t _real_NiFpga_WriteArrayU8 = NULL;
static _real_NiFpga_WriteArrayI16_t _real_NiFpga_WriteArrayI16 = NULL;
static _real_NiFpga_WriteArrayU16_t _real_NiFpga_WriteArrayU16 = NULL;
static _real_NiFpga_WriteArrayI32_t _real_NiFpga_WriteArrayI32 = NULL;
static _real_NiFpga_WriteArrayU32_t _real_NiFpga_WriteArrayU32 = NULL;
static _real_NiFpga_WriteArrayI64_t _real_NiFpga_WriteArrayI64 = NULL;
static _real_NiFpga_WriteArrayU64_t _real_NiFpga_WriteArrayU64 = NULL;
static _real_NiFpga_WriteArraySgl_t _real_NiFpga_WriteArraySgl = NULL;
static _real_NiFpga_WriteArrayDbl_t _real_NiFpga_WriteArrayDbl = NULL;
static _real_NiFpga_ReserveIrqContext_t _real_NiFpga_ReserveIrqContext = NULL;
static _real_NiFpga_UnreserveIrqContext_t _real_NiFpga_UnreserveIrqContext = NULL;
static _real_NiFpga_WaitOnIrqs_t _real_NiFpga_WaitOnIrqs = NULL;
static _real_NiFpga_AcknowledgeIrqs_t _real_NiFpga_AcknowledgeIrqs = NULL;
static _real_NiFpga_ConfigureFifo_t _real_NiFpga_ConfigureFifo = NULL;
static _real_NiFpga_ConfigureFifo2_t _real_NiFpga_ConfigureFifo2 = NULL;
static _real_NiFpga_StartFifo_t _real_NiFpga_StartFifo = NULL;
static _real_NiFpga_StopFifo_t _real_NiFpga_StopFifo = NULL;
static _real_NiFpga_ReadFifoBool_t _real_NiFpga_ReadFifoBool = NULL;
static _real_NiFpga_ReadFifoI8_t _real_NiFpga_ReadFifoI8 = NULL;
static _real_NiFpga_ReadFifoU8_t _real_NiFpga_ReadFifoU8 = NULL;
static _real_NiFpga_ReadFifoI16_t _real_NiFpga_ReadFifoI16 = NULL;
static _real_NiFpga_ReadFifoU16_t _real_NiFpga_ReadFifoU16 = NULL;
static _real_NiFpga_ReadFifoI32_t _real_NiFpga_ReadFifoI32 = NULL;
static _real_NiFpga_ReadFifoU32_t _real_NiFpga_ReadFifoU32 = NULL;
static _real_NiFpga_ReadFifoI64_t _real_NiFpga_ReadFifoI64 = NULL;
static _real_NiFpga_ReadFifoU64_t _real_NiFpga_ReadFifoU64 = NULL;
static _real_NiFpga_ReadFifoSgl_t _real_NiFpga_ReadFifoSgl = NULL;
static _real_NiFpga_ReadFifoDbl_t _real_NiFpga_ReadFifoDbl = NULL;
static _real_NiFpga_WriteFifoBool_t _real_NiFpga_WriteFifoBool = NULL;
static _real_NiFpga_WriteFifoI8_t _real_NiFpga_WriteFifoI8 = NULL;
static _real_NiFpga_WriteFifoU8_t _real_NiFpga_WriteFifoU8 = NULL;
static _real_NiFpga_WriteFifoI16_t _real_NiFpga_WriteFifoI16 = NULL;
static _real_NiFpga_WriteFifoU16_t _real_NiFpga_WriteFifoU16 = NULL;
static _real_NiFpga_WriteFifoI32_t _real_NiFpga_WriteFifoI32 = NULL;
static _real_NiFpga_WriteFifoU32_t _real_NiFpga_WriteFifoU32 = NULL;
static _real_NiFpga_WriteFifoI64_t _real_NiFpga_WriteFifoI64 = NULL;
static _real_NiFpga_WriteFifoU64_t _real_NiFpga_WriteFifoU64 = NULL;
static _real_NiFpga_WriteFifoSgl_t _real_NiFpga_WriteFifoSgl = NULL;
static _real_NiFpga_WriteFifoDbl_t _real_NiFpga_WriteFifoDbl = NULL;
static _real_NiFpga_AcquireFifoReadElementsBool_t _real_NiFpga_AcquireFifoReadElementsBool = NULL;
static _real_NiFpga_AcquireFifoReadElementsI8_t _real_NiFpga_AcquireFifoReadElementsI8 = NULL;
static _real_NiFpga_AcquireFifoReadElementsU8_t _real_NiFpga_AcquireFifoReadElementsU8 = NULL;
static _real_NiFpga_AcquireFifoReadElementsI16_t _real_NiFpga_AcquireFifoReadElementsI16 = NULL;
static _real_NiFpga_AcquireFifoReadElementsU16_t _real_NiFpga_AcquireFifoReadElementsU16 = NULL;
static _real_NiFpga_AcquireFifoReadElementsI32_t _real_NiFpga_AcquireFifoReadElementsI32 = NULL;
static _real_NiFpga_AcquireFifoReadElementsU32_t _real_NiFpga_AcquireFifoReadElementsU32 = NULL;
static _real_NiFpga_AcquireFifoReadElementsI64_t _real_NiFpga_AcquireFifoReadElementsI64 = NULL;
static _real_NiFpga_AcquireFifoReadElementsU64_t _real_NiFpga_AcquireFifoReadElementsU64 = NULL;
static _real_NiFpga_AcquireFifoReadElementsSgl_t _real_NiFpga_AcquireFifoReadElementsSgl = NULL;
static _real_NiFpga_AcquireFifoReadElementsDbl_t _real_NiFpga_AcquireFifoReadElementsDbl = NULL;
static _real_NiFpga_AcquireFifoWriteElementsBool_t _real_NiFpga_AcquireFifoWriteElementsBool = NULL;
static _real_NiFpga_AcquireFifoWriteElementsI8_t _real_NiFpga_AcquireFifoWriteElementsI8 = NULL;
static _real_NiFpga_AcquireFifoWriteElementsU8_t _real_NiFpga_AcquireFifoWriteElementsU8 = NULL;
static _real_NiFpga_AcquireFifoWriteElementsI16_t _real_NiFpga_AcquireFifoWriteElementsI16 = NULL;
static _real_NiFpga_AcquireFifoWriteElementsU16_t _real_NiFpga_AcquireFifoWriteElementsU16 = NULL;
static _real_NiFpga_AcquireFifoWriteElementsI32_t _real_NiFpga_AcquireFifoWriteElementsI32 = NULL;
static _real_NiFpga_AcquireFifoWriteElementsU32_t _real_NiFpga_AcquireFifoWriteElementsU32 = NULL;
static _real_NiFpga_AcquireFifoWriteElementsI64_t _real_NiFpga_AcquireFifoWriteElementsI64 = NULL;
static _real_NiFpga_AcquireFifoWriteElementsU64_t _real_NiFpga_AcquireFifoWriteElementsU64 = NULL;
static _real_NiFpga_AcquireFifoWriteElementsSgl_t _real_NiFpga_AcquireFifoWriteElementsSgl = NULL;
static _real_NiFpga_AcquireFifoWriteElementsDbl_t _real_NiFpga_AcquireFifoWriteElementsDbl = NULL;
static _real_NiFpga_ReleaseFifoElements_t _real_NiFpga_ReleaseFifoElements = NULL;
static _real_NiFpga_GetPeerToPeerFifoEndpoint_t _real_NiFpga_GetPeerToPeerFifoEndpoint = NULL;
static _real_NiFpga_GetBitfileContents_t _real_NiFpga_GetBitfileContents = NULL;
static _real_NiFpga_ClientFunctionCall_t _real_NiFpga_ClientFunctionCall = NULL;

NiFpga_Bool NiFpgaDll_IsError(const NiFpga_Status status) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_IsError\n");
	fprintf(outfile, "\tstatus = %d\n", status);
	return _real_NiFpga_IsError ? _real_NiFpga_IsError(status) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Bool NiFpgaDll_IsNotError(const NiFpga_Status status) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_IsNotError\n");
	fprintf(outfile, "\tstatus = %d\n", status);
	return _real_NiFpga_IsNotError ? _real_NiFpga_IsNotError(status) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_MergeStatus(NiFpga_Status *const status, const NiFpga_Status newStatus) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_MergeStatus\n");
	fprintf(outfile, "\tstatus = %p\n", status);
	fprintf(outfile, "\tnewStatus = %d\n", newStatus);
	return _real_NiFpga_MergeStatus ? _real_NiFpga_MergeStatus(status, newStatus) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_Initialize() {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_Initialize\n");
	return _real_NiFpga_Initialize ? _real_NiFpga_Initialize() : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_Finalize() {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_Finalize\n");
	return _real_NiFpga_Finalize ? _real_NiFpga_Finalize() : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_Open(const char * bitfile, const char * signature, const char * resource, uint32_t attribute, NiFpga_Session * session) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_Open\n");
	fprintf(outfile, "\tbitfile = %p\n", bitfile);
	fprintf(outfile, "\tsignature = %p\n", signature);
	fprintf(outfile, "\tresource = %p\n", resource);
	fprintf(outfile, "\tattribute = %d\n", attribute);
	fprintf(outfile, "\tsession = %p\n", session);
	return _real_NiFpga_Open ? _real_NiFpga_Open(bitfile, signature, resource, attribute, session) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_Close(NiFpga_Session session, uint32_t attribute) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_Close\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tattribute = %d\n", attribute);
	return _real_NiFpga_Close ? _real_NiFpga_Close(session, attribute) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_Run(NiFpga_Session session, uint32_t attribute) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_Run\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tattribute = %d\n", attribute);
	return _real_NiFpga_Run ? _real_NiFpga_Run(session, attribute) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_Abort(NiFpga_Session session) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_Abort\n");
	fprintf(outfile, "\tsession = %d\n", session);
	return _real_NiFpga_Abort ? _real_NiFpga_Abort(session) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_Reset(NiFpga_Session session) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_Reset\n");
	fprintf(outfile, "\tsession = %d\n", session);
	return _real_NiFpga_Reset ? _real_NiFpga_Reset(session) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_Download(NiFpga_Session session) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_Download\n");
	fprintf(outfile, "\tsession = %d\n", session);
	return _real_NiFpga_Download ? _real_NiFpga_Download(session) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadBool(NiFpga_Session session, uint32_t indicator, NiFpga_Bool * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadBool\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadBool ? _real_NiFpga_ReadBool(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadI8(NiFpga_Session session, uint32_t indicator, int8_t * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadI8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadI8 ? _real_NiFpga_ReadI8(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadU8(NiFpga_Session session, uint32_t indicator, uint8_t * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadU8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadU8 ? _real_NiFpga_ReadU8(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadI16(NiFpga_Session session, uint32_t indicator, int16_t * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadI16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadI16 ? _real_NiFpga_ReadI16(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadU16(NiFpga_Session session, uint32_t indicator, uint16_t * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadU16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadU16 ? _real_NiFpga_ReadU16(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadI32(NiFpga_Session session, uint32_t indicator, int32_t * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadI32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadI32 ? _real_NiFpga_ReadI32(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadU32(NiFpga_Session session, uint32_t indicator, uint32_t * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadU32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadU32 ? _real_NiFpga_ReadU32(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadI64(NiFpga_Session session, uint32_t indicator, int64_t * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadI64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadI64 ? _real_NiFpga_ReadI64(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadU64(NiFpga_Session session, uint32_t indicator, uint64_t * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadU64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadU64 ? _real_NiFpga_ReadU64(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadSgl(NiFpga_Session session, uint32_t indicator, float * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadSgl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadSgl ? _real_NiFpga_ReadSgl(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadDbl(NiFpga_Session session, uint32_t indicator, double * value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadDbl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tvalue = %p\n", value);
	return _real_NiFpga_ReadDbl ? _real_NiFpga_ReadDbl(session, indicator, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteBool(NiFpga_Session session, uint32_t control, NiFpga_Bool value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteBool\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteBool ? _real_NiFpga_WriteBool(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteI8(NiFpga_Session session, uint32_t control, int8_t value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteI8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteI8 ? _real_NiFpga_WriteI8(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteU8(NiFpga_Session session, uint32_t control, uint8_t value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteU8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteU8 ? _real_NiFpga_WriteU8(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteI16(NiFpga_Session session, uint32_t control, int16_t value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteI16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteI16 ? _real_NiFpga_WriteI16(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteU16(NiFpga_Session session, uint32_t control, uint16_t value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteU16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteU16 ? _real_NiFpga_WriteU16(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteI32(NiFpga_Session session, uint32_t control, int32_t value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteI32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteI32 ? _real_NiFpga_WriteI32(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteU32(NiFpga_Session session, uint32_t control, uint32_t value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteU32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteU32 ? _real_NiFpga_WriteU32(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteI64(NiFpga_Session session, uint32_t control, int64_t value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteI64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteI64 ? _real_NiFpga_WriteI64(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteU64(NiFpga_Session session, uint32_t control, uint64_t value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteU64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %d\n", value);
	return _real_NiFpga_WriteU64 ? _real_NiFpga_WriteU64(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteSgl(NiFpga_Session session, uint32_t control, float value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteSgl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %f\n", value);
	return _real_NiFpga_WriteSgl ? _real_NiFpga_WriteSgl(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteDbl(NiFpga_Session session, uint32_t control, double value) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteDbl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tvalue = %f\n", value);
	return _real_NiFpga_WriteDbl ? _real_NiFpga_WriteDbl(session, control, value) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayBool(NiFpga_Session session, uint32_t indicator, NiFpga_Bool * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayBool\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayBool ? _real_NiFpga_ReadArrayBool(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayI8(NiFpga_Session session, uint32_t indicator, int8_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayI8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayI8 ? _real_NiFpga_ReadArrayI8(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayU8(NiFpga_Session session, uint32_t indicator, uint8_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayU8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayU8 ? _real_NiFpga_ReadArrayU8(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayI16(NiFpga_Session session, uint32_t indicator, int16_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayI16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayI16 ? _real_NiFpga_ReadArrayI16(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayU16(NiFpga_Session session, uint32_t indicator, uint16_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayU16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayU16 ? _real_NiFpga_ReadArrayU16(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayI32(NiFpga_Session session, uint32_t indicator, int32_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayI32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayI32 ? _real_NiFpga_ReadArrayI32(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayU32(NiFpga_Session session, uint32_t indicator, uint32_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayU32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayU32 ? _real_NiFpga_ReadArrayU32(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayI64(NiFpga_Session session, uint32_t indicator, int64_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayI64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayI64 ? _real_NiFpga_ReadArrayI64(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayU64(NiFpga_Session session, uint32_t indicator, uint64_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayU64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayU64 ? _real_NiFpga_ReadArrayU64(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArraySgl(NiFpga_Session session, uint32_t indicator, float * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArraySgl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArraySgl ? _real_NiFpga_ReadArraySgl(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadArrayDbl(NiFpga_Session session, uint32_t indicator, double * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadArrayDbl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tindicator = %d\n", indicator);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_ReadArrayDbl ? _real_NiFpga_ReadArrayDbl(session, indicator, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayBool(NiFpga_Session session, uint32_t control, const NiFpga_Bool * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayBool\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayBool ? _real_NiFpga_WriteArrayBool(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayI8(NiFpga_Session session, uint32_t control, const int8_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayI8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayI8 ? _real_NiFpga_WriteArrayI8(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayU8(NiFpga_Session session, uint32_t control, const uint8_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayU8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayU8 ? _real_NiFpga_WriteArrayU8(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayI16(NiFpga_Session session, uint32_t control, const int16_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayI16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayI16 ? _real_NiFpga_WriteArrayI16(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayU16(NiFpga_Session session, uint32_t control, const uint16_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayU16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayU16 ? _real_NiFpga_WriteArrayU16(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayI32(NiFpga_Session session, uint32_t control, const int32_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayI32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayI32 ? _real_NiFpga_WriteArrayI32(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayU32(NiFpga_Session session, uint32_t control, const uint32_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayU32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayU32 ? _real_NiFpga_WriteArrayU32(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayI64(NiFpga_Session session, uint32_t control, const int64_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayI64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayI64 ? _real_NiFpga_WriteArrayI64(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayU64(NiFpga_Session session, uint32_t control, const uint64_t * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayU64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayU64 ? _real_NiFpga_WriteArrayU64(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArraySgl(NiFpga_Session session, uint32_t control, const float * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArraySgl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArraySgl ? _real_NiFpga_WriteArraySgl(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteArrayDbl(NiFpga_Session session, uint32_t control, const double * array, int size) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteArrayDbl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontrol = %d\n", control);
	fprintf(outfile, "\tarray = %p\n", array);
	fprintf(outfile, "\tsize = %d\n", size);
	return _real_NiFpga_WriteArrayDbl ? _real_NiFpga_WriteArrayDbl(session, control, array, size) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReserveIrqContext(NiFpga_Session session, NiFpga_IrqContext * context) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReserveIrqContext\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontext = %p\n", context);
	return _real_NiFpga_ReserveIrqContext ? _real_NiFpga_ReserveIrqContext(session, context) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_UnreserveIrqContext(NiFpga_Session session, NiFpga_IrqContext context) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_UnreserveIrqContext\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontext = %d\n", context);
	return _real_NiFpga_UnreserveIrqContext ? _real_NiFpga_UnreserveIrqContext(session, context) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WaitOnIrqs(NiFpga_Session session, NiFpga_IrqContext context, uint32_t irqs, uint32_t timeout, uint32_t * irqsAsserted, NiFpga_Bool * timedOut) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WaitOnIrqs\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontext = %d\n", context);
	fprintf(outfile, "\tirqs = %d\n", irqs);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\tirqsAsserted = %p\n", irqsAsserted);
	fprintf(outfile, "\ttimedOut = %p\n", timedOut);
	return _real_NiFpga_WaitOnIrqs ? _real_NiFpga_WaitOnIrqs(session, context, irqs, timeout, irqsAsserted, timedOut) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcknowledgeIrqs(NiFpga_Session session, uint32_t irqs) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcknowledgeIrqs\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tirqs = %d\n", irqs);
	return _real_NiFpga_AcknowledgeIrqs ? _real_NiFpga_AcknowledgeIrqs(session, irqs) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ConfigureFifo(NiFpga_Session session, uint32_t fifo, int depth) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ConfigureFifo\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdepth = %d\n", depth);
	return _real_NiFpga_ConfigureFifo ? _real_NiFpga_ConfigureFifo(session, fifo, depth) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ConfigureFifo2(NiFpga_Session session, uint32_t fifo, int requestedDepth, int * actualDepth) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ConfigureFifo2\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\trequestedDepth = %d\n", requestedDepth);
	fprintf(outfile, "\tactualDepth = %p\n", actualDepth);
	return _real_NiFpga_ConfigureFifo2 ? _real_NiFpga_ConfigureFifo2(session, fifo, requestedDepth, actualDepth) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_StartFifo(NiFpga_Session session, uint32_t fifo) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_StartFifo\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	return _real_NiFpga_StartFifo ? _real_NiFpga_StartFifo(session, fifo) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_StopFifo(NiFpga_Session session, uint32_t fifo) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_StopFifo\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	return _real_NiFpga_StopFifo ? _real_NiFpga_StopFifo(session, fifo) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoBool\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoBool ? _real_NiFpga_ReadFifoBool(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoI8(NiFpga_Session session, uint32_t fifo, int8_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoI8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoI8 ? _real_NiFpga_ReadFifoI8(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoU8(NiFpga_Session session, uint32_t fifo, uint8_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoU8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoU8 ? _real_NiFpga_ReadFifoU8(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoI16(NiFpga_Session session, uint32_t fifo, int16_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoI16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoI16 ? _real_NiFpga_ReadFifoI16(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoU16(NiFpga_Session session, uint32_t fifo, uint16_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoU16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoU16 ? _real_NiFpga_ReadFifoU16(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoI32(NiFpga_Session session, uint32_t fifo, int32_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoI32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoI32 ? _real_NiFpga_ReadFifoI32(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoU32(NiFpga_Session session, uint32_t fifo, uint32_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoU32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoU32 ? _real_NiFpga_ReadFifoU32(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoI64(NiFpga_Session session, uint32_t fifo, int64_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoI64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoI64 ? _real_NiFpga_ReadFifoI64(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoU64(NiFpga_Session session, uint32_t fifo, uint64_t * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoU64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoU64 ? _real_NiFpga_ReadFifoU64(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoSgl(NiFpga_Session session, uint32_t fifo, float * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoSgl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoSgl ? _real_NiFpga_ReadFifoSgl(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReadFifoDbl(NiFpga_Session session, uint32_t fifo, double * data, int numberOfElements, uint32_t timeout, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReadFifoDbl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_ReadFifoDbl ? _real_NiFpga_ReadFifoDbl(session, fifo, data, numberOfElements, timeout, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoBool(NiFpga_Session session, uint32_t fifo, const NiFpga_Bool * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoBool\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoBool ? _real_NiFpga_WriteFifoBool(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoI8(NiFpga_Session session, uint32_t fifo, const int8_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoI8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoI8 ? _real_NiFpga_WriteFifoI8(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoU8(NiFpga_Session session, uint32_t fifo, const uint8_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoU8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoU8 ? _real_NiFpga_WriteFifoU8(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoI16(NiFpga_Session session, uint32_t fifo, const int16_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoI16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoI16 ? _real_NiFpga_WriteFifoI16(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoU16(NiFpga_Session session, uint32_t fifo, const uint16_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoU16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoU16 ? _real_NiFpga_WriteFifoU16(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoI32(NiFpga_Session session, uint32_t fifo, const int32_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoI32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoI32 ? _real_NiFpga_WriteFifoI32(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoU32(NiFpga_Session session, uint32_t fifo, const uint32_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoU32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoU32 ? _real_NiFpga_WriteFifoU32(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoI64(NiFpga_Session session, uint32_t fifo, const int64_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoI64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoI64 ? _real_NiFpga_WriteFifoI64(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoU64(NiFpga_Session session, uint32_t fifo, const uint64_t * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoU64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoU64 ? _real_NiFpga_WriteFifoU64(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoSgl(NiFpga_Session session, uint32_t fifo, const float * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoSgl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoSgl ? _real_NiFpga_WriteFifoSgl(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_WriteFifoDbl(NiFpga_Session session, uint32_t fifo, const double * data, int numberOfElements, uint32_t timeout, int * emptyElementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_WriteFifoDbl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tdata = %p\n", data);
	fprintf(outfile, "\tnumberOfElements = %d\n", numberOfElements);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\temptyElementsRemaining = %p\n", emptyElementsRemaining);
	return _real_NiFpga_WriteFifoDbl ? _real_NiFpga_WriteFifoDbl(session, fifo, data, numberOfElements, timeout, emptyElementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsBool\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsBool ? _real_NiFpga_AcquireFifoReadElementsBool(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsI8(NiFpga_Session session, uint32_t fifo, int8_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsI8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsI8 ? _real_NiFpga_AcquireFifoReadElementsI8(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsU8(NiFpga_Session session, uint32_t fifo, uint8_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsU8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsU8 ? _real_NiFpga_AcquireFifoReadElementsU8(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsI16(NiFpga_Session session, uint32_t fifo, int16_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsI16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsI16 ? _real_NiFpga_AcquireFifoReadElementsI16(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsU16(NiFpga_Session session, uint32_t fifo, uint16_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsU16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsU16 ? _real_NiFpga_AcquireFifoReadElementsU16(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsI32(NiFpga_Session session, uint32_t fifo, int32_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsI32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsI32 ? _real_NiFpga_AcquireFifoReadElementsI32(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsU32(NiFpga_Session session, uint32_t fifo, uint32_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsU32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsU32 ? _real_NiFpga_AcquireFifoReadElementsU32(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsI64(NiFpga_Session session, uint32_t fifo, int64_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsI64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsI64 ? _real_NiFpga_AcquireFifoReadElementsI64(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsU64(NiFpga_Session session, uint32_t fifo, uint64_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsU64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsU64 ? _real_NiFpga_AcquireFifoReadElementsU64(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsSgl(NiFpga_Session session, uint32_t fifo, float ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsSgl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsSgl ? _real_NiFpga_AcquireFifoReadElementsSgl(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoReadElementsDbl(NiFpga_Session session, uint32_t fifo, double ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoReadElementsDbl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoReadElementsDbl ? _real_NiFpga_AcquireFifoReadElementsDbl(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsBool(NiFpga_Session session, uint32_t fifo, NiFpga_Bool ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsBool\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsBool ? _real_NiFpga_AcquireFifoWriteElementsBool(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsI8(NiFpga_Session session, uint32_t fifo, int8_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsI8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsI8 ? _real_NiFpga_AcquireFifoWriteElementsI8(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsU8(NiFpga_Session session, uint32_t fifo, uint8_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsU8\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsU8 ? _real_NiFpga_AcquireFifoWriteElementsU8(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsI16(NiFpga_Session session, uint32_t fifo, int16_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsI16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsI16 ? _real_NiFpga_AcquireFifoWriteElementsI16(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsU16(NiFpga_Session session, uint32_t fifo, uint16_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsU16\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsU16 ? _real_NiFpga_AcquireFifoWriteElementsU16(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsI32(NiFpga_Session session, uint32_t fifo, int32_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsI32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsI32 ? _real_NiFpga_AcquireFifoWriteElementsI32(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsU32(NiFpga_Session session, uint32_t fifo, uint32_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsU32\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsU32 ? _real_NiFpga_AcquireFifoWriteElementsU32(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsI64(NiFpga_Session session, uint32_t fifo, int64_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsI64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsI64 ? _real_NiFpga_AcquireFifoWriteElementsI64(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsU64(NiFpga_Session session, uint32_t fifo, uint64_t ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsU64\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsU64 ? _real_NiFpga_AcquireFifoWriteElementsU64(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsSgl(NiFpga_Session session, uint32_t fifo, float ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsSgl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsSgl ? _real_NiFpga_AcquireFifoWriteElementsSgl(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_AcquireFifoWriteElementsDbl(NiFpga_Session session, uint32_t fifo, double ** elements, int elementsRequested, uint32_t timeout, int * elementsAcquired, int * elementsRemaining) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_AcquireFifoWriteElementsDbl\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %p\n", elements);
	fprintf(outfile, "\telementsRequested = %d\n", elementsRequested);
	fprintf(outfile, "\ttimeout = %d\n", timeout);
	fprintf(outfile, "\telementsAcquired = %p\n", elementsAcquired);
	fprintf(outfile, "\telementsRemaining = %p\n", elementsRemaining);
	return _real_NiFpga_AcquireFifoWriteElementsDbl ? _real_NiFpga_AcquireFifoWriteElementsDbl(session, fifo, elements, elementsRequested, timeout, elementsAcquired, elementsRemaining) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ReleaseFifoElements(NiFpga_Session session, uint32_t fifo, int elements) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ReleaseFifoElements\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\telements = %d\n", elements);
	return _real_NiFpga_ReleaseFifoElements ? _real_NiFpga_ReleaseFifoElements(session, fifo, elements) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_GetPeerToPeerFifoEndpoint(NiFpga_Session session, uint32_t fifo, uint32_t * endpoint) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_GetPeerToPeerFifoEndpoint\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tfifo = %d\n", fifo);
	fprintf(outfile, "\tendpoint = %p\n", endpoint);
	return _real_NiFpga_GetPeerToPeerFifoEndpoint ? _real_NiFpga_GetPeerToPeerFifoEndpoint(session, fifo, endpoint) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_GetBitfileContents(NiFpga_Session session, const char ** contents) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_GetBitfileContents\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tcontents = %p\n", contents);
	return _real_NiFpga_GetBitfileContents ? _real_NiFpga_GetBitfileContents(session, contents) : NiFpga_Status_ResourceNotInitialized;
}
NiFpga_Status NiFpgaDll_ClientFunctionCall(NiFpga_Session session, uint32_t group, uint32_t functionId, const void * inBuffer, int inBufferSize, void * outBuffer, int outBufferSize) {
	if(!initialized) _proxy_init();
	fprintf(outfile, "NiFpga_ClientFunctionCall\n");
	fprintf(outfile, "\tsession = %d\n", session);
	fprintf(outfile, "\tgroup = %d\n", group);
	fprintf(outfile, "\tfunctionId = %d\n", functionId);
	fprintf(outfile, "\tinBuffer = %p\n", inBuffer);
	fprintf(outfile, "\tinBufferSize = %d\n", inBufferSize);
	fprintf(outfile, "\toutBuffer = %p\n", outBuffer);
	fprintf(outfile, "\toutBufferSize = %d\n", outBufferSize);
	return _real_NiFpga_ClientFunctionCall ? _real_NiFpga_ClientFunctionCall(session, group, functionId, inBuffer, inBufferSize, outBuffer, outBufferSize) : NiFpga_Status_ResourceNotInitialized;
}

static void _proxy_load_fns() {
	_real_NiFpga_IsError = (_real_NiFpga_IsError_t) dlsym(handle, "NiFpgaDll_IsError");
	_real_NiFpga_IsNotError = (_real_NiFpga_IsNotError_t) dlsym(handle, "NiFpgaDll_IsNotError");
	_real_NiFpga_MergeStatus = (_real_NiFpga_MergeStatus_t) dlsym(handle, "NiFpgaDll_MergeStatus");
	_real_NiFpga_Initialize = (_real_NiFpga_Initialize_t) dlsym(handle, "NiFpgaDll_Initialize");
	_real_NiFpga_Finalize = (_real_NiFpga_Finalize_t) dlsym(handle, "NiFpgaDll_Finalize");
	_real_NiFpga_Open = (_real_NiFpga_Open_t) dlsym(handle, "NiFpgaDll_Open");
	_real_NiFpga_Close = (_real_NiFpga_Close_t) dlsym(handle, "NiFpgaDll_Close");
	_real_NiFpga_Run = (_real_NiFpga_Run_t) dlsym(handle, "NiFpgaDll_Run");
	_real_NiFpga_Abort = (_real_NiFpga_Abort_t) dlsym(handle, "NiFpgaDll_Abort");
	_real_NiFpga_Reset = (_real_NiFpga_Reset_t) dlsym(handle, "NiFpgaDll_Reset");
	_real_NiFpga_Download = (_real_NiFpga_Download_t) dlsym(handle, "NiFpgaDll_Download");
	_real_NiFpga_ReadBool = (_real_NiFpga_ReadBool_t) dlsym(handle, "NiFpgaDll_ReadBool");
	_real_NiFpga_ReadI8 = (_real_NiFpga_ReadI8_t) dlsym(handle, "NiFpgaDll_ReadI8");
	_real_NiFpga_ReadU8 = (_real_NiFpga_ReadU8_t) dlsym(handle, "NiFpgaDll_ReadU8");
	_real_NiFpga_ReadI16 = (_real_NiFpga_ReadI16_t) dlsym(handle, "NiFpgaDll_ReadI16");
	_real_NiFpga_ReadU16 = (_real_NiFpga_ReadU16_t) dlsym(handle, "NiFpgaDll_ReadU16");
	_real_NiFpga_ReadI32 = (_real_NiFpga_ReadI32_t) dlsym(handle, "NiFpgaDll_ReadI32");
	_real_NiFpga_ReadU32 = (_real_NiFpga_ReadU32_t) dlsym(handle, "NiFpgaDll_ReadU32");
	_real_NiFpga_ReadI64 = (_real_NiFpga_ReadI64_t) dlsym(handle, "NiFpgaDll_ReadI64");
	_real_NiFpga_ReadU64 = (_real_NiFpga_ReadU64_t) dlsym(handle, "NiFpgaDll_ReadU64");
	_real_NiFpga_ReadSgl = (_real_NiFpga_ReadSgl_t) dlsym(handle, "NiFpgaDll_ReadSgl");
	_real_NiFpga_ReadDbl = (_real_NiFpga_ReadDbl_t) dlsym(handle, "NiFpgaDll_ReadDbl");
	_real_NiFpga_WriteBool = (_real_NiFpga_WriteBool_t) dlsym(handle, "NiFpgaDll_WriteBool");
	_real_NiFpga_WriteI8 = (_real_NiFpga_WriteI8_t) dlsym(handle, "NiFpgaDll_WriteI8");
	_real_NiFpga_WriteU8 = (_real_NiFpga_WriteU8_t) dlsym(handle, "NiFpgaDll_WriteU8");
	_real_NiFpga_WriteI16 = (_real_NiFpga_WriteI16_t) dlsym(handle, "NiFpgaDll_WriteI16");
	_real_NiFpga_WriteU16 = (_real_NiFpga_WriteU16_t) dlsym(handle, "NiFpgaDll_WriteU16");
	_real_NiFpga_WriteI32 = (_real_NiFpga_WriteI32_t) dlsym(handle, "NiFpgaDll_WriteI32");
	_real_NiFpga_WriteU32 = (_real_NiFpga_WriteU32_t) dlsym(handle, "NiFpgaDll_WriteU32");
	_real_NiFpga_WriteI64 = (_real_NiFpga_WriteI64_t) dlsym(handle, "NiFpgaDll_WriteI64");
	_real_NiFpga_WriteU64 = (_real_NiFpga_WriteU64_t) dlsym(handle, "NiFpgaDll_WriteU64");
	_real_NiFpga_WriteSgl = (_real_NiFpga_WriteSgl_t) dlsym(handle, "NiFpgaDll_WriteSgl");
	_real_NiFpga_WriteDbl = (_real_NiFpga_WriteDbl_t) dlsym(handle, "NiFpgaDll_WriteDbl");
	_real_NiFpga_ReadArrayBool = (_real_NiFpga_ReadArrayBool_t) dlsym(handle, "NiFpgaDll_ReadArrayBool");
	_real_NiFpga_ReadArrayI8 = (_real_NiFpga_ReadArrayI8_t) dlsym(handle, "NiFpgaDll_ReadArrayI8");
	_real_NiFpga_ReadArrayU8 = (_real_NiFpga_ReadArrayU8_t) dlsym(handle, "NiFpgaDll_ReadArrayU8");
	_real_NiFpga_ReadArrayI16 = (_real_NiFpga_ReadArrayI16_t) dlsym(handle, "NiFpgaDll_ReadArrayI16");
	_real_NiFpga_ReadArrayU16 = (_real_NiFpga_ReadArrayU16_t) dlsym(handle, "NiFpgaDll_ReadArrayU16");
	_real_NiFpga_ReadArrayI32 = (_real_NiFpga_ReadArrayI32_t) dlsym(handle, "NiFpgaDll_ReadArrayI32");
	_real_NiFpga_ReadArrayU32 = (_real_NiFpga_ReadArrayU32_t) dlsym(handle, "NiFpgaDll_ReadArrayU32");
	_real_NiFpga_ReadArrayI64 = (_real_NiFpga_ReadArrayI64_t) dlsym(handle, "NiFpgaDll_ReadArrayI64");
	_real_NiFpga_ReadArrayU64 = (_real_NiFpga_ReadArrayU64_t) dlsym(handle, "NiFpgaDll_ReadArrayU64");
	_real_NiFpga_ReadArraySgl = (_real_NiFpga_ReadArraySgl_t) dlsym(handle, "NiFpgaDll_ReadArraySgl");
	_real_NiFpga_ReadArrayDbl = (_real_NiFpga_ReadArrayDbl_t) dlsym(handle, "NiFpgaDll_ReadArrayDbl");
	_real_NiFpga_WriteArrayBool = (_real_NiFpga_WriteArrayBool_t) dlsym(handle, "NiFpgaDll_WriteArrayBool");
	_real_NiFpga_WriteArrayI8 = (_real_NiFpga_WriteArrayI8_t) dlsym(handle, "NiFpgaDll_WriteArrayI8");
	_real_NiFpga_WriteArrayU8 = (_real_NiFpga_WriteArrayU8_t) dlsym(handle, "NiFpgaDll_WriteArrayU8");
	_real_NiFpga_WriteArrayI16 = (_real_NiFpga_WriteArrayI16_t) dlsym(handle, "NiFpgaDll_WriteArrayI16");
	_real_NiFpga_WriteArrayU16 = (_real_NiFpga_WriteArrayU16_t) dlsym(handle, "NiFpgaDll_WriteArrayU16");
	_real_NiFpga_WriteArrayI32 = (_real_NiFpga_WriteArrayI32_t) dlsym(handle, "NiFpgaDll_WriteArrayI32");
	_real_NiFpga_WriteArrayU32 = (_real_NiFpga_WriteArrayU32_t) dlsym(handle, "NiFpgaDll_WriteArrayU32");
	_real_NiFpga_WriteArrayI64 = (_real_NiFpga_WriteArrayI64_t) dlsym(handle, "NiFpgaDll_WriteArrayI64");
	_real_NiFpga_WriteArrayU64 = (_real_NiFpga_WriteArrayU64_t) dlsym(handle, "NiFpgaDll_WriteArrayU64");
	_real_NiFpga_WriteArraySgl = (_real_NiFpga_WriteArraySgl_t) dlsym(handle, "NiFpgaDll_WriteArraySgl");
	_real_NiFpga_WriteArrayDbl = (_real_NiFpga_WriteArrayDbl_t) dlsym(handle, "NiFpgaDll_WriteArrayDbl");
	_real_NiFpga_ReserveIrqContext = (_real_NiFpga_ReserveIrqContext_t) dlsym(handle, "NiFpgaDll_ReserveIrqContext");
	_real_NiFpga_UnreserveIrqContext = (_real_NiFpga_UnreserveIrqContext_t) dlsym(handle, "NiFpgaDll_UnreserveIrqContext");
	_real_NiFpga_WaitOnIrqs = (_real_NiFpga_WaitOnIrqs_t) dlsym(handle, "NiFpgaDll_WaitOnIrqs");
	_real_NiFpga_AcknowledgeIrqs = (_real_NiFpga_AcknowledgeIrqs_t) dlsym(handle, "NiFpgaDll_AcknowledgeIrqs");
	_real_NiFpga_ConfigureFifo = (_real_NiFpga_ConfigureFifo_t) dlsym(handle, "NiFpgaDll_ConfigureFifo");
	_real_NiFpga_ConfigureFifo2 = (_real_NiFpga_ConfigureFifo2_t) dlsym(handle, "NiFpgaDll_ConfigureFifo2");
	_real_NiFpga_StartFifo = (_real_NiFpga_StartFifo_t) dlsym(handle, "NiFpgaDll_StartFifo");
	_real_NiFpga_StopFifo = (_real_NiFpga_StopFifo_t) dlsym(handle, "NiFpgaDll_StopFifo");
	_real_NiFpga_ReadFifoBool = (_real_NiFpga_ReadFifoBool_t) dlsym(handle, "NiFpgaDll_ReadFifoBool");
	_real_NiFpga_ReadFifoI8 = (_real_NiFpga_ReadFifoI8_t) dlsym(handle, "NiFpgaDll_ReadFifoI8");
	_real_NiFpga_ReadFifoU8 = (_real_NiFpga_ReadFifoU8_t) dlsym(handle, "NiFpgaDll_ReadFifoU8");
	_real_NiFpga_ReadFifoI16 = (_real_NiFpga_ReadFifoI16_t) dlsym(handle, "NiFpgaDll_ReadFifoI16");
	_real_NiFpga_ReadFifoU16 = (_real_NiFpga_ReadFifoU16_t) dlsym(handle, "NiFpgaDll_ReadFifoU16");
	_real_NiFpga_ReadFifoI32 = (_real_NiFpga_ReadFifoI32_t) dlsym(handle, "NiFpgaDll_ReadFifoI32");
	_real_NiFpga_ReadFifoU32 = (_real_NiFpga_ReadFifoU32_t) dlsym(handle, "NiFpgaDll_ReadFifoU32");
	_real_NiFpga_ReadFifoI64 = (_real_NiFpga_ReadFifoI64_t) dlsym(handle, "NiFpgaDll_ReadFifoI64");
	_real_NiFpga_ReadFifoU64 = (_real_NiFpga_ReadFifoU64_t) dlsym(handle, "NiFpgaDll_ReadFifoU64");
	_real_NiFpga_ReadFifoSgl = (_real_NiFpga_ReadFifoSgl_t) dlsym(handle, "NiFpgaDll_ReadFifoSgl");
	_real_NiFpga_ReadFifoDbl = (_real_NiFpga_ReadFifoDbl_t) dlsym(handle, "NiFpgaDll_ReadFifoDbl");
	_real_NiFpga_WriteFifoBool = (_real_NiFpga_WriteFifoBool_t) dlsym(handle, "NiFpgaDll_WriteFifoBool");
	_real_NiFpga_WriteFifoI8 = (_real_NiFpga_WriteFifoI8_t) dlsym(handle, "NiFpgaDll_WriteFifoI8");
	_real_NiFpga_WriteFifoU8 = (_real_NiFpga_WriteFifoU8_t) dlsym(handle, "NiFpgaDll_WriteFifoU8");
	_real_NiFpga_WriteFifoI16 = (_real_NiFpga_WriteFifoI16_t) dlsym(handle, "NiFpgaDll_WriteFifoI16");
	_real_NiFpga_WriteFifoU16 = (_real_NiFpga_WriteFifoU16_t) dlsym(handle, "NiFpgaDll_WriteFifoU16");
	_real_NiFpga_WriteFifoI32 = (_real_NiFpga_WriteFifoI32_t) dlsym(handle, "NiFpgaDll_WriteFifoI32");
	_real_NiFpga_WriteFifoU32 = (_real_NiFpga_WriteFifoU32_t) dlsym(handle, "NiFpgaDll_WriteFifoU32");
	_real_NiFpga_WriteFifoI64 = (_real_NiFpga_WriteFifoI64_t) dlsym(handle, "NiFpgaDll_WriteFifoI64");
	_real_NiFpga_WriteFifoU64 = (_real_NiFpga_WriteFifoU64_t) dlsym(handle, "NiFpgaDll_WriteFifoU64");
	_real_NiFpga_WriteFifoSgl = (_real_NiFpga_WriteFifoSgl_t) dlsym(handle, "NiFpgaDll_WriteFifoSgl");
	_real_NiFpga_WriteFifoDbl = (_real_NiFpga_WriteFifoDbl_t) dlsym(handle, "NiFpgaDll_WriteFifoDbl");
	_real_NiFpga_AcquireFifoReadElementsBool = (_real_NiFpga_AcquireFifoReadElementsBool_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsBool");
	_real_NiFpga_AcquireFifoReadElementsI8 = (_real_NiFpga_AcquireFifoReadElementsI8_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsI8");
	_real_NiFpga_AcquireFifoReadElementsU8 = (_real_NiFpga_AcquireFifoReadElementsU8_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsU8");
	_real_NiFpga_AcquireFifoReadElementsI16 = (_real_NiFpga_AcquireFifoReadElementsI16_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsI16");
	_real_NiFpga_AcquireFifoReadElementsU16 = (_real_NiFpga_AcquireFifoReadElementsU16_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsU16");
	_real_NiFpga_AcquireFifoReadElementsI32 = (_real_NiFpga_AcquireFifoReadElementsI32_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsI32");
	_real_NiFpga_AcquireFifoReadElementsU32 = (_real_NiFpga_AcquireFifoReadElementsU32_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsU32");
	_real_NiFpga_AcquireFifoReadElementsI64 = (_real_NiFpga_AcquireFifoReadElementsI64_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsI64");
	_real_NiFpga_AcquireFifoReadElementsU64 = (_real_NiFpga_AcquireFifoReadElementsU64_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsU64");
	_real_NiFpga_AcquireFifoReadElementsSgl = (_real_NiFpga_AcquireFifoReadElementsSgl_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsSgl");
	_real_NiFpga_AcquireFifoReadElementsDbl = (_real_NiFpga_AcquireFifoReadElementsDbl_t) dlsym(handle, "NiFpgaDll_AcquireFifoReadElementsDbl");
	_real_NiFpga_AcquireFifoWriteElementsBool = (_real_NiFpga_AcquireFifoWriteElementsBool_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsBool");
	_real_NiFpga_AcquireFifoWriteElementsI8 = (_real_NiFpga_AcquireFifoWriteElementsI8_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsI8");
	_real_NiFpga_AcquireFifoWriteElementsU8 = (_real_NiFpga_AcquireFifoWriteElementsU8_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsU8");
	_real_NiFpga_AcquireFifoWriteElementsI16 = (_real_NiFpga_AcquireFifoWriteElementsI16_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsI16");
	_real_NiFpga_AcquireFifoWriteElementsU16 = (_real_NiFpga_AcquireFifoWriteElementsU16_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsU16");
	_real_NiFpga_AcquireFifoWriteElementsI32 = (_real_NiFpga_AcquireFifoWriteElementsI32_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsI32");
	_real_NiFpga_AcquireFifoWriteElementsU32 = (_real_NiFpga_AcquireFifoWriteElementsU32_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsU32");
	_real_NiFpga_AcquireFifoWriteElementsI64 = (_real_NiFpga_AcquireFifoWriteElementsI64_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsI64");
	_real_NiFpga_AcquireFifoWriteElementsU64 = (_real_NiFpga_AcquireFifoWriteElementsU64_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsU64");
	_real_NiFpga_AcquireFifoWriteElementsSgl = (_real_NiFpga_AcquireFifoWriteElementsSgl_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsSgl");
	_real_NiFpga_AcquireFifoWriteElementsDbl = (_real_NiFpga_AcquireFifoWriteElementsDbl_t) dlsym(handle, "NiFpgaDll_AcquireFifoWriteElementsDbl");
	_real_NiFpga_ReleaseFifoElements = (_real_NiFpga_ReleaseFifoElements_t) dlsym(handle, "NiFpgaDll_ReleaseFifoElements");
	_real_NiFpga_GetPeerToPeerFifoEndpoint = (_real_NiFpga_GetPeerToPeerFifoEndpoint_t) dlsym(handle, "NiFpgaDll_GetPeerToPeerFifoEndpoint");
	_real_NiFpga_GetBitfileContents = (_real_NiFpga_GetBitfileContents_t) dlsym(handle, "NiFpgaDll_GetBitfileContents");
	_real_NiFpga_ClientFunctionCall = (_real_NiFpga_ClientFunctionCall_t) dlsym(handle, "NiFpgaDll_ClientFunctionCall");	initialized = 1;

}

