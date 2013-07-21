import shutil

types = {
	"const char*" : ["in", "s"],
	"char*" : ["out", "s"],
	"uint64" : ["in", "K"],
	"anyID" : ["in", "i"],
	"size_t" : ["in", "i"],
	"int" : ["in", "i"],
	"unsigned int" : ["in", "i"],
}
import re

matcher = re.compile(r"^PLUGINS_EXPORTDLL\s+(void|int)\s+ts3plugin_(\w+)\((.*)\);")

callbackData = open("plugin.h").read()
output = open("callbacks.h","w")
start = False
for line in callbackData.split("\n"):
	if line.strip() == "/* Clientlib */":
		start = True
	if not start:
		continue
	match = matcher.match(line)
	if not match:
		continue
	returnType = match.group(1)
	functionName = match.group(2)
	parameters = [x.strip() for x in match.group(3).split(",")]
	paramArray = []
	paramString = ""
	invalid = False
	for x in parameters:
		spaceIndex = x.rfind(" ")
		type = x[0:spaceIndex].strip()
		if type in types.keys():
			paramString += types[type][1]
		else:
			print "Missing %s in function %s" % (type, functionName)
			invalid = True
			continue
		var = x[spaceIndex:].strip()
		paramArray.append([type,var])
	if invalid:
		continue
	output.write("%s ts3plugin_%s(%s){\n" % (returnType, functionName, match.group(3))); # function signature
	output.write('\tPyObject* function;\n');
	output.write('\tlogDebugFile("%s callback start");\n'  % functionName);
	
	# output.write('\tPyGILState_STATE gstate = PyGILState_Ensure();\n');
	output.write('\tPyEval_RestoreThread(mainThreadState);\n');	
	output.write('\tlogDebugFile("%s lock held");\n'  % functionName);
	output.write('\tfunction = PyDict_GetItemString(globalDict, "%s");\n' % functionName)
	output.write('\tif(function != NULL && PyCallable_Check(function)){\n');
	if(len(paramArray) > 0):
		output.write('\t\tPyObject* returnValue = PyObject_CallFunction(function,"%s", %s);\n' % (paramString,", ".join([x[1] for x in paramArray])));
		output.write('\t\tPy_XDECREF(returnValue);\n')
	else:
		print "Error empty function call in function %s" % functionName
		output.write('\t\tPyFunc_Call(function);\n');
	output.write("\t}\n")
	
	output.write('\tlogDebugFile("%s lock release");\n'  % functionName);
	output.write("\tmainThreadState = PyEval_SaveThread();\n")
	
	output.write('\tlogDebugFile("%s callback end");\n' % functionName);
	
	if returnType == "int":
		output.write("\t return 0;\n");
	output.write("}\n");
	# output.write(returnType)
	# output.write(" " + functionName)
	# output.write(repr(paramArray))
output.close()
shutil.copyfile('callbacks.h', '../src/callbacks.h')