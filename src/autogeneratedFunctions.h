static PyObject * getClientLibVersion(PyObject *self, PyObject *args)
{
	char* result;
	logDebugFile("Called function getClientLibVersion");
	if(ts3Functions.getClientLibVersion(&result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * getClientLibVersionNumber(PyObject *self, PyObject *args)
{
	uint64 result;
	logDebugFile("Called function getClientLibVersionNumber");
	if(ts3Functions.getClientLibVersionNumber(&result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * spawnNewServerConnectionHandler(PyObject *self, PyObject *args)
{
	int port;
	uint64 result;
	logDebugFile("Called function spawnNewServerConnectionHandler");
	if (!PyArg_ParseTuple(args, "i", &port))
		return NULL;
	if(ts3Functions.spawnNewServerConnectionHandler(port, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * destroyServerConnectionHandler(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	logDebugFile("Called function destroyServerConnectionHandler");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.destroyServerConnectionHandler(serverConnectionHandlerID);
	return Py_None;
}
static PyObject * logMessage(PyObject *self, PyObject *args)
{
	const char* logMessage;
	enum LogLevel severity;
	const char* channel;
	uint64 logID;
	logDebugFile("Called function logMessage");
	if (!PyArg_ParseTuple(args, "sisK", &logMessage, &severity, &channel, &logID))
		return NULL;
	ts3Functions.logMessage(logMessage, severity, channel, logID);
	return Py_None;
}
static PyObject * getDefaultPlayBackMode(PyObject *self, PyObject *args)
{
	char* result;
	logDebugFile("Called function getDefaultPlayBackMode");
	if(ts3Functions.getDefaultPlayBackMode(&result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * getDefaultCaptureMode(PyObject *self, PyObject *args)
{
	char* result;
	logDebugFile("Called function getDefaultCaptureMode");
	if(ts3Functions.getDefaultCaptureMode(&result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * openPlaybackDevice(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* modeID;
	const char* playbackDevice;
	logDebugFile("Called function openPlaybackDevice");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &modeID, &playbackDevice))
		return NULL;
	ts3Functions.openPlaybackDevice(serverConnectionHandlerID, modeID, playbackDevice);
	return Py_None;
}
static PyObject * openCaptureDevice(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* modeID;
	const char* captureDevice;
	logDebugFile("Called function openCaptureDevice");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &modeID, &captureDevice))
		return NULL;
	ts3Functions.openCaptureDevice(serverConnectionHandlerID, modeID, captureDevice);
	return Py_None;
}
static PyObject * getCurrentPlayBackMode(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	char* result;
	logDebugFile("Called function getCurrentPlayBackMode");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	if(ts3Functions.getCurrentPlayBackMode(serverConnectionHandlerID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * getCurrentCaptureMode(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	char* result;
	logDebugFile("Called function getCurrentCaptureMode");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	if(ts3Functions.getCurrentCaptureMode(serverConnectionHandlerID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * initiateGracefulPlaybackShutdown(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	logDebugFile("Called function initiateGracefulPlaybackShutdown");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.initiateGracefulPlaybackShutdown(serverConnectionHandlerID);
	return Py_None;
}
static PyObject * closePlaybackDevice(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	logDebugFile("Called function closePlaybackDevice");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.closePlaybackDevice(serverConnectionHandlerID);
	return Py_None;
}
static PyObject * closeCaptureDevice(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	logDebugFile("Called function closeCaptureDevice");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.closeCaptureDevice(serverConnectionHandlerID);
	return Py_None;
}
static PyObject * activateCaptureDevice(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	logDebugFile("Called function activateCaptureDevice");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.activateCaptureDevice(serverConnectionHandlerID);
	return Py_None;
}
static PyObject * playWaveFileHandle(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* path;
	int loop;
	uint64 waveHandle;
	logDebugFile("Called function playWaveFileHandle");
	if (!PyArg_ParseTuple(args, "Ksi", &serverConnectionHandlerID, &path, &loop))
		return NULL;
	if(ts3Functions.playWaveFileHandle(serverConnectionHandlerID, path, loop, &waveHandle) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",waveHandle);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * pauseWaveFileHandle(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 waveHandle;
	int pause;
	logDebugFile("Called function pauseWaveFileHandle");
	if (!PyArg_ParseTuple(args, "KKi", &serverConnectionHandlerID, &waveHandle, &pause))
		return NULL;
	ts3Functions.pauseWaveFileHandle(serverConnectionHandlerID, waveHandle, pause);
	return Py_None;
}
static PyObject * closeWaveFileHandle(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 waveHandle;
	logDebugFile("Called function closeWaveFileHandle");
	if (!PyArg_ParseTuple(args, "KK", &serverConnectionHandlerID, &waveHandle))
		return NULL;
	ts3Functions.closeWaveFileHandle(serverConnectionHandlerID, waveHandle);
	return Py_None;
}
static PyObject * playWaveFile(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* path;
	logDebugFile("Called function playWaveFile");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &path))
		return NULL;
	ts3Functions.playWaveFile(serverConnectionHandlerID, path);
	return Py_None;
}
static PyObject * registerCustomDevice(PyObject *self, PyObject *args)
{
	const char* deviceID;
	const char* deviceDisplayName;
	int capFrequency;
	int capChannels;
	int playFrequency;
	int playChannels;
	logDebugFile("Called function registerCustomDevice");
	if (!PyArg_ParseTuple(args, "ssiiii", &deviceID, &deviceDisplayName, &capFrequency, &capChannels, &playFrequency, &playChannels))
		return NULL;
	ts3Functions.registerCustomDevice(deviceID, deviceDisplayName, capFrequency, capChannels, playFrequency, playChannels);
	return Py_None;
}
static PyObject * unregisterCustomDevice(PyObject *self, PyObject *args)
{
	const char* deviceID;
	logDebugFile("Called function unregisterCustomDevice");
	if (!PyArg_ParseTuple(args, "s", &deviceID))
		return NULL;
	ts3Functions.unregisterCustomDevice(deviceID);
	return Py_None;
}
static PyObject * getPreProcessorConfigValue(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* ident;
	char* result;
	logDebugFile("Called function getPreProcessorConfigValue");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &ident))
		return NULL;
	if(ts3Functions.getPreProcessorConfigValue(serverConnectionHandlerID, ident, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * setPreProcessorConfigValue(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* ident;
	const char* value;
	logDebugFile("Called function setPreProcessorConfigValue");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &ident, &value))
		return NULL;
	ts3Functions.setPreProcessorConfigValue(serverConnectionHandlerID, ident, value);
	return Py_None;
}
static PyObject * getEncodeConfigValue(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* ident;
	char* result;
	logDebugFile("Called function getEncodeConfigValue");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &ident))
		return NULL;
	if(ts3Functions.getEncodeConfigValue(serverConnectionHandlerID, ident, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * setPlaybackConfigValue(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* ident;
	const char* value;
	logDebugFile("Called function setPlaybackConfigValue");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &ident, &value))
		return NULL;
	ts3Functions.setPlaybackConfigValue(serverConnectionHandlerID, ident, value);
	return Py_None;
}
static PyObject * startVoiceRecording(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	logDebugFile("Called function startVoiceRecording");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.startVoiceRecording(serverConnectionHandlerID);
	return Py_None;
}
static PyObject * stopVoiceRecording(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	logDebugFile("Called function stopVoiceRecording");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.stopVoiceRecording(serverConnectionHandlerID);
	return Py_None;
}
static PyObject * stopConnection(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* quitMessage;
	logDebugFile("Called function stopConnection");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &quitMessage))
		return NULL;
	ts3Functions.stopConnection(serverConnectionHandlerID, quitMessage);
	return Py_None;
}
static PyObject * requestClientMove(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	uint64 newChannelID;
	const char* password;
	const char* returnCode;
	logDebugFile("Called function requestClientMove");
	if (!PyArg_ParseTuple(args, "KiKss", &serverConnectionHandlerID, &clientID, &newChannelID, &password, &returnCode))
		return NULL;
	ts3Functions.requestClientMove(serverConnectionHandlerID, clientID, newChannelID, password, returnCode);
	return Py_None;
}
static PyObject * requestClientVariables(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* returnCode;
	logDebugFile("Called function requestClientVariables");
	if (!PyArg_ParseTuple(args, "Kis", &serverConnectionHandlerID, &clientID, &returnCode))
		return NULL;
	ts3Functions.requestClientVariables(serverConnectionHandlerID, clientID, returnCode);
	return Py_None;
}
static PyObject * requestClientKickFromChannel(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* kickReason;
	const char* returnCode;
	logDebugFile("Called function requestClientKickFromChannel");
	if (!PyArg_ParseTuple(args, "Kiss", &serverConnectionHandlerID, &clientID, &kickReason, &returnCode))
		return NULL;
	ts3Functions.requestClientKickFromChannel(serverConnectionHandlerID, clientID, kickReason, returnCode);
	return Py_None;
}
static PyObject * requestClientKickFromServer(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* kickReason;
	const char* returnCode;
	logDebugFile("Called function requestClientKickFromServer");
	if (!PyArg_ParseTuple(args, "Kiss", &serverConnectionHandlerID, &clientID, &kickReason, &returnCode))
		return NULL;
	ts3Functions.requestClientKickFromServer(serverConnectionHandlerID, clientID, kickReason, returnCode);
	return Py_None;
}
static PyObject * requestChannelDelete(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	int force;
	const char* returnCode;
	logDebugFile("Called function requestChannelDelete");
	if (!PyArg_ParseTuple(args, "KKis", &serverConnectionHandlerID, &channelID, &force, &returnCode))
		return NULL;
	ts3Functions.requestChannelDelete(serverConnectionHandlerID, channelID, force, returnCode);
	return Py_None;
}
static PyObject * requestChannelMove(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	uint64 newChannelParentID;
	uint64 newChannelOrder;
	const char* returnCode;
	logDebugFile("Called function requestChannelMove");
	if (!PyArg_ParseTuple(args, "KKKKs", &serverConnectionHandlerID, &channelID, &newChannelParentID, &newChannelOrder, &returnCode))
		return NULL;
	ts3Functions.requestChannelMove(serverConnectionHandlerID, channelID, newChannelParentID, newChannelOrder, returnCode);
	return Py_None;
}
static PyObject * requestSendPrivateTextMsg(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* message;
	anyID targetClientID;
	const char* returnCode;
	logDebugFile("Called function requestSendPrivateTextMsg");
	if (!PyArg_ParseTuple(args, "Ksis", &serverConnectionHandlerID, &message, &targetClientID, &returnCode))
		return NULL;
	ts3Functions.requestSendPrivateTextMsg(serverConnectionHandlerID, message, targetClientID, returnCode);
	return Py_None;
}
static PyObject * requestSendChannelTextMsg(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* message;
	uint64 targetChannelID;
	const char* returnCode;
	logDebugFile("Called function requestSendChannelTextMsg");
	if (!PyArg_ParseTuple(args, "KsKs", &serverConnectionHandlerID, &message, &targetChannelID, &returnCode))
		return NULL;
	ts3Functions.requestSendChannelTextMsg(serverConnectionHandlerID, message, targetChannelID, returnCode);
	return Py_None;
}
static PyObject * requestSendServerTextMsg(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* message;
	const char* returnCode;
	logDebugFile("Called function requestSendServerTextMsg");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &message, &returnCode))
		return NULL;
	ts3Functions.requestSendServerTextMsg(serverConnectionHandlerID, message, returnCode);
	return Py_None;
}
static PyObject * requestConnectionInfo(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* returnCode;
	logDebugFile("Called function requestConnectionInfo");
	if (!PyArg_ParseTuple(args, "Kis", &serverConnectionHandlerID, &clientID, &returnCode))
		return NULL;
	ts3Functions.requestConnectionInfo(serverConnectionHandlerID, clientID, returnCode);
	return Py_None;
}
static PyObject * requestChannelSubscribeAll(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	logDebugFile("Called function requestChannelSubscribeAll");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &returnCode))
		return NULL;
	ts3Functions.requestChannelSubscribeAll(serverConnectionHandlerID, returnCode);
	return Py_None;
}
static PyObject * requestChannelUnsubscribeAll(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	logDebugFile("Called function requestChannelUnsubscribeAll");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &returnCode))
		return NULL;
	ts3Functions.requestChannelUnsubscribeAll(serverConnectionHandlerID, returnCode);
	return Py_None;
}
static PyObject * requestChannelDescription(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* returnCode;
	logDebugFile("Called function requestChannelDescription");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &channelID, &returnCode))
		return NULL;
	ts3Functions.requestChannelDescription(serverConnectionHandlerID, channelID, returnCode);
	return Py_None;
}
static PyObject * requestClientPoke(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* message;
	const char* returnCode;
	logDebugFile("Called function requestClientPoke");
	if (!PyArg_ParseTuple(args, "Kiss", &serverConnectionHandlerID, &clientID, &message, &returnCode))
		return NULL;
	ts3Functions.requestClientPoke(serverConnectionHandlerID, clientID, message, returnCode);
	return Py_None;
}
static PyObject * clientChatClosed(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* clientUniqueIdentifier;
	anyID clientID;
	const char* returnCode;
	logDebugFile("Called function clientChatClosed");
	if (!PyArg_ParseTuple(args, "Ksis", &serverConnectionHandlerID, &clientUniqueIdentifier, &clientID, &returnCode))
		return NULL;
	ts3Functions.clientChatClosed(serverConnectionHandlerID, clientUniqueIdentifier, clientID, returnCode);
	return Py_None;
}
static PyObject * clientChatComposing(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* returnCode;
	logDebugFile("Called function clientChatComposing");
	if (!PyArg_ParseTuple(args, "Kis", &serverConnectionHandlerID, &clientID, &returnCode))
		return NULL;
	ts3Functions.clientChatComposing(serverConnectionHandlerID, clientID, returnCode);
	return Py_None;
}
static PyObject * getClientSelfVariableAsInt(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	size_t flag;
	int result;
	logDebugFile("Called function getClientSelfVariableAsInt");
	if (!PyArg_ParseTuple(args, "Ki", &serverConnectionHandlerID, &flag))
		return NULL;
	if(ts3Functions.getClientSelfVariableAsInt(serverConnectionHandlerID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getClientSelfVariableAsString(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	size_t flag;
	char* result;
	logDebugFile("Called function getClientSelfVariableAsString");
	if (!PyArg_ParseTuple(args, "Ki", &serverConnectionHandlerID, &flag))
		return NULL;
	if(ts3Functions.getClientSelfVariableAsString(serverConnectionHandlerID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * setClientSelfVariableAsInt(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	size_t flag;
	int value;
	logDebugFile("Called function setClientSelfVariableAsInt");
	if (!PyArg_ParseTuple(args, "Kii", &serverConnectionHandlerID, &flag, &value))
		return NULL;
	ts3Functions.setClientSelfVariableAsInt(serverConnectionHandlerID, flag, value);
	return Py_None;
}
static PyObject * setClientSelfVariableAsString(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	size_t flag;
	const char* value;
	logDebugFile("Called function setClientSelfVariableAsString");
	if (!PyArg_ParseTuple(args, "Kis", &serverConnectionHandlerID, &flag, &value))
		return NULL;
	ts3Functions.setClientSelfVariableAsString(serverConnectionHandlerID, flag, value);
	return Py_None;
}
static PyObject * flushClientSelfUpdates(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	logDebugFile("Called function flushClientSelfUpdates");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &returnCode))
		return NULL;
	ts3Functions.flushClientSelfUpdates(serverConnectionHandlerID, returnCode);
	return Py_None;
}
static PyObject * getClientVariableAsInt(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	int result;
	logDebugFile("Called function getClientVariableAsInt");
	if (!PyArg_ParseTuple(args, "Kii", &serverConnectionHandlerID, &clientID, &flag))
		return NULL;
	if(ts3Functions.getClientVariableAsInt(serverConnectionHandlerID, clientID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getClientVariableAsUInt64(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	uint64 result;
	logDebugFile("Called function getClientVariableAsUInt64");
	if (!PyArg_ParseTuple(args, "Kii", &serverConnectionHandlerID, &clientID, &flag))
		return NULL;
	if(ts3Functions.getClientVariableAsUInt64(serverConnectionHandlerID, clientID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getClientVariableAsString(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	char* result;
	logDebugFile("Called function getClientVariableAsString");
	if (!PyArg_ParseTuple(args, "Kii", &serverConnectionHandlerID, &clientID, &flag))
		return NULL;
	if(ts3Functions.getClientVariableAsString(serverConnectionHandlerID, clientID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * getClientList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID* result;
	logDebugFile("Called function getClientList");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	if(ts3Functions.getClientList(serverConnectionHandlerID, &result) == ERROR_ok) {
		int i;
		PyObject* returnValue = PyList_New(0);
		for(i=0; result[i]!=0; i++){
			PyList_Append(returnValue, Py_BuildValue("i",result[i]));
		}
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * getChannelOfClient(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	uint64 result;
	logDebugFile("Called function getChannelOfClient");
	if (!PyArg_ParseTuple(args, "Ki", &serverConnectionHandlerID, &clientID))
		return NULL;
	if(ts3Functions.getChannelOfClient(serverConnectionHandlerID, clientID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getChannelVariableAsInt(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	int result;
	logDebugFile("Called function getChannelVariableAsInt");
	if (!PyArg_ParseTuple(args, "KKi", &serverConnectionHandlerID, &channelID, &flag))
		return NULL;
	if(ts3Functions.getChannelVariableAsInt(serverConnectionHandlerID, channelID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getChannelVariableAsUInt64(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	uint64 result;
	logDebugFile("Called function getChannelVariableAsUInt64");
	if (!PyArg_ParseTuple(args, "KKi", &serverConnectionHandlerID, &channelID, &flag))
		return NULL;
	if(ts3Functions.getChannelVariableAsUInt64(serverConnectionHandlerID, channelID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getChannelVariableAsString(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	char* result;
	logDebugFile("Called function getChannelVariableAsString");
	if (!PyArg_ParseTuple(args, "KKi", &serverConnectionHandlerID, &channelID, &flag))
		return NULL;
	if(ts3Functions.getChannelVariableAsString(serverConnectionHandlerID, channelID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * setChannelVariableAsInt(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	int value;
	logDebugFile("Called function setChannelVariableAsInt");
	if (!PyArg_ParseTuple(args, "KKii", &serverConnectionHandlerID, &channelID, &flag, &value))
		return NULL;
	ts3Functions.setChannelVariableAsInt(serverConnectionHandlerID, channelID, flag, value);
	return Py_None;
}
static PyObject * setChannelVariableAsUInt64(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	uint64 value;
	logDebugFile("Called function setChannelVariableAsUInt64");
	if (!PyArg_ParseTuple(args, "KKiK", &serverConnectionHandlerID, &channelID, &flag, &value))
		return NULL;
	ts3Functions.setChannelVariableAsUInt64(serverConnectionHandlerID, channelID, flag, value);
	return Py_None;
}
static PyObject * setChannelVariableAsString(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	const char* value;
	logDebugFile("Called function setChannelVariableAsString");
	if (!PyArg_ParseTuple(args, "KKis", &serverConnectionHandlerID, &channelID, &flag, &value))
		return NULL;
	ts3Functions.setChannelVariableAsString(serverConnectionHandlerID, channelID, flag, value);
	return Py_None;
}
static PyObject * flushChannelUpdates(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	logDebugFile("Called function flushChannelUpdates");
	if (!PyArg_ParseTuple(args, "KK", &serverConnectionHandlerID, &channelID))
		return NULL;
	ts3Functions.flushChannelUpdates(serverConnectionHandlerID, channelID, "");
	return Py_None;
}
static PyObject * flushChannelCreation(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelParentID;
	logDebugFile("Called function flushChannelCreation");
	if (!PyArg_ParseTuple(args, "KK", &serverConnectionHandlerID, &channelParentID))
		return NULL;
	ts3Functions.flushChannelCreation(serverConnectionHandlerID, channelParentID, "");
	return Py_None;
}
static PyObject * getChannelClientList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	anyID* result;
	logDebugFile("Called function getChannelClientList");
	if (!PyArg_ParseTuple(args, "KK", &serverConnectionHandlerID, &channelID))
		return NULL;
	if(ts3Functions.getChannelClientList(serverConnectionHandlerID, channelID, &result) == ERROR_ok) {
		int i;
		PyObject* returnValue = PyList_New(0);
		for(i=0; result[i]!=0; i++){
			PyList_Append(returnValue, Py_BuildValue("i",result[i]));
		}
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * getParentChannelOfChannel(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	uint64 result;
	logDebugFile("Called function getParentChannelOfChannel");
	if (!PyArg_ParseTuple(args, "KK", &serverConnectionHandlerID, &channelID))
		return NULL;
	if(ts3Functions.getParentChannelOfChannel(serverConnectionHandlerID, channelID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getServerVariableAsInt(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	size_t flag;
	int result;
	logDebugFile("Called function getServerVariableAsInt");
	if (!PyArg_ParseTuple(args, "Ki", &serverConnectionHandlerID, &flag))
		return NULL;
	if(ts3Functions.getServerVariableAsInt(serverConnectionHandlerID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getServerVariableAsUInt64(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	size_t flag;
	uint64 result;
	logDebugFile("Called function getServerVariableAsUInt64");
	if (!PyArg_ParseTuple(args, "Ki", &serverConnectionHandlerID, &flag))
		return NULL;
	if(ts3Functions.getServerVariableAsUInt64(serverConnectionHandlerID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getServerVariableAsString(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	size_t flag;
	char* result;
	logDebugFile("Called function getServerVariableAsString");
	if (!PyArg_ParseTuple(args, "Ki", &serverConnectionHandlerID, &flag))
		return NULL;
	if(ts3Functions.getServerVariableAsString(serverConnectionHandlerID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * requestServerVariables(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	logDebugFile("Called function requestServerVariables");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.requestServerVariables(serverConnectionHandlerID);
	return Py_None;
}
static PyObject * getConnectionStatus(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	int result;
	logDebugFile("Called function getConnectionStatus");
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	if(ts3Functions.getConnectionStatus(serverConnectionHandlerID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getConnectionVariableAsUInt64(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	uint64 result;
	logDebugFile("Called function getConnectionVariableAsUInt64");
	if (!PyArg_ParseTuple(args, "Kii", &serverConnectionHandlerID, &clientID, &flag))
		return NULL;
	if(ts3Functions.getConnectionVariableAsUInt64(serverConnectionHandlerID, clientID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getConnectionVariableAsString(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	char* result;
	logDebugFile("Called function getConnectionVariableAsString");
	if (!PyArg_ParseTuple(args, "Kii", &serverConnectionHandlerID, &clientID, &flag))
		return NULL;
	if(ts3Functions.getConnectionVariableAsString(serverConnectionHandlerID, clientID, flag, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * cleanUpConnectionInfo(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	logDebugFile("Called function cleanUpConnectionInfo");
	if (!PyArg_ParseTuple(args, "Ki", &serverConnectionHandlerID, &clientID))
		return NULL;
	ts3Functions.cleanUpConnectionInfo(serverConnectionHandlerID, clientID);
	return Py_None;
}
static PyObject * requestClientDBIDfromUID(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* clientUniqueIdentifier;
	const char* returnCode;
	logDebugFile("Called function requestClientDBIDfromUID");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &clientUniqueIdentifier, &returnCode))
		return NULL;
	ts3Functions.requestClientDBIDfromUID(serverConnectionHandlerID, clientUniqueIdentifier, returnCode);
	return Py_None;
}
static PyObject * requestClientNamefromUID(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* clientUniqueIdentifier;
	const char* returnCode;
	logDebugFile("Called function requestClientNamefromUID");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &clientUniqueIdentifier, &returnCode))
		return NULL;
	ts3Functions.requestClientNamefromUID(serverConnectionHandlerID, clientUniqueIdentifier, returnCode);
	return Py_None;
}
static PyObject * requestClientNamefromDBID(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 clientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestClientNamefromDBID");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &clientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestClientNamefromDBID(serverConnectionHandlerID, clientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * requestClientEditDescription(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* clientDescription;
	const char* returnCode;
	logDebugFile("Called function requestClientEditDescription");
	if (!PyArg_ParseTuple(args, "Kiss", &serverConnectionHandlerID, &clientID, &clientDescription, &returnCode))
		return NULL;
	ts3Functions.requestClientEditDescription(serverConnectionHandlerID, clientID, clientDescription, returnCode);
	return Py_None;
}
static PyObject * requestClientSetIsTalker(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	int isTalker;
	const char* returnCode;
	logDebugFile("Called function requestClientSetIsTalker");
	if (!PyArg_ParseTuple(args, "Kiis", &serverConnectionHandlerID, &clientID, &isTalker, &returnCode))
		return NULL;
	ts3Functions.requestClientSetIsTalker(serverConnectionHandlerID, clientID, isTalker, returnCode);
	return Py_None;
}
static PyObject * requestIsTalker(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	int isTalkerRequest;
	const char* isTalkerRequestMessage;
	const char* returnCode;
	logDebugFile("Called function requestIsTalker");
	if (!PyArg_ParseTuple(args, "Kiss", &serverConnectionHandlerID, &isTalkerRequest, &isTalkerRequestMessage, &returnCode))
		return NULL;
	ts3Functions.requestIsTalker(serverConnectionHandlerID, isTalkerRequest, isTalkerRequestMessage, returnCode);
	return Py_None;
}
static PyObject * requestSendClientQueryCommand(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* command;
	const char* returnCode;
	logDebugFile("Called function requestSendClientQueryCommand");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &command, &returnCode))
		return NULL;
	ts3Functions.requestSendClientQueryCommand(serverConnectionHandlerID, command, returnCode);
	return Py_None;
}
static PyObject * getTransferFileName(PyObject *self, PyObject *args)
{
	anyID transferID;
	char* result;
	logDebugFile("Called function getTransferFileName");
	if (!PyArg_ParseTuple(args, "i", &transferID))
		return NULL;
	if(ts3Functions.getTransferFileName(transferID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * getTransferFilePath(PyObject *self, PyObject *args)
{
	anyID transferID;
	char* result;
	logDebugFile("Called function getTransferFilePath");
	if (!PyArg_ParseTuple(args, "i", &transferID))
		return NULL;
	if(ts3Functions.getTransferFilePath(transferID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("s",result);
		if(returnValue == NULL) { return Py_None; }
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * getTransferFileSize(PyObject *self, PyObject *args)
{
	anyID transferID;
	uint64 result;
	logDebugFile("Called function getTransferFileSize");
	if (!PyArg_ParseTuple(args, "i", &transferID))
		return NULL;
	if(ts3Functions.getTransferFileSize(transferID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getTransferFileSizeDone(PyObject *self, PyObject *args)
{
	anyID transferID;
	uint64 result;
	logDebugFile("Called function getTransferFileSizeDone");
	if (!PyArg_ParseTuple(args, "i", &transferID))
		return NULL;
	if(ts3Functions.getTransferFileSizeDone(transferID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * isTransferSender(PyObject *self, PyObject *args)
{
	anyID transferID;
	int result;
	logDebugFile("Called function isTransferSender");
	if (!PyArg_ParseTuple(args, "i", &transferID))
		return NULL;
	if(ts3Functions.isTransferSender(transferID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getTransferStatus(PyObject *self, PyObject *args)
{
	anyID transferID;
	int result;
	logDebugFile("Called function getTransferStatus");
	if (!PyArg_ParseTuple(args, "i", &transferID))
		return NULL;
	if(ts3Functions.getTransferStatus(transferID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * getTransferRunTime(PyObject *self, PyObject *args)
{
	anyID transferID;
	uint64 result;
	logDebugFile("Called function getTransferRunTime");
	if (!PyArg_ParseTuple(args, "i", &transferID))
		return NULL;
	if(ts3Functions.getTransferRunTime(transferID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("K",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * haltTransfer(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID transferID;
	int deleteUnfinishedFile;
	const char* returnCode;
	logDebugFile("Called function haltTransfer");
	if (!PyArg_ParseTuple(args, "Kiis", &serverConnectionHandlerID, &transferID, &deleteUnfinishedFile, &returnCode))
		return NULL;
	ts3Functions.haltTransfer(serverConnectionHandlerID, transferID, deleteUnfinishedFile, returnCode);
	return Py_None;
}
static PyObject * requestFileList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	const char* path;
	const char* returnCode;
	logDebugFile("Called function requestFileList");
	if (!PyArg_ParseTuple(args, "KKsss", &serverConnectionHandlerID, &channelID, &channelPW, &path, &returnCode))
		return NULL;
	ts3Functions.requestFileList(serverConnectionHandlerID, channelID, channelPW, path, returnCode);
	return Py_None;
}
static PyObject * requestFileInfo(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	const char* file;
	const char* returnCode;
	logDebugFile("Called function requestFileInfo");
	if (!PyArg_ParseTuple(args, "KKsss", &serverConnectionHandlerID, &channelID, &channelPW, &file, &returnCode))
		return NULL;
	ts3Functions.requestFileInfo(serverConnectionHandlerID, channelID, channelPW, file, returnCode);
	return Py_None;
}
static PyObject * requestCreateDirectory(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	const char* directoryPath;
	const char* returnCode;
	logDebugFile("Called function requestCreateDirectory");
	if (!PyArg_ParseTuple(args, "KKsss", &serverConnectionHandlerID, &channelID, &channelPW, &directoryPath, &returnCode))
		return NULL;
	ts3Functions.requestCreateDirectory(serverConnectionHandlerID, channelID, channelPW, directoryPath, returnCode);
	return Py_None;
}
static PyObject * requestRenameFile(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 fromChannelID;
	const char* channelPW;
	uint64 toChannelID;
	const char* toChannelPW;
	const char* oldFile;
	const char* newFile;
	const char* returnCode;
	logDebugFile("Called function requestRenameFile");
	if (!PyArg_ParseTuple(args, "KKsKssss", &serverConnectionHandlerID, &fromChannelID, &channelPW, &toChannelID, &toChannelPW, &oldFile, &newFile, &returnCode))
		return NULL;
	ts3Functions.requestRenameFile(serverConnectionHandlerID, fromChannelID, channelPW, toChannelID, toChannelPW, oldFile, newFile, returnCode);
	return Py_None;
}
static PyObject * requestMessageAdd(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* toClientUID;
	const char* subject;
	const char* message;
	const char* returnCode;
	logDebugFile("Called function requestMessageAdd");
	if (!PyArg_ParseTuple(args, "Kssss", &serverConnectionHandlerID, &toClientUID, &subject, &message, &returnCode))
		return NULL;
	ts3Functions.requestMessageAdd(serverConnectionHandlerID, toClientUID, subject, message, returnCode);
	return Py_None;
}
static PyObject * requestMessageDel(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 messageID;
	const char* returnCode;
	logDebugFile("Called function requestMessageDel");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &messageID, &returnCode))
		return NULL;
	ts3Functions.requestMessageDel(serverConnectionHandlerID, messageID, returnCode);
	return Py_None;
}
static PyObject * requestMessageGet(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 messageID;
	const char* returnCode;
	logDebugFile("Called function requestMessageGet");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &messageID, &returnCode))
		return NULL;
	ts3Functions.requestMessageGet(serverConnectionHandlerID, messageID, returnCode);
	return Py_None;
}
static PyObject * requestMessageList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	logDebugFile("Called function requestMessageList");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &returnCode))
		return NULL;
	ts3Functions.requestMessageList(serverConnectionHandlerID, returnCode);
	return Py_None;
}
static PyObject * requestMessageUpdateFlag(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 messageID;
	int flag;
	const char* returnCode;
	logDebugFile("Called function requestMessageUpdateFlag");
	if (!PyArg_ParseTuple(args, "KKis", &serverConnectionHandlerID, &messageID, &flag, &returnCode))
		return NULL;
	ts3Functions.requestMessageUpdateFlag(serverConnectionHandlerID, messageID, flag, returnCode);
	return Py_None;
}
static PyObject * verifyServerPassword(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* serverPassword;
	const char* returnCode;
	logDebugFile("Called function verifyServerPassword");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandlerID, &serverPassword, &returnCode))
		return NULL;
	ts3Functions.verifyServerPassword(serverConnectionHandlerID, serverPassword, returnCode);
	return Py_None;
}
static PyObject * verifyChannelPassword(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPassword;
	const char* returnCode;
	logDebugFile("Called function verifyChannelPassword");
	if (!PyArg_ParseTuple(args, "KKss", &serverConnectionHandlerID, &channelID, &channelPassword, &returnCode))
		return NULL;
	ts3Functions.verifyChannelPassword(serverConnectionHandlerID, channelID, channelPassword, returnCode);
	return Py_None;
}
static PyObject * banclient(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	anyID clientID;
	uint64 timeInSeconds;
	const char* banReason;
	const char* returnCode;
	logDebugFile("Called function banclient");
	if (!PyArg_ParseTuple(args, "KiKss", &serverConnectionHandlerID, &clientID, &timeInSeconds, &banReason, &returnCode))
		return NULL;
	ts3Functions.banclient(serverConnectionHandlerID, clientID, timeInSeconds, banReason, returnCode);
	return Py_None;
}
static PyObject * banadd(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* ipRegExp;
	const char* nameRegexp;
	const char* uniqueIdentity;
	uint64 timeInSeconds;
	const char* banReason;
	const char* returnCode;
	logDebugFile("Called function banadd");
	if (!PyArg_ParseTuple(args, "KsssKss", &serverConnectionHandlerID, &ipRegExp, &nameRegexp, &uniqueIdentity, &timeInSeconds, &banReason, &returnCode))
		return NULL;
	ts3Functions.banadd(serverConnectionHandlerID, ipRegExp, nameRegexp, uniqueIdentity, timeInSeconds, banReason, returnCode);
	return Py_None;
}
static PyObject * bandel(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 banID;
	const char* returnCode;
	logDebugFile("Called function bandel");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &banID, &returnCode))
		return NULL;
	ts3Functions.bandel(serverConnectionHandlerID, banID, returnCode);
	return Py_None;
}
static PyObject * bandelall(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	logDebugFile("Called function bandelall");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &returnCode))
		return NULL;
	ts3Functions.bandelall(serverConnectionHandlerID, returnCode);
	return Py_None;
}
static PyObject * requestBanList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	logDebugFile("Called function requestBanList");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &returnCode))
		return NULL;
	ts3Functions.requestBanList(serverConnectionHandlerID, returnCode);
	return Py_None;
}
static PyObject * requestComplainAdd(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 targetClientDatabaseID;
	const char* complainReason;
	const char* returnCode;
	logDebugFile("Called function requestComplainAdd");
	if (!PyArg_ParseTuple(args, "KKss", &serverConnectionHandlerID, &targetClientDatabaseID, &complainReason, &returnCode))
		return NULL;
	ts3Functions.requestComplainAdd(serverConnectionHandlerID, targetClientDatabaseID, complainReason, returnCode);
	return Py_None;
}
static PyObject * requestComplainDel(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 targetClientDatabaseID;
	uint64 fromClientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestComplainDel");
	if (!PyArg_ParseTuple(args, "KKKs", &serverConnectionHandlerID, &targetClientDatabaseID, &fromClientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestComplainDel(serverConnectionHandlerID, targetClientDatabaseID, fromClientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * requestComplainDelAll(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 targetClientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestComplainDelAll");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &targetClientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestComplainDelAll(serverConnectionHandlerID, targetClientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * requestComplainList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 targetClientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestComplainList");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &targetClientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestComplainList(serverConnectionHandlerID, targetClientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * requestServerGroupList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	logDebugFile("Called function requestServerGroupList");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &returnCode))
		return NULL;
	ts3Functions.requestServerGroupList(serverConnectionHandlerID, returnCode);
	return Py_None;
}
static PyObject * requestServerGroupAdd(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* groupName;
	int groupType;
	const char* returnCode;
	logDebugFile("Called function requestServerGroupAdd");
	if (!PyArg_ParseTuple(args, "Ksis", &serverConnectionHandlerID, &groupName, &groupType, &returnCode))
		return NULL;
	ts3Functions.requestServerGroupAdd(serverConnectionHandlerID, groupName, groupType, returnCode);
	return Py_None;
}
static PyObject * requestServerGroupDel(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	int force;
	const char* returnCode;
	logDebugFile("Called function requestServerGroupDel");
	if (!PyArg_ParseTuple(args, "KKis", &serverConnectionHandlerID, &serverGroupID, &force, &returnCode))
		return NULL;
	ts3Functions.requestServerGroupDel(serverConnectionHandlerID, serverGroupID, force, returnCode);
	return Py_None;
}
static PyObject * requestServerGroupAddClient(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	uint64 clientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestServerGroupAddClient");
	if (!PyArg_ParseTuple(args, "KKKs", &serverConnectionHandlerID, &serverGroupID, &clientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestServerGroupAddClient(serverConnectionHandlerID, serverGroupID, clientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * requestServerGroupDelClient(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	uint64 clientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestServerGroupDelClient");
	if (!PyArg_ParseTuple(args, "KKKs", &serverConnectionHandlerID, &serverGroupID, &clientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestServerGroupDelClient(serverConnectionHandlerID, serverGroupID, clientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * requestServerGroupsByClientID(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 clientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestServerGroupsByClientID");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &clientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestServerGroupsByClientID(serverConnectionHandlerID, clientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * requestServerGroupPermList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	const char* returnCode;
	logDebugFile("Called function requestServerGroupPermList");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &serverGroupID, &returnCode))
		return NULL;
	ts3Functions.requestServerGroupPermList(serverConnectionHandlerID, serverGroupID, returnCode);
	return Py_None;
}
static PyObject * requestServerGroupClientList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	int withNames;
	const char* returnCode;
	logDebugFile("Called function requestServerGroupClientList");
	if (!PyArg_ParseTuple(args, "KKis", &serverConnectionHandlerID, &serverGroupID, &withNames, &returnCode))
		return NULL;
	ts3Functions.requestServerGroupClientList(serverConnectionHandlerID, serverGroupID, withNames, returnCode);
	return Py_None;
}
static PyObject * requestChannelGroupList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	logDebugFile("Called function requestChannelGroupList");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandlerID, &returnCode))
		return NULL;
	ts3Functions.requestChannelGroupList(serverConnectionHandlerID, returnCode);
	return Py_None;
}
static PyObject * requestChannelGroupAdd(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* groupName;
	int groupType;
	const char* returnCode;
	logDebugFile("Called function requestChannelGroupAdd");
	if (!PyArg_ParseTuple(args, "Ksis", &serverConnectionHandlerID, &groupName, &groupType, &returnCode))
		return NULL;
	ts3Functions.requestChannelGroupAdd(serverConnectionHandlerID, groupName, groupType, returnCode);
	return Py_None;
}
static PyObject * requestChannelGroupDel(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelGroupID;
	int force;
	const char* returnCode;
	logDebugFile("Called function requestChannelGroupDel");
	if (!PyArg_ParseTuple(args, "KKis", &serverConnectionHandlerID, &channelGroupID, &force, &returnCode))
		return NULL;
	ts3Functions.requestChannelGroupDel(serverConnectionHandlerID, channelGroupID, force, returnCode);
	return Py_None;
}
static PyObject * requestChannelGroupPermList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelGroupID;
	const char* returnCode;
	logDebugFile("Called function requestChannelGroupPermList");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &channelGroupID, &returnCode))
		return NULL;
	ts3Functions.requestChannelGroupPermList(serverConnectionHandlerID, channelGroupID, returnCode);
	return Py_None;
}
static PyObject * requestChannelPermList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* returnCode;
	logDebugFile("Called function requestChannelPermList");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &channelID, &returnCode))
		return NULL;
	ts3Functions.requestChannelPermList(serverConnectionHandlerID, channelID, returnCode);
	return Py_None;
}
static PyObject * requestClientPermList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 clientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestClientPermList");
	if (!PyArg_ParseTuple(args, "KKs", &serverConnectionHandlerID, &clientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestClientPermList(serverConnectionHandlerID, clientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * requestChannelClientPermList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	uint64 clientDatabaseID;
	const char* returnCode;
	logDebugFile("Called function requestChannelClientPermList");
	if (!PyArg_ParseTuple(args, "KKKs", &serverConnectionHandlerID, &channelID, &clientDatabaseID, &returnCode))
		return NULL;
	ts3Functions.requestChannelClientPermList(serverConnectionHandlerID, channelID, clientDatabaseID, returnCode);
	return Py_None;
}
static PyObject * privilegeKeyUse(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandler;
	const char* tokenKey;
	const char* returnCode;
	logDebugFile("Called function privilegeKeyUse");
	if (!PyArg_ParseTuple(args, "Kss", &serverConnectionHandler, &tokenKey, &returnCode))
		return NULL;
	ts3Functions.privilegeKeyUse(serverConnectionHandler, tokenKey, returnCode);
	return Py_None;
}
static PyObject * requestPermissionList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandler;
	const char* returnCode;
	logDebugFile("Called function requestPermissionList");
	if (!PyArg_ParseTuple(args, "Ks", &serverConnectionHandler, &returnCode))
		return NULL;
	ts3Functions.requestPermissionList(serverConnectionHandler, returnCode);
	return Py_None;
}
static PyObject * requestPermissionOverview(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandler;
	uint64 clientDBID;
	uint64 channelID;
	const char* returnCode;
	logDebugFile("Called function requestPermissionOverview");
	if (!PyArg_ParseTuple(args, "KKKs", &serverConnectionHandler, &clientDBID, &channelID, &returnCode))
		return NULL;
	ts3Functions.requestPermissionOverview(serverConnectionHandler, clientDBID, channelID, returnCode);
	return Py_None;
}
static PyObject * printMessage(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	const char* message;
	enum PluginMessageTarget messageTarget;
	logDebugFile("Called function printMessage");
	if (!PyArg_ParseTuple(args, "Ksi", &serverConnectionHandlerID, &message, &messageTarget))
		return NULL;
	ts3Functions.printMessage(serverConnectionHandlerID, message, messageTarget);
	return Py_None;
}
static PyObject * printMessageToCurrentTab(PyObject *self, PyObject *args)
{
	const char* message;
	logDebugFile("Called function printMessageToCurrentTab");
	if (!PyArg_ParseTuple(args, "s", &message))
		return NULL;
	ts3Functions.printMessageToCurrentTab(message);
	return Py_None;
}
static PyObject * requestInfoUpdate(PyObject *self, PyObject *args)
{
	uint64 scHandlerID;
	enum PluginItemType itemType;
	uint64 itemID;
	logDebugFile("Called function requestInfoUpdate");
	if (!PyArg_ParseTuple(args, "KiK", &scHandlerID, &itemType, &itemID))
		return NULL;
	ts3Functions.requestInfoUpdate(scHandlerID, itemType, itemID);
	return Py_None;
}
static PyObject * getServerVersion(PyObject *self, PyObject *args)
{
	uint64 scHandlerID;
	logDebugFile("Called function getServerVersion");
	if (!PyArg_ParseTuple(args, "K", &scHandlerID))
		return NULL;
	ts3Functions.getServerVersion(scHandlerID);
	return Py_None;
}
static PyObject * isWhispering(PyObject *self, PyObject *args)
{
	uint64 scHandlerID;
	anyID clientID;
	int result;
	logDebugFile("Called function isWhispering");
	if (!PyArg_ParseTuple(args, "Ki", &scHandlerID, &clientID))
		return NULL;
	if(ts3Functions.isWhispering(scHandlerID, clientID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
static PyObject * isReceivingWhisper(PyObject *self, PyObject *args)
{
	uint64 scHandlerID;
	anyID clientID;
	int result;
	logDebugFile("Called function isReceivingWhisper");
	if (!PyArg_ParseTuple(args, "Ki", &scHandlerID, &clientID))
		return NULL;
	if(ts3Functions.isReceivingWhisper(scHandlerID, clientID, &result) == ERROR_ok) {
		PyObject* returnValue = Py_BuildValue("i",result);
		if(returnValue == NULL) { return Py_None; }
		return returnValue;
	}
	return Py_None;
}
