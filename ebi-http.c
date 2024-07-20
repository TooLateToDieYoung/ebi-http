#include "ebi-http.h"
#include <string.h>

httpVersion_e 
httpVersionStrToEnum(
    const char * const cpcnVersion
) {
    if ( NULL == cpcnVersion )
    {
        return HVUnknown;
    }

    if ( 0 == strcsecmp(cpcnVersion, httpVersionEnumToStr(HV0_9)) )
    {
        return HV0_9;
    }

    if ( 0 == strcasecmp(cpcnVersion, httpVersionEnumToStr(HV1_0)) )
    {
        return HV1_0;
    }

    if ( 0 == strcasecmp(cpcnVersion, httpVersionEnumToStr(HV1_1)) )
    {
        return HV1_1;
    }

    if ( 0 == strcasecmp(cpcnVersion, httpVersionEnumToStr(HV2)) )
    {
        return HV2;
    }

    if ( 0 == strcasecmp(cpcnVersion, httpVersionEnumToStr(HV3)) )
    {
        return HV3;
    }

    return HVUnknown;
}

const char * 
httpVersionEnumToStr(
    const httpVersion_e ceVersion
) {
    switch ( ceVersion )
    {
    case HV0_9:
        return "HTTP/0.9";
    case HV1_0:
        return "HTTP/1.0";
    case HV1_1:
        return "HTTP/1.1";
    case HV2:
        return "HTTP/2";
    case HV3:
        return "HTTP/3";
    default:
        break;
    }

    return "";
}

httpMethod_e 
httpMethodStrToEnum(
    const char * const cpcnMethod
) {
    if ( NULL == cpcnMethod )
    {
        return HMUnknown;
    }

    if ( 0 == strcsecmp(cpcnMethod, "OPTIONS") )
    {
        return HMOptions;
    }

    if ( 0 == strcsecmp(cpcnMethod, "GET") )
    {
        return HMGet;
    }

    if ( 0 == strcsecmp(cpcnMethod, "HEAD") )
    {
        return HMHead;
    }

    if ( 0 == strcsecmp(cpcnMethod, "POST") )
    {
        return HMPost;
    }

    if ( 0 == strcsecmp(cpcnMethod, "PUT") )
    {
        return HMPut;
    }

    if ( 0 == strcsecmp(cpcnMethod, "DELETE") )
    {
        return HMDelete;
    }

    if ( 0 == strcsecmp(cpcnMethod, "TRACE") )
    {
        return HMTrace;
    }

    if ( 0 == strcsecmp(cpcnMethod, "CONNECT") )
    {
        return HMConnect;
    }

    if ( 0 == strcsecmp(cpcnMethod, "PATCH") )
    {
        return HMPatch;
    }

    return HMUnknown;
}

const char * 
httpStatusEnumToStr(
    const httpStatus_e ceStatus
) {
    switch ( ceStatus )
    {
    case HSOk:
        return "OK";

    // TODO

    default:
        break;
    }

    return "Not Found";
}

bool
httpIsHeaderKeyExist(
    const char * const cpcnHeader,
    const char * const cpcnKey
) {
    if ( NULL == cpcnHeader || NULL == cpcnKey )
    {
        return false;
    }

    return ( NULL != strstr(cpcnHeader, cpcnKey) ) ? ( true ) : ( false ) ;
}
