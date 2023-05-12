#pragma once
#include <ntddk.h>
#include  "ImageLoadingCallbackFunc.h"

VOID UnloadFunc(PDRIVER_OBJECT)
{
    PsRemoveLoadImageNotifyRoutine(LoadingImageCallBack);
    DbgPrint("----Unload Driver and remove callback-----");
}
