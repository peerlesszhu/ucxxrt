/*
 * PROJECT:   Universal C++ RunTime (UCXXRT)
 * FILE:      terminate.cpp
 * DATA:      2021/05/10
 *
 * PURPOSE:   Universal C++ RunTime
 *
 * LICENSE:   Relicensed under The MIT License from The CC BY 4.0 License
 *
 * DEVELOPER: MiroKaku (miro.kaku AT Outlook.com)
 */

#include <ehdata_values.h>

#ifdef _KERNEL_MODE

EXTERN_C_START

//_ACRTIMP __declspec(noreturn) inline void __cdecl abort(void)
//{
//    KeBugCheckEx(
//        KMODE_EXCEPTION_NOT_HANDLED,
//        EH_EXCEPTION_NUMBER,
//        (ULONG_PTR)_ReturnAddress(),
//        EH_MAGIC_NUMBER1,
//        0);
//}

_ACRTIMP __declspec(noreturn) void __cdecl terminate() throw()
{
    KeBugCheckEx(
        KMODE_EXCEPTION_NOT_HANDLED,
        EH_EXCEPTION_NUMBER,
        (ULONG_PTR)_ReturnAddress(),
        EH_MAGIC_NUMBER1,
        1);
}

EXTERN_C_END

#endif
