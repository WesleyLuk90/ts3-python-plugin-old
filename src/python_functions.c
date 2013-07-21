#pragma once
#include "Python.h"
#include "ts3_functions.h"
extern struct TS3Functions ts3Functions;

#include "autogeneratedFunctions.h"

#define LINE_BUFFER_SIZE 1024
char lineBuffer[LINE_BUFFER_SIZE];
int lineBufferIndex = 0;
static PyObject * customWrite(PyObject *self, PyObject *args)
{
    char *command;
    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
	{
		int i;
		for(i=0;i < (int)strlen(command);i++){
			if(command[i] == '\n' || lineBufferIndex >= LINE_BUFFER_SIZE - 1){
				// flush buffer
				lineBuffer[lineBufferIndex] = '\0';
				ts3Functions.printMessageToCurrentTab(lineBuffer);
				lineBufferIndex = 0;
			} else {
				// append buffer
				lineBuffer[lineBufferIndex++] = command[i];
			}
		}
	}
	return Py_None;
}


static PyObject * getCurrentServerConnectionHandlerID(PyObject * self, PyObject * args){
	_int64 value;
	value = ts3Functions.getCurrentServerConnectionHandlerID();
	return Py_BuildValue("K", value);
}
static PyObject * getClientID(PyObject * self, PyObject * args){
	uint64 serverConnectionHandlerID;
	anyID clientID;
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	ts3Functions.getClientID(serverConnectionHandlerID, &clientID);
	return Py_BuildValue("i", clientID);
}

static PyObject * getChannelList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64* result;
	if (!PyArg_ParseTuple(args, "K", &serverConnectionHandlerID))
		return NULL;
	if(ts3Functions.getChannelList(serverConnectionHandlerID, &result)==ERROR_ok) {
		int i;
		PyObject* returnValue = PyList_New(0);
		for(i=0; result[i]!=0; i++){
			PyList_Append(returnValue, Py_BuildValue("K",result[i]));
		}
		ts3Functions.freeMemory(result);
		return returnValue;
	}
	return Py_None;
}
static PyObject * requestClientSetWhisperList(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	int clientID;
	PyObject * targetChannels;
	PyObject * targetClients;
	char returnCode;
	if (!PyArg_ParseTuple(args, "KiOO", &serverConnectionHandlerID, &clientID, &targetChannels, &targetClients))
		return NULL;
	if(!PyList_Check(targetChannels) || !PyList_Check(targetClients)){
		return NULL;
	}
	{
		int tarChanSize = PyList_Size(targetChannels);
		int tarCliSize = PyList_Size(targetClients);
		if(tarChanSize == 0 && tarCliSize == 0){
			ts3Functions.requestClientSetWhisperList(serverConnectionHandlerID, clientID, NULL, NULL, &returnCode);
		} else	{
			uint64* tarChan = (uint64*)malloc(sizeof(uint64)*(tarChanSize+1));
			anyID* tarCli =  (anyID*)malloc(sizeof(anyID)*(tarCliSize+1));
			int i;

			for(i=0;i<PyList_Size(targetChannels);i++){
				PyObject* channel = PyList_GetItem(targetChannels,i);
				if(!PyInt_Check(channel) && !PyLong_Check(channel)){
					free(tarChan);
					free(tarCli);
					ts3Functions.printMessageToCurrentTab("Error 1");
					return NULL;
				}
				tarChan[i] = PyLong_AsLong(channel);
			}
			tarChan[tarChanSize] = 0;

			for(i=0;i<PyList_Size(targetClients);i++){
				PyObject* client = PyList_GetItem(targetClients,i);
				if(!PyInt_Check(client) && !PyLong_Check(client)){
					free(tarChan);
					free(tarCli);
					ts3Functions.printMessageToCurrentTab("Error 2");
					ts3Functions.printMessageToCurrentTab(PyString_AsString(PyObject_Str(client)));
					return NULL;
				}
				tarCli[i] = (int)PyInt_AsLong(client);
			}
			tarCli[tarCliSize] = 0;

			ts3Functions.requestClientSetWhisperList(serverConnectionHandlerID, clientID, tarChan, tarCli, &returnCode);
			free(tarChan);
			free(tarCli);
		}
	}
	Py_XDECREF(targetChannels);
	Py_XDECREF(targetClients);
	return Py_None;
}

static PyObject * requestSetClientChannelGroup(PyObject *self, PyObject *args)
{
	uint64 serverConnectionHandlerID;
	uint64 channelGroup;
	uint64 channelID;
	uint64 clientUID;
	if (!PyArg_ParseTuple(args, "KKKK", &serverConnectionHandlerID, &channelGroup, &channelID, &clientUID))
		return NULL;
	ts3Functions.requestSetClientChannelGroup(serverConnectionHandlerID, &channelGroup, &channelID, &clientUID, 1, NULL);
	return Py_None;
}
static PyMethodDef TS3Methods[] = {
	{"write", customWrite, METH_VARARGS, "write"},
	{"getCurrentServerConnectionHandlerID", getCurrentServerConnectionHandlerID, METH_VARARGS, "getCurrentServerConnectionHandlerID"},
	{"getClientID", getClientID, METH_VARARGS, "getClientID"},
	{"getChannelList", getChannelList, METH_VARARGS, "getChannelList"},
	{"requestSetClientChannelGroup", requestSetClientChannelGroup, METH_VARARGS, "requestSetClientChannelGroup"},
	//{"requestClientSetWhisperList", requestClientSetWhisperList, METH_VARARGS, "requestClientSetWhisperList"},
	/* BEGIN AUTO GENERATED FUNCTION TABLE */
	//{"printMessageToCurrentTab",printMessageToCurrentTab,METH_VARARGS,"printMessageToCurrentTab"},
#include "structs.h"
	/* END AUTO GENERATED FUNCTION TABLE */
	{NULL,NULL, 0, NULL}
};
PyMODINIT_FUNC TS3init(void)
{
	PyObject *m;
	printf("Init TS3 module\n");
	m = Py_InitModule("TS3", TS3Methods);	
	PySys_SetObject("stdout", m);
	PySys_SetObject("stderr", m);
}