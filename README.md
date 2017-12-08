# FileParser

C++ tool to parse file like:

```
FIELD1,FIELD2,FIELD3,FIELD4,
VAL__1,VAL__X,VAL__Y,VAL__Z,
VAL__1,VAL__X,VAL__Y,VAL__Z,    (duplicates)
VAL__2,VAL__X,VAL__Y,VAL__Z,
VAL__3,VAL__X,VAL__Y,VAL__Z,
```
with config
```
FIELDS = FIELD1,FIELD2,FIELD3,FIELD4
DELIM  = ","
```

to achieve:

```
Parser parser;
parser.load("path/to/file", "path/to/cfg");

for (Parser::const_iterator it=parser.begin(); it!=parser.end(); ++it){
	string val;
	if(it->get("FIELD2",val)){
		//update something
	}
}
```

actual code:

```
Parser parser;
parser.load(/*filename, cfg*/);
for (parser_iterator it=parser.begin(); it!=parser.end(); it++){
    //it.print();
    string val;
    if(it.get(parser.getFieldIdx("A"), val)){
        cout<<val<<endl;
    } else {
        cout<<"unable to get val"<<endl;
    }
}
```


### reference:
1.Wrap STL vector and change behavior of its iterator  
https://stackoverflow.com/questions/7824097/wrap-stl-vector-and-change-behavior-of-its-iterator

2.Using `boost::iterator_facade<>`  
https://stackoverflow.com/questions/3514457/using-boostiterator-facade  
http://www.boost.org/doc/libs/1_62_0/libs/iterator/doc/iterator_facade.html

3.Iterator Adaptor?
