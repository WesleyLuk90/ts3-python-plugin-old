/*
 * TeamSpeak 3 demo plugin
 *
 * Copyright (c) 2008-2011 TeamSpeak Systems GmbH
 */
#pragma once
#include "Python.h"
#ifdef _WIN32
#pragma warning (disable : 4100)  /* Disable Unreferenced parameter warning */
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "public_errors.h"
//#include "public_errors_rare.h"
#include "public_definitions.h"
#include "public_rare_definitions.h"
#include "ts3_functions.h"
#include "plugin_events.h"
#include "plugin.h"

#include "python_functions.h"

static struct TS3Functions ts3Functions;

#define PLUGIN_API_VERSION 18

#define PATH_BUFSIZE 512
#define COMMAND_BUFSIZE 128
#define INFODATA_BUFSIZE 128
#define SERVERINFO_BUFSIZE 256
#define CHANNELINFO_BUFSIZE 512
#define RETURNCODE_BUFSIZE 128
#define REQUESTCLIENTMOVERETURNCODES_SLOTS 5

#define _strcpy strcpy_s

static char* pluginID = NULL;

/* Array for request client move return codes. See comments within ts3plugin_processCommand for details */
static char requestClientMoveReturnCodes[REQUESTCLIENTMOVERETURNCODES_SLOTS][RETURNCODE_BUFSIZE];

#ifdef _WIN32
/* Helper function to convert wchar_T to Utf-8 encoded strings on Windows */
static int wcharToUtf8(const wchar_t* str, char** result) {
	int outlen = WideCharToMultiByte(CP_UTF8, 0, str, -1, 0, 0, 0, 0);
	*result = (char*)malloc(outlen);
	if(WideCharToMultiByte(CP_UTF8, 0, str, -1, *result, outlen, 0, 0) == 0) {
		*result = NULL;
		return -1;
	}
	return 0;
}
#endif

/*********************************** Required functions ************************************/
/*
 * If any of these required functions is not implemented, TS3 will refuse to load the plugin
 */

/* Unique name identifying this plugin */
const char* ts3plugin_name() {
#ifdef _WIN32
	/* TeamSpeak expects UTF-8 encoded characters. Following demonstrates a possibility how to convert UTF-16 wchar_t into UTF-8. */
	static char* result = NULL;  /* Static variable so it's allocated only once */
	if(!result) {
		const wchar_t* name = L"Python Plugin";
		if(wcharToUtf8(name, &result) == -1) {  /* Convert name into UTF-8 encoded result */
			result = "Python Plugin";  /* Conversion failed, fallback here */
		}
	}
	return result;
#else
	return "Python plugin";
#endif
}

/* Plugin version */
const char* ts3plugin_version() {
    return "1.2";
}

/* Plugin API version. Must be the same as the clients API major version, else the plugin fails to load. */
int ts3plugin_apiVersion() {
	return PLUGIN_API_VERSION;
}

/* Plugin author */
const char* ts3plugin_author() {
	/* If you want to use wchar_t, see ts3plugin_name() on how to use */
    return "Python plugin";
}

/* Plugin description */
const char* ts3plugin_description() {
	/* If you want to use wchar_t, see ts3plugin_name() on how to use */
    return "Python plugin";
}

/* Set TeamSpeak 3 callback functions */
void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
    ts3Functions = funcs;
}


/*
 * Custom code called right after loading the plugin. Returns 0 on success, 1 on failure.
 * If the function returns 1 on failure, the plugin will be unloaded again.
 */
