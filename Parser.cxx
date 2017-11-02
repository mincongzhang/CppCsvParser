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

		vector<string> v1;
		v1.push_back("A");
		v1.push_back("B");
		v1.push_back("C");
		vector<string> v2;
		v2.push_back("1");
		v2.push_back("2");
		v2.push_back("3");
		vector<string> v3;
		v2.push_back("a");
		v2.push_back("b");
		v2.push_back("c");
		m_map.push_back(v1);
		m_map.push_back(v2);
		m_map.push_back(v3);
        return true;
	}

	int getFieldIdx(const string & field_name){
		//if not exist, return -1
		return m_field_idx[field_name];
	}

	vector<vector<string> >::iterator begin(){
		return m_map.begin();
	}

	vector<vector<string> >::iterator end(){
		return m_map.end();
	}

	//TODO:bool iterator::get(const string & field_name, string & field_val)
};


class parser_iterator : public boost::iterator_facade <parser_iterator, Parser, boost::forward_traversal_tag> {
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
        vector<string> & v = *m_it;
    }
};


int main(){
	//Usecase
	Parser parser;
	parser.load();
    parser_iterator it(parser.begin());
    parser_iterator it_end(parser.end());
    int count = 0;
	for (; it!=it_end; ++it){
        cout<<count<<endl;
        count++;
        //for(int i=0; i<v.size(); ++i){
         //   cout<<v[i]<<endl;
        //}
	}
}
