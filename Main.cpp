#include<ntddk.h>

#include "ImageLoadingCallbackFunc.h"
#include "UnLoadFunc.h"

extern "C"
NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING /*RegistryPath*/)
{
	NTSTATUS status = PsSetLoadImageNotifyRoutine(LoadingImageCallBack);
	DbgPrint("----Setting callback----");

	DriverObject->DriverUnload = UnloadFunc;

	return status;
}