char appPath[PATH_BUFSIZE];
char resourcesPath[PATH_BUFSIZE];
char configPath[PATH_BUFSIZE];
char pluginPath[PATH_BUFSIZE];
PyObject* globalDict, *globalModule;
PyThreadState * mainThreadState = NULL;
void initPython(){
	printf("Python plugin init\n");

	PyEval_InitThreads();
	Py_Initialize();
	//mainThreadState = PyThreadState_Get();
	// Initilize the module
	TS3init();
	globalModule = PyImport_AddModule("__main__");
	{
		PyObject *sys_path, *path;
		char pythonPath[PATH_BUFSIZE];
		sys_path = PySys_GetObject("path"); 
		if (sys_path == NULL) {
			printf("Python plugin failed, sys.path was null\n");
			return; 
		}
		sprintf_s(pythonPath, PATH_BUFSIZE, "%spython", pluginPath);
		path = PyString_FromString(pythonPath);
		if (path == NULL) {
			printf("Python plugin init failed, path was NULL\n");
			return;
		}
		if (PyList_Append(sys_path, path) < 0) {
			printf("Python plugin failed, could not append path\n");
			return;
		}
	}
	globalDict = PyModule_GetDict(globalModule);
	{
		char pythonMainPath[PATH_BUFSIZE];
		PyObject* pyFile;
		// Load the main file
		sprintf_s(pythonMainPath, PATH_BUFSIZE, "%spython/main.py", pluginPath);
		//ts3Functions.printMessageToCurrentTab(pythonMainPath);
		//printf(pythonMainPath);
	
		pyFile = PyFile_FromString(pythonMainPath, "r");
		//PyRun_File(PyFile_AsFile(pyFile), pythonMainPath, Py_file_input, globalDict, globalDict);
		PyRun_AnyFileEx(PyFile_AsFile(pyFile), pythonMainPath, 1);
		// decref PyFileObject
		PyFile_DecUseCount((PyFileObject*)pyFile);
	}
	{
		PyObject* function;
		logDebugFile("plugin init");
		function = PyDict_GetItemString(globalDict, "onInit");
		if(function != NULL && PyCallable_Check(function)){
			PyObject* returnValue = PyObject_CallFunction(function, "");
			Py_XDECREF(returnValue);
		}
	}
	mainThreadState = PyEval_SaveThread();
}

int ts3plugin_init() {


    /* Example on how to query application, resources and configuration paths from client */
    /* Note: Console client returns empty string for app and resources path */
    ts3Functions.getAppPath(appPath, PATH_BUFSIZE);
    ts3Functions.getResourcesPath(resourcesPath, PATH_BUFSIZE);
    ts3Functions.getConfigPath(configPath, PATH_BUFSIZE);
	ts3Functions.getPluginPath(pluginPath, PATH_BUFSIZE);


	/* Initialize return codes array for requestClientMove */
	memset(requestClientMoveReturnCodes, 0, REQUESTCLIENTMOVERETURNCODES_SLOTS * RETURNCODE_BUFSIZE);
	initPython();
    return 0;  /* 0 = success, 1 = failure */
}

/* Custom code called right before the plugin is unloaded */
void ts3plugin_shutdown() {
    /* Your plugin cleanup code here */
	logDebugFile("plugin shutdown");
	PyEval_RestoreThread(mainThreadState);	
	{
		PyObject* function;
		logDebugFile("plugin shutdown");
		function = PyDict_GetItemString(globalDict, "onShutdown");
		if(function != NULL && PyCallable_Check(function)){
			PyObject* returnValue = PyObject_CallFunction(function, "");
			Py_XDECREF(returnValue);
		}
	}
	Py_Finalize();
	/*
	 * Note:
	 * If your plugin implements a settings dialog, it must be closed and deleted here, else the
	 * TeamSpeak client will most likely crash (DLL removed but dialog from DLL code still open).
	 */

	/* Free pluginID if we registered it */
	if(pluginID) {
		free(pluginID);
		pluginID = NULL;
	}
}

/****************************** Optional functions ********************************/
/*
 * Following functions are optional, if not needed you don't need to implement them.
 */

/* Tell client if plugin offers a configuration window. If this function is not implemented, it's an assumed "does not offer" (PLUGIN_OFFERS_NO_CONFIGURE). */
int ts3plugin_offersConfigure() {
	//printf("PLUGIN: offersConfigure\n");
	/*
	 * Return values:
	 * PLUGIN_OFFERS_NO_CONFIGURE         - Plugin does not implement ts3plugin_configure
	 * PLUGIN_OFFERS_CONFIGURE_NEW_THREAD - Plugin does implement ts3plugin_configure and requests to run this function in an own thread
	 * PLUGIN_OFFERS_CONFIGURE_QT_THREAD  - Plugin does implement ts3plugin_configure and requests to run this function in the Qt GUI thread
	 */
	return PLUGIN_OFFERS_NO_CONFIGURE;  /* In this case ts3plugin_configure does not need to be implemented */
}

/* Plugin might offer a configuration window. If ts3plugin_offersConfigure returns 0, this function does not need to be implemented. */
void ts3plugin_configure(void* handle, void* qParentWidget) {
    //printf("PLUGIN: configure\n");
}

/*
 * If the plugin wants to use error return codes or plugin commands, it needs to register a command ID. This function will be automatically
 * called after the plugin was initialized. This function is optional. If you don't use error return codes or plugin commands, the function
 * can be omitted.
 * Note the passed pluginID parameter is no longer valid after calling this function, so you must copy it and store it in the plugin.
 */
void ts3plugin_registerPluginID(const char* id) {
}

/* Plugin command keyword. Return NULL or "" if not used. */
const char* ts3plugin_commandKeyword() {
	return "python";
}

/* Plugin processes console command. Return 0 if plugin handled the command, 1 if not handled. */
int ts3plugin_processCommand(uint64 serverConnectionHandlerID, const char* command) {
	PyObject* function;
	logDebugFile("processCommand callback start");
	PyEval_RestoreThread(mainThreadState);
	logDebugFile("processCommand lock held");
	function = PyDict_GetItemString(globalDict, "processCommand");
	if(function != NULL && PyCallable_Check(function)){
		PyObject* returnValue = PyObject_CallFunction(function,"Ks", serverConnectionHandlerID, command);
		Py_XDECREF(returnValue);
	}
	logDebugFile("processCommand lock release");
	mainThreadState = PyEval_SaveThread();
	logDebugFile("processCommand callback end");
	return 0;
}
/* Client changed current server connection handler */
void ts3plugin_currentServerConnectionChanged(uint64 serverConnectionHandlerID) {
    //printf("PLUGIN: currentServerConnectionChanged %llu (%llu)\n", (long long unsigned int)serverConnectionHandlerID, (long long unsigned int)ts3Functions.getCurrentServerConnectionHandlerID());
}

void ts3plugin_pluginEvent(unsigned short data, const char* message) {
}

/*
 * Implement the following three functions when the plugin should display a line in the server/channel/client info.
 * If any of ts3plugin_infoTitle, ts3plugin_infoData or ts3plugin_freeMemory is missing, the info text will not be displayed.
 */

/* Static title shown in the left column in the info frame */
const char* ts3plugin_infoTitle() {
	return "Python plugin info";
}

/*
 * Dynamic content shown in the right column in the info frame. Memory for the data string needs to be allocated in this
 * function. The client will call ts3plugin_freeMemory once done with the string to release the allocated memory again.
 * Check the parameter "type" if you want to implement this feature only for specific item types. Set the parameter
 * "data" to NULL to have the client ignore the info data.
 */
void ts3plugin_infoData(uint64 serverConnectionHandlerID, uint64 id, enum PluginItemType type, char** data) {
}

/* Required to release the memory for parameter "data" allocated in ts3plugin_infoData */
void ts3plugin_freeMemory(void* data) {
	free(data);
}

/*
 * Plugin requests to be always automatically loaded by the TeamSpeak 3 client unless
 * the user manually disabled it in the plugin dialog.
 * This function is optional. If missing, no autoload is assumed.
 */
int ts3plugin_requestAutoload() {
	return 0;  /* 1 = request autoloaded, 0 = do not request autoload */
}
#ifdef DEBUGLOG
void logDebugFile( const char * string){
	FILE *file;
	file = fopen("python_log.txt", "a+");
	fprintf(file,"%s\n",string);
	fclose(file);
}
#else
void logDebugFile( const char * string){
}
#endif
#include "callbacks.h"
