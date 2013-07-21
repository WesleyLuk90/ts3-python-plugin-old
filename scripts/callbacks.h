void ts3plugin_onConnectStatusChangeEvent(uint64 serverConnectionHandlerID, int newStatus, unsigned int errorNumber){
	PyObject* function;
	logDebugFile("onConnectStatusChangeEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onConnectStatusChangeEvent lock held");
	function = PyDict_GetItemString(globalDict, "onConnectStatusChangeEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kii", serverConnectionHandlerID, newStatus, errorNumber);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onConnectStatusChangeEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onConnectStatusChangeEvent callback end");
}
void ts3plugin_onNewChannelEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 channelParentID){
	PyObject* function;
	logDebugFile("onNewChannelEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onNewChannelEvent lock held");
	function = PyDict_GetItemString(globalDict, "onNewChannelEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKK", serverConnectionHandlerID, channelID, channelParentID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onNewChannelEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onNewChannelEvent callback end");
}
void ts3plugin_onNewChannelCreatedEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 channelParentID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier){
	PyObject* function;
	logDebugFile("onNewChannelCreatedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onNewChannelCreatedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onNewChannelCreatedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKKiss", serverConnectionHandlerID, channelID, channelParentID, invokerID, invokerName, invokerUniqueIdentifier);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onNewChannelCreatedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onNewChannelCreatedEvent callback end");
}
void ts3plugin_onDelChannelEvent(uint64 serverConnectionHandlerID, uint64 channelID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier){
	PyObject* function;
	logDebugFile("onDelChannelEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onDelChannelEvent lock held");
	function = PyDict_GetItemString(globalDict, "onDelChannelEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKiss", serverConnectionHandlerID, channelID, invokerID, invokerName, invokerUniqueIdentifier);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onDelChannelEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onDelChannelEvent callback end");
}
void ts3plugin_onChannelMoveEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 newChannelParentID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier){
	PyObject* function;
	logDebugFile("onChannelMoveEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelMoveEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelMoveEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKKiss", serverConnectionHandlerID, channelID, newChannelParentID, invokerID, invokerName, invokerUniqueIdentifier);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelMoveEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelMoveEvent callback end");
}
void ts3plugin_onUpdateChannelEvent(uint64 serverConnectionHandlerID, uint64 channelID){
	PyObject* function;
	logDebugFile("onUpdateChannelEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onUpdateChannelEvent lock held");
	function = PyDict_GetItemString(globalDict, "onUpdateChannelEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, channelID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onUpdateChannelEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onUpdateChannelEvent callback end");
}
void ts3plugin_onUpdateChannelEditedEvent(uint64 serverConnectionHandlerID, uint64 channelID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier){
	PyObject* function;
	logDebugFile("onUpdateChannelEditedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onUpdateChannelEditedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onUpdateChannelEditedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKiss", serverConnectionHandlerID, channelID, invokerID, invokerName, invokerUniqueIdentifier);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onUpdateChannelEditedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onUpdateChannelEditedEvent callback end");
}
void ts3plugin_onUpdateClientEvent(uint64 serverConnectionHandlerID, anyID clientID){
	PyObject* function;
	logDebugFile("onUpdateClientEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onUpdateClientEvent lock held");
	function = PyDict_GetItemString(globalDict, "onUpdateClientEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ki", serverConnectionHandlerID, clientID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onUpdateClientEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onUpdateClientEvent callback end");
}
void ts3plugin_onClientMoveEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, const char* moveMessage){
	PyObject* function;
	logDebugFile("onClientMoveEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientMoveEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientMoveEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KiKKis", serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, moveMessage);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientMoveEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientMoveEvent callback end");
}
void ts3plugin_onClientMoveSubscriptionEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility){
	PyObject* function;
	logDebugFile("onClientMoveSubscriptionEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientMoveSubscriptionEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientMoveSubscriptionEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KiKKi", serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientMoveSubscriptionEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientMoveSubscriptionEvent callback end");
}
void ts3plugin_onClientMoveTimeoutEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, const char* timeoutMessage){
	PyObject* function;
	logDebugFile("onClientMoveTimeoutEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientMoveTimeoutEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientMoveTimeoutEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KiKKis", serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, timeoutMessage);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientMoveTimeoutEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientMoveTimeoutEvent callback end");
}
void ts3plugin_onClientMoveMovedEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID moverID, const char* moverName, const char* moverUniqueIdentifier, const char* moveMessage){
	PyObject* function;
	logDebugFile("onClientMoveMovedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientMoveMovedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientMoveMovedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KiKKiisss", serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, moverID, moverName, moverUniqueIdentifier, moveMessage);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientMoveMovedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientMoveMovedEvent callback end");
}
void ts3plugin_onClientKickFromChannelEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID kickerID, const char* kickerName, const char* kickerUniqueIdentifier, const char* kickMessage){
	PyObject* function;
	logDebugFile("onClientKickFromChannelEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientKickFromChannelEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientKickFromChannelEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KiKKiisss", serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, kickerID, kickerName, kickerUniqueIdentifier, kickMessage);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientKickFromChannelEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientKickFromChannelEvent callback end");
}
void ts3plugin_onClientKickFromServerEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID kickerID, const char* kickerName, const char* kickerUniqueIdentifier, const char* kickMessage){
	PyObject* function;
	logDebugFile("onClientKickFromServerEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientKickFromServerEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientKickFromServerEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KiKKiisss", serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, kickerID, kickerName, kickerUniqueIdentifier, kickMessage);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientKickFromServerEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientKickFromServerEvent callback end");
}
void ts3plugin_onServerEditedEvent(uint64 serverConnectionHandlerID, anyID editerID, const char* editerName, const char* editerUniqueIdentifier){
	PyObject* function;
	logDebugFile("onServerEditedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerEditedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerEditedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kiss", serverConnectionHandlerID, editerID, editerName, editerUniqueIdentifier);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerEditedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerEditedEvent callback end");
}
void ts3plugin_onServerUpdatedEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onServerUpdatedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerUpdatedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerUpdatedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerUpdatedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerUpdatedEvent callback end");
}
int ts3plugin_onServerErrorEvent(uint64 serverConnectionHandlerID, const char* errorMessage, unsigned int error, const char* returnCode, const char* extraMessage){
	PyObject* function;
	logDebugFile("onServerErrorEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerErrorEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerErrorEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ksiss", serverConnectionHandlerID, errorMessage, error, returnCode, extraMessage);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerErrorEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerErrorEvent callback end");
	 return 0;
}
void ts3plugin_onServerStopEvent(uint64 serverConnectionHandlerID, const char* shutdownMessage){
	PyObject* function;
	logDebugFile("onServerStopEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerStopEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerStopEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ks", serverConnectionHandlerID, shutdownMessage);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerStopEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerStopEvent callback end");
}
int ts3plugin_onTextMessageEvent(uint64 serverConnectionHandlerID, anyID targetMode, anyID toID, anyID fromID, const char* fromName, const char* fromUniqueIdentifier, const char* message, int ffIgnored){
	PyObject* function;
	logDebugFile("onTextMessageEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onTextMessageEvent lock held");
	function = PyDict_GetItemString(globalDict, "onTextMessageEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kiiisssi", serverConnectionHandlerID, targetMode, toID, fromID, fromName, fromUniqueIdentifier, message, ffIgnored);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onTextMessageEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onTextMessageEvent callback end");
	 return 0;
}
void ts3plugin_onTalkStatusChangeEvent(uint64 serverConnectionHandlerID, int status, int isReceivedWhisper, anyID clientID){
	PyObject* function;
	logDebugFile("onTalkStatusChangeEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onTalkStatusChangeEvent lock held");
	function = PyDict_GetItemString(globalDict, "onTalkStatusChangeEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kiii", serverConnectionHandlerID, status, isReceivedWhisper, clientID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onTalkStatusChangeEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onTalkStatusChangeEvent callback end");
}
void ts3plugin_onConnectionInfoEvent(uint64 serverConnectionHandlerID, anyID clientID){
	PyObject* function;
	logDebugFile("onConnectionInfoEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onConnectionInfoEvent lock held");
	function = PyDict_GetItemString(globalDict, "onConnectionInfoEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ki", serverConnectionHandlerID, clientID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onConnectionInfoEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onConnectionInfoEvent callback end");
}
void ts3plugin_onServerConnectionInfoEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onServerConnectionInfoEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerConnectionInfoEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerConnectionInfoEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerConnectionInfoEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerConnectionInfoEvent callback end");
}
void ts3plugin_onChannelSubscribeEvent(uint64 serverConnectionHandlerID, uint64 channelID){
	PyObject* function;
	logDebugFile("onChannelSubscribeEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelSubscribeEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelSubscribeEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, channelID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelSubscribeEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelSubscribeEvent callback end");
}
void ts3plugin_onChannelSubscribeFinishedEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onChannelSubscribeFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelSubscribeFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelSubscribeFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelSubscribeFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelSubscribeFinishedEvent callback end");
}
void ts3plugin_onChannelUnsubscribeEvent(uint64 serverConnectionHandlerID, uint64 channelID){
	PyObject* function;
	logDebugFile("onChannelUnsubscribeEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelUnsubscribeEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelUnsubscribeEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, channelID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelUnsubscribeEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelUnsubscribeEvent callback end");
}
void ts3plugin_onChannelUnsubscribeFinishedEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onChannelUnsubscribeFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelUnsubscribeFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelUnsubscribeFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelUnsubscribeFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelUnsubscribeFinishedEvent callback end");
}
void ts3plugin_onChannelDescriptionUpdateEvent(uint64 serverConnectionHandlerID, uint64 channelID){
	PyObject* function;
	logDebugFile("onChannelDescriptionUpdateEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelDescriptionUpdateEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelDescriptionUpdateEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, channelID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelDescriptionUpdateEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelDescriptionUpdateEvent callback end");
}
void ts3plugin_onChannelPasswordChangedEvent(uint64 serverConnectionHandlerID, uint64 channelID){
	PyObject* function;
	logDebugFile("onChannelPasswordChangedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelPasswordChangedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelPasswordChangedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, channelID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelPasswordChangedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelPasswordChangedEvent callback end");
}
void ts3plugin_onPlaybackShutdownCompleteEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onPlaybackShutdownCompleteEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onPlaybackShutdownCompleteEvent lock held");
	function = PyDict_GetItemString(globalDict, "onPlaybackShutdownCompleteEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onPlaybackShutdownCompleteEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onPlaybackShutdownCompleteEvent callback end");
}
void ts3plugin_onSoundDeviceListChangedEvent(const char* modeID, int playOrCap){
	PyObject* function;
	logDebugFile("onSoundDeviceListChangedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onSoundDeviceListChangedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onSoundDeviceListChangedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"si", modeID, playOrCap);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onSoundDeviceListChangedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onSoundDeviceListChangedEvent callback end");
}
void ts3plugin_onUserLoggingMessageEvent(const char* logMessage, int logLevel, const char* logChannel, uint64 logID, const char* logTime, const char* completeLogString){
	PyObject* function;
	logDebugFile("onUserLoggingMessageEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onUserLoggingMessageEvent lock held");
	function = PyDict_GetItemString(globalDict, "onUserLoggingMessageEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"sisKss", logMessage, logLevel, logChannel, logID, logTime, completeLogString);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onUserLoggingMessageEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onUserLoggingMessageEvent callback end");
}
void ts3plugin_onClientBanFromServerEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID kickerID, const char* kickerName, const char* kickerUniqueIdentifier, uint64 time, const char* kickMessage){
	PyObject* function;
	logDebugFile("onClientBanFromServerEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientBanFromServerEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientBanFromServerEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KiKKiissKs", serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, kickerID, kickerName, kickerUniqueIdentifier, time, kickMessage);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientBanFromServerEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientBanFromServerEvent callback end");
}
int ts3plugin_onClientPokeEvent(uint64 serverConnectionHandlerID, anyID fromClientID, const char* pokerName, const char* pokerUniqueIdentity, const char* message, int ffIgnored){
	PyObject* function;
	logDebugFile("onClientPokeEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientPokeEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientPokeEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kisssi", serverConnectionHandlerID, fromClientID, pokerName, pokerUniqueIdentity, message, ffIgnored);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientPokeEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientPokeEvent callback end");
	 return 0;
}
void ts3plugin_onClientSelfVariableUpdateEvent(uint64 serverConnectionHandlerID, int flag, const char* oldValue, const char* newValue){
	PyObject* function;
	logDebugFile("onClientSelfVariableUpdateEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientSelfVariableUpdateEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientSelfVariableUpdateEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kiss", serverConnectionHandlerID, flag, oldValue, newValue);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientSelfVariableUpdateEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientSelfVariableUpdateEvent callback end");
}
void ts3plugin_onFileListEvent(uint64 serverConnectionHandlerID, uint64 channelID, const char* path, const char* name, uint64 size, uint64 datetime, int type, uint64 incompletesize, const char* returnCode){
	PyObject* function;
	logDebugFile("onFileListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onFileListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onFileListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKssKKiKs", serverConnectionHandlerID, channelID, path, name, size, datetime, type, incompletesize, returnCode);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onFileListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onFileListEvent callback end");
}
void ts3plugin_onFileListFinishedEvent(uint64 serverConnectionHandlerID, uint64 channelID, const char* path){
	PyObject* function;
	logDebugFile("onFileListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onFileListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onFileListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKs", serverConnectionHandlerID, channelID, path);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onFileListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onFileListFinishedEvent callback end");
}
void ts3plugin_onFileInfoEvent(uint64 serverConnectionHandlerID, uint64 channelID, const char* name, uint64 size, uint64 datetime){
	PyObject* function;
	logDebugFile("onFileInfoEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onFileInfoEvent lock held");
	function = PyDict_GetItemString(globalDict, "onFileInfoEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKsKK", serverConnectionHandlerID, channelID, name, size, datetime);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onFileInfoEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onFileInfoEvent callback end");
}
void ts3plugin_onServerGroupListEvent(uint64 serverConnectionHandlerID, uint64 serverGroupID, const char* name, int type, int iconID, int saveDB){
	PyObject* function;
	logDebugFile("onServerGroupListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerGroupListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerGroupListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKsiii", serverConnectionHandlerID, serverGroupID, name, type, iconID, saveDB);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerGroupListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerGroupListEvent callback end");
}
void ts3plugin_onServerGroupListFinishedEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onServerGroupListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerGroupListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerGroupListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerGroupListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerGroupListFinishedEvent callback end");
}
void ts3plugin_onServerGroupByClientIDEvent(uint64 serverConnectionHandlerID, const char* name, uint64 serverGroupList, uint64 clientDatabaseID){
	PyObject* function;
	logDebugFile("onServerGroupByClientIDEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerGroupByClientIDEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerGroupByClientIDEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KsKK", serverConnectionHandlerID, name, serverGroupList, clientDatabaseID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerGroupByClientIDEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerGroupByClientIDEvent callback end");
}
void ts3plugin_onServerGroupPermListEvent(uint64 serverConnectionHandlerID, uint64 serverGroupID, anyID permissionID, int permissionValue, int permissionNegated, int permissionSkip){
	PyObject* function;
	logDebugFile("onServerGroupPermListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerGroupPermListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerGroupPermListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKiiii", serverConnectionHandlerID, serverGroupID, permissionID, permissionValue, permissionNegated, permissionSkip);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerGroupPermListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerGroupPermListEvent callback end");
}
void ts3plugin_onServerGroupPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 serverGroupID){
	PyObject* function;
	logDebugFile("onServerGroupPermListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerGroupPermListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerGroupPermListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, serverGroupID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerGroupPermListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerGroupPermListFinishedEvent callback end");
}
void ts3plugin_onServerGroupClientListEvent(uint64 serverConnectionHandlerID, uint64 serverGroupID, uint64 clientDatabaseID, const char* clientNameIdentifier, const char* clientUniqueID){
	PyObject* function;
	logDebugFile("onServerGroupClientListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerGroupClientListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerGroupClientListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKKss", serverConnectionHandlerID, serverGroupID, clientDatabaseID, clientNameIdentifier, clientUniqueID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerGroupClientListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerGroupClientListEvent callback end");
}
void ts3plugin_onChannelGroupListEvent(uint64 serverConnectionHandlerID, uint64 channelGroupID, const char* name, int type, int iconID, int saveDB){
	PyObject* function;
	logDebugFile("onChannelGroupListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelGroupListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelGroupListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKsiii", serverConnectionHandlerID, channelGroupID, name, type, iconID, saveDB);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelGroupListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelGroupListEvent callback end");
}
void ts3plugin_onChannelGroupListFinishedEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onChannelGroupListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelGroupListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelGroupListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelGroupListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelGroupListFinishedEvent callback end");
}
void ts3plugin_onChannelGroupPermListEvent(uint64 serverConnectionHandlerID, uint64 channelGroupID, anyID permissionID, int permissionValue, int permissionNegated, int permissionSkip){
	PyObject* function;
	logDebugFile("onChannelGroupPermListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelGroupPermListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelGroupPermListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKiiii", serverConnectionHandlerID, channelGroupID, permissionID, permissionValue, permissionNegated, permissionSkip);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelGroupPermListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelGroupPermListEvent callback end");
}
void ts3plugin_onChannelGroupPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 channelGroupID){
	PyObject* function;
	logDebugFile("onChannelGroupPermListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelGroupPermListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelGroupPermListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, channelGroupID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelGroupPermListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelGroupPermListFinishedEvent callback end");
}
void ts3plugin_onChannelPermListEvent(uint64 serverConnectionHandlerID, uint64 channelID, anyID permissionID, int permissionValue, int permissionNegated, int permissionSkip){
	PyObject* function;
	logDebugFile("onChannelPermListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelPermListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelPermListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKiiii", serverConnectionHandlerID, channelID, permissionID, permissionValue, permissionNegated, permissionSkip);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelPermListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelPermListEvent callback end");
}
void ts3plugin_onChannelPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 channelID){
	PyObject* function;
	logDebugFile("onChannelPermListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelPermListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelPermListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, channelID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelPermListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelPermListFinishedEvent callback end");
}
void ts3plugin_onClientPermListEvent(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, anyID permissionID, int permissionValue, int permissionNegated, int permissionSkip){
	PyObject* function;
	logDebugFile("onClientPermListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientPermListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientPermListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKiiii", serverConnectionHandlerID, clientDatabaseID, permissionID, permissionValue, permissionNegated, permissionSkip);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientPermListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientPermListEvent callback end");
}
void ts3plugin_onClientPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 clientDatabaseID){
	PyObject* function;
	logDebugFile("onClientPermListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientPermListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientPermListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KK", serverConnectionHandlerID, clientDatabaseID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientPermListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientPermListFinishedEvent callback end");
}
void ts3plugin_onChannelClientPermListEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 clientDatabaseID, anyID permissionID, int permissionValue, int permissionNegated, int permissionSkip){
	PyObject* function;
	logDebugFile("onChannelClientPermListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelClientPermListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelClientPermListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKKiiii", serverConnectionHandlerID, channelID, clientDatabaseID, permissionID, permissionValue, permissionNegated, permissionSkip);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelClientPermListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelClientPermListEvent callback end");
}
void ts3plugin_onChannelClientPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 clientDatabaseID){
	PyObject* function;
	logDebugFile("onChannelClientPermListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onChannelClientPermListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onChannelClientPermListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKK", serverConnectionHandlerID, channelID, clientDatabaseID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onChannelClientPermListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onChannelClientPermListFinishedEvent callback end");
}
void ts3plugin_onClientChannelGroupChangedEvent(uint64 serverConnectionHandlerID, uint64 channelGroupID, uint64 channelID, anyID clientID, anyID invokerClientID, const char* invokerName, const char* invokerUniqueIdentity){
	PyObject* function;
	logDebugFile("onClientChannelGroupChangedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientChannelGroupChangedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientChannelGroupChangedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKKiiss", serverConnectionHandlerID, channelGroupID, channelID, clientID, invokerClientID, invokerName, invokerUniqueIdentity);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientChannelGroupChangedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientChannelGroupChangedEvent callback end");
}
int ts3plugin_onServerPermissionErrorEvent(uint64 serverConnectionHandlerID, const char* errorMessage, unsigned int error, const char* returnCode, anyID failedPermissionID){
	PyObject* function;
	logDebugFile("onServerPermissionErrorEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerPermissionErrorEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerPermissionErrorEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ksisi", serverConnectionHandlerID, errorMessage, error, returnCode, failedPermissionID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerPermissionErrorEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerPermissionErrorEvent callback end");
	 return 0;
}
void ts3plugin_onPermissionListEvent(uint64 serverConnectionHandlerID, anyID permissionID, const char* permissionName, const char* permissionDescription){
	PyObject* function;
	logDebugFile("onPermissionListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onPermissionListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onPermissionListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kiss", serverConnectionHandlerID, permissionID, permissionName, permissionDescription);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onPermissionListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onPermissionListEvent callback end");
}
void ts3plugin_onPermissionListFinishedEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onPermissionListFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onPermissionListFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onPermissionListFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onPermissionListFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onPermissionListFinishedEvent callback end");
}
void ts3plugin_onPermissionOverviewEvent(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, uint64 channelID, int overviewType, uint64 overviewID1, uint64 overviewID2, anyID permissionID, int permissionValue, int permissionNegated, int permissionSkip){
	PyObject* function;
	logDebugFile("onPermissionOverviewEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onPermissionOverviewEvent lock held");
	function = PyDict_GetItemString(globalDict, "onPermissionOverviewEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKKiKKiiii", serverConnectionHandlerID, clientDatabaseID, channelID, overviewType, overviewID1, overviewID2, permissionID, permissionValue, permissionNegated, permissionSkip);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onPermissionOverviewEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onPermissionOverviewEvent callback end");
}
void ts3plugin_onPermissionOverviewFinishedEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onPermissionOverviewFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onPermissionOverviewFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onPermissionOverviewFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onPermissionOverviewFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onPermissionOverviewFinishedEvent callback end");
}
void ts3plugin_onServerGroupClientAddedEvent(uint64 serverConnectionHandlerID, anyID clientID, const char* clientName, const char* clientUniqueIdentity, uint64 serverGroupID, anyID invokerClientID, const char* invokerName, const char* invokerUniqueIdentity){
	PyObject* function;
	logDebugFile("onServerGroupClientAddedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerGroupClientAddedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerGroupClientAddedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KissKiss", serverConnectionHandlerID, clientID, clientName, clientUniqueIdentity, serverGroupID, invokerClientID, invokerName, invokerUniqueIdentity);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerGroupClientAddedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerGroupClientAddedEvent callback end");
}
void ts3plugin_onServerGroupClientDeletedEvent(uint64 serverConnectionHandlerID, anyID clientID, const char* clientName, const char* clientUniqueIdentity, uint64 serverGroupID, anyID invokerClientID, const char* invokerName, const char* invokerUniqueIdentity){
	PyObject* function;
	logDebugFile("onServerGroupClientDeletedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerGroupClientDeletedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerGroupClientDeletedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KissKiss", serverConnectionHandlerID, clientID, clientName, clientUniqueIdentity, serverGroupID, invokerClientID, invokerName, invokerUniqueIdentity);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerGroupClientDeletedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerGroupClientDeletedEvent callback end");
}
void ts3plugin_onClientNeededPermissionsEvent(uint64 serverConnectionHandlerID, anyID permissionID, int permissionValue){
	PyObject* function;
	logDebugFile("onClientNeededPermissionsEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientNeededPermissionsEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientNeededPermissionsEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kii", serverConnectionHandlerID, permissionID, permissionValue);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientNeededPermissionsEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientNeededPermissionsEvent callback end");
}
void ts3plugin_onClientNeededPermissionsFinishedEvent(uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onClientNeededPermissionsFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientNeededPermissionsFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientNeededPermissionsFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"K", serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientNeededPermissionsFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientNeededPermissionsFinishedEvent callback end");
}
void ts3plugin_onFileTransferStatusEvent(anyID transferID, unsigned int status, const char* statusMessage, uint64 remotefileSize, uint64 serverConnectionHandlerID){
	PyObject* function;
	logDebugFile("onFileTransferStatusEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onFileTransferStatusEvent lock held");
	function = PyDict_GetItemString(globalDict, "onFileTransferStatusEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"iisKK", transferID, status, statusMessage, remotefileSize, serverConnectionHandlerID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onFileTransferStatusEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onFileTransferStatusEvent callback end");
}
void ts3plugin_onClientChatClosedEvent(uint64 serverConnectionHandlerID, anyID clientID, const char* clientUniqueIdentity){
	PyObject* function;
	logDebugFile("onClientChatClosedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientChatClosedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientChatClosedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kis", serverConnectionHandlerID, clientID, clientUniqueIdentity);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientChatClosedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientChatClosedEvent callback end");
}
void ts3plugin_onClientChatComposingEvent(uint64 serverConnectionHandlerID, anyID clientID, const char* clientUniqueIdentity){
	PyObject* function;
	logDebugFile("onClientChatComposingEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientChatComposingEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientChatComposingEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kis", serverConnectionHandlerID, clientID, clientUniqueIdentity);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientChatComposingEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientChatComposingEvent callback end");
}
void ts3plugin_onServerLogEvent(uint64 serverConnectionHandlerID, const char* logMsg){
	PyObject* function;
	logDebugFile("onServerLogEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerLogEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerLogEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ks", serverConnectionHandlerID, logMsg);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerLogEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerLogEvent callback end");
}
void ts3plugin_onServerLogFinishedEvent(uint64 serverConnectionHandlerID, uint64 lastPos, uint64 fileSize){
	PyObject* function;
	logDebugFile("onServerLogFinishedEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerLogFinishedEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerLogFinishedEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKK", serverConnectionHandlerID, lastPos, fileSize);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerLogFinishedEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerLogFinishedEvent callback end");
}
void ts3plugin_onServerQueryEvent(uint64 serverConnectionHandlerID, const char* result){
	PyObject* function;
	logDebugFile("onServerQueryEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onServerQueryEvent lock held");
	function = PyDict_GetItemString(globalDict, "onServerQueryEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ks", serverConnectionHandlerID, result);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onServerQueryEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onServerQueryEvent callback end");
}
void ts3plugin_onMessageListEvent(uint64 serverConnectionHandlerID, uint64 messageID, const char* fromClientUniqueIdentity, const char* subject, uint64 timestamp, int flagRead){
	PyObject* function;
	logDebugFile("onMessageListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onMessageListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onMessageListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKssKi", serverConnectionHandlerID, messageID, fromClientUniqueIdentity, subject, timestamp, flagRead);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onMessageListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onMessageListEvent callback end");
}
void ts3plugin_onMessageGetEvent(uint64 serverConnectionHandlerID, uint64 messageID, const char* fromClientUniqueIdentity, const char* subject, const char* message, uint64 timestamp){
	PyObject* function;
	logDebugFile("onMessageGetEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onMessageGetEvent lock held");
	function = PyDict_GetItemString(globalDict, "onMessageGetEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKsssK", serverConnectionHandlerID, messageID, fromClientUniqueIdentity, subject, message, timestamp);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onMessageGetEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onMessageGetEvent callback end");
}
void ts3plugin_onClientDBIDfromUIDEvent(uint64 serverConnectionHandlerID, const char* uniqueClientIdentifier, uint64 clientDatabaseID){
	PyObject* function;
	logDebugFile("onClientDBIDfromUIDEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientDBIDfromUIDEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientDBIDfromUIDEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KsK", serverConnectionHandlerID, uniqueClientIdentifier, clientDatabaseID);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientDBIDfromUIDEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientDBIDfromUIDEvent callback end");
}
void ts3plugin_onClientNamefromUIDEvent(uint64 serverConnectionHandlerID, const char* uniqueClientIdentifier, uint64 clientDatabaseID, const char* clientNickName){
	PyObject* function;
	logDebugFile("onClientNamefromUIDEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientNamefromUIDEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientNamefromUIDEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KsKs", serverConnectionHandlerID, uniqueClientIdentifier, clientDatabaseID, clientNickName);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientNamefromUIDEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientNamefromUIDEvent callback end");
}
void ts3plugin_onClientNamefromDBIDEvent(uint64 serverConnectionHandlerID, const char* uniqueClientIdentifier, uint64 clientDatabaseID, const char* clientNickName){
	PyObject* function;
	logDebugFile("onClientNamefromDBIDEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientNamefromDBIDEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientNamefromDBIDEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KsKs", serverConnectionHandlerID, uniqueClientIdentifier, clientDatabaseID, clientNickName);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientNamefromDBIDEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientNamefromDBIDEvent callback end");
}
void ts3plugin_onComplainListEvent(uint64 serverConnectionHandlerID, uint64 targetClientDatabaseID, const char* targetClientNickName, uint64 fromClientDatabaseID, const char* fromClientNickName, const char* complainReason, uint64 timestamp){
	PyObject* function;
	logDebugFile("onComplainListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onComplainListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onComplainListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKsKssK", serverConnectionHandlerID, targetClientDatabaseID, targetClientNickName, fromClientDatabaseID, fromClientNickName, complainReason, timestamp);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onComplainListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onComplainListEvent callback end");
}
void ts3plugin_onBanListEvent(uint64 serverConnectionHandlerID, uint64 banid, const char* ip, const char* name, const char* uid, uint64 creationTime, uint64 durationTime, const char* invokerName, uint64 invokercldbid, const char* invokeruid, const char* reason, int numberOfEnforcements, const char* lastNickName){
	PyObject* function;
	logDebugFile("onBanListEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onBanListEvent lock held");
	function = PyDict_GetItemString(globalDict, "onBanListEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"KKsssKKsKssis", serverConnectionHandlerID, banid, ip, name, uid, creationTime, durationTime, invokerName, invokercldbid, invokeruid, reason, numberOfEnforcements, lastNickName);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onBanListEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onBanListEvent callback end");
}
void ts3plugin_onClientServerQueryLoginPasswordEvent(uint64 serverConnectionHandlerID, const char* loginPassword){
	PyObject* function;
	logDebugFile("onClientServerQueryLoginPasswordEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onClientServerQueryLoginPasswordEvent lock held");
	function = PyDict_GetItemString(globalDict, "onClientServerQueryLoginPasswordEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ks", serverConnectionHandlerID, loginPassword);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onClientServerQueryLoginPasswordEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onClientServerQueryLoginPasswordEvent callback end");
}
void ts3plugin_onPluginCommandEvent(uint64 serverConnectionHandlerID, const char* pluginName, const char* pluginCommand){
	PyObject* function;
	logDebugFile("onPluginCommandEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onPluginCommandEvent lock held");
	function = PyDict_GetItemString(globalDict, "onPluginCommandEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kss", serverConnectionHandlerID, pluginName, pluginCommand);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onPluginCommandEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onPluginCommandEvent callback end");
}
void ts3plugin_onIncomingClientQueryEvent(uint64 serverConnectionHandlerID, const char* commandText){
	PyObject* function;
	logDebugFile("onIncomingClientQueryEvent callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onIncomingClientQueryEvent lock held");
	function = PyDict_GetItemString(globalDict, "onIncomingClientQueryEvent");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ks", serverConnectionHandlerID, commandText);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onIncomingClientQueryEvent lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onIncomingClientQueryEvent callback end");
}
void ts3plugin_onAvatarUpdated(uint64 serverConnectionHandlerID, anyID clientID, const char* avatarPath){
	PyObject* function;
	logDebugFile("onAvatarUpdated callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("onAvatarUpdated lock held");
	function = PyDict_GetItemString(globalDict, "onAvatarUpdated");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Kis", serverConnectionHandlerID, clientID, avatarPath);
		Py_XDECREF(returnValue);
	}
	logDebugFile("onAvatarUpdated lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("onAvatarUpdated callback end");
}
