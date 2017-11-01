CfgableParser {
	private:
		vector<vector<string> > m_map;
		unordered_map<string,int> m_field_idx;

		
	public:
		bool load(const string & filename, const config & cfg){
			//load m_field_idx
			//load m_map
		}

		int getFieldIdx(const string & field_name){
			//if not exist, return -1
			return m_field_idx[field_name];
		}
		
		//TODO:iterator
		//TODO:begin()
		//TODO:end()
		//TODO:bool iterator::get(const string & field_name, string & field_val)
};

//Usecase
CfgableParser parser;
parser.load("path/to/file", "path/to/cfg");
for (CfgableParser::const_iterator it=parser.begin(); it!=parser.end(); ++it){
	string val;
	if(it->get("FIELD",val)){
		//update something
	}
}
