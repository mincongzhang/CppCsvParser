# FileParser

C++ tool to parse file like:

```
FIELD1|FIELD2|FIELD3|FIELD4|
VAL__1|VAL__X|VAL__Y|VAL__Z|
VAL__1|VAL__X|VAL__Y|VAL__Z|
VAL__2|VAL__X|VAL__Y|VAL__Z|
VAL__3|VAL__X|VAL__Y|VAL__Z|
```
with config
```
FIELDS = FIELD1,FIELD2,FIELD3,FIELD4
DELIM  = "|"
```

to achieve:

```
CfgableParser parser;
parser.load("path/to/file", "path/to/cfg");
for (CfgableParser::const_iterator it=parser.begin(); it!=parser.end(); ++it){
	string val;
	if(it->get("FIELD",val)){
		//update something
	}
}
```
