#pragma once
#include <ntddk.h>

VOID
LoadingImageCallBack(
    _In_opt_ PUNICODE_STRING FullImageName,
    _In_ HANDLE ProcessId,                // pid into which image is being mapped
    _In_ PIMAGE_INFO /*ImageInfo*/
)
{
    DbgPrint("----Image Path: %wS Process Id: %d----",FullImageName->Buffer, ProcessId);
}