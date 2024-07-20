#ifndef __EBI_HTTP_H
#define __EBI_HTTP_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stddef.h>
#include <stdbool.h>

typedef enum {
    HV0_9, 
    HV1_0,
    HV1_1,
    HV2,
    HV3,
    HVUnknown = -1
} httpVersion_e;

typedef enum {
    HMOptions,
    HMGet,
    HMHead,
    HMPost,
    HMPut,
    HMDelete,
    HMTrace,
    HMConnect,
    HMPatch,
    HMUnknown = -1
} httpMethod_e;

typedef enum {
    HSOk = 200,
    HSUnknown = -1
} httpStatus_e;

typedef struct {
    unsigned char * pnVal;
    size_t zLen;
} httpPktBody_s;

typedef struct {
    httpMethod_e eMethod;
    char nPath[256];
    httpVersion_e eVersion;
    char nHeader[1024];
    httpPktBody_s sBody;
} httpReq_s;

typedef struct {
    httpVersion_e eVersion;
    httpStatus_e eStatus;
    char nHeader[1024];
    httpPktBody_s sBody;
} httpRes_s;

httpVersion_e 
httpVersionStrToEnum(
    const char * const cpcnVersion
);

const char * 
httpVersionEnumToStr(
    const httpVersion_e ceVersion
);

httpMethod_e 
httpMethodStrToEnum(
    const char * const cpcnMethod
);

const char * 
httpStatusEnumToStr(
    const httpStatus_e ceStatus
);

bool
httpIsHeaderKeyExist(
    const char * const cpcnHeader,
    const char * const cpcnKey
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __EBI_HTTP_H */
