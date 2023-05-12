# LoadingImageWatching
 Windows驱动实现捕捉PE映像加载信息
 
 这里主要用了 PsSetLoadImageNotifyRoutine(设置映像加载回调) PsRemoveLoadImageNotifyRoutine(卸载映像加载回调);
 
 PsSetLoadImageNotifyRoutine 例程注册驱动程序提供的回调，每当映像 (（例如，DLL 或 EXE) ）加载 (或映射到内存) 时，该回调随后会收到通知。

以下是从微软官方文档节选出来的
NTSTATUS PsSetLoadImageNotifyRoutine(
  [in] PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine
);
参数
[in] NotifyRoutine

指向加载映像通知的调用方实现 的PLOAD_IMAGE_NOTIFY_ROUTINE 回调例程的指针。

返回值
PsSetLoadImageNotifyRoutine 返回STATUS_SUCCESS，或者如果回调注册失败，则返回STATUS_INSUFFICIENT_RESOURCES。

备注
最高级别的系统分析驱动程序可以调用 PsSetLoadImageNotifyRoutine 来设置其加载映像通知例程 ， (查看PLOAD_IMAGE_NOTIFY_ROUTINE) 。

可以同时注册以接收加载映像通知的最大驱动程序数为 8。 如果驱动程序调用 PsSetLoadImageNotifyRoutine 以尝试注册其他通知例程时，已注册最大负载映像通知例程数， 则 PsSetLoadImageNotifyRoutine 会失败并返回STATUS_INSUFFICIENT_RESOURCES。

PsRemoveLoadImageNotifyRoutine 例程删除由 PsSetLoadImageNotifyRoutine 例程注册的回调例程。

NTSTATUS PsRemoveLoadImageNotifyRoutine(
  [in] PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine
);
参数
[in] NotifyRoutine

指向驱动程序以前通过 PsSetLoadImageNotifyRoutine 注册的回调例程的指针。

返回值
如果 PsRemoveLoadImageNotifyRoutine 成功删除回调例程，则返回STATUS_SUCCESS;如果 NotifyRoutine 的值与任何已注册的回调例程不匹配，则返回STATUS_PROCEDURE_NOT_FOUND。

注解
如果驱动程序的回调例程当前正在运行， PsRemoveLoadImageNotifyRoutine 会等待回调例程退出，然后再将其删除。 因此，回调例程本身不得调用 PsRemoveLoadImageNotifyRoutine。
