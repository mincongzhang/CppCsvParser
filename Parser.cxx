# include <boost/iterator/iterator_facade.hpp>
#include <memory>
#include <iostream>
#include <algorithm>
#include <functional>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Parser {
private:
	vector<vector<string> > m_map;
	unordered_map<string,int> m_field_idx;

public:
	bool load(/*const string & filename , const config & cfg*/){
		//load m_field_idx
		//load m_map

        m_field_idx["A"]=0;
        m_field_idx["B"]=1;
        m_field_idx["C"]=2;
        
		vector<string> v1;
		v1.push_back("A");
		v1.push_back("B");
		v1.push_back("C");
		vector<string> v2;
		v2.push_back("1");
		v2.push_back("2");
		v2.push_back("3");
		vector<string> v3;
		v3.push_back("a");
		v3.push_back("b");
		v3.push_back("c");
		m_map.push_back(v1);
        m_map.push_back(v3);
		m_map.push_back(v2);
		m_map.push_back(v3);

        return true;
	}

	int getFieldIdx(const string & field_name){
        if(m_field_idx.find(field_name)==m_field_idx.end()){
            return -1;
        }
		
		return m_field_idx[field_name];
	}

	vector<vector<string> >::iterator begin(){
		return m_map.begin();
	}

	vector<vector<string> >::iterator end(){
		return m_map.end();
	}
};


class parser_iterator : public boost::iterator_facade <parser_iterator, vector<vector<string> >::iterator, boost::forward_traversal_tag> {
private:
	friend class boost::iterator_core_access;
	void increment() { ++m_it; }

	bool equal(const parser_iterator & other) const {
		return this->m_it == other.m_it;
	}

    vector<string> & dereference() const { return *m_it; }

	vector<vector<string> >::iterator m_it;
public:
	parser_iterator(){}
	explicit parser_iterator(vector<vector<string> >::iterator it): m_it(it) {}
    
    void print(){
        vector<string> v = *m_it;
        for(int i=0; i<v.size(); ++i){
            cout<<v[i]<<",";
        }
        cout<<endl;
    }
    
    bool get(const int field_idx, string & field_val){
        const vector<string> & v = *m_it;
        if(field_idx<0 || field_idx>= v.size()){
            return false;
        }
        
        field_val = v[field_idx];
        return true;
    }
};


int main(){
	//Usecase
	Parser parser;
	parser.load();
    parser_iterator it(parser.begin());
    parser_iterator it_end(parser.end());
    int count = 0;
	for (; it!=it_end; it++){
        //it.print();
        string val;
        it.get(parser.getFieldIdx("A"), val);
        cout<<val<<endl;
	}
}
