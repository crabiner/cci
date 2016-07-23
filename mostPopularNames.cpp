#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <utility>      // std::pair
#include <iostream>     // std::cout
using namespace std;


class NameSet
{
public:
	NameSet(){}
	~NameSet(){}

	NameSet(string name, int frequency)
	{
		m_names.insert(name);
		m_rootName = name;
		m_frequency = frequency;
	}
	void copyNamesWithFrequency(unordered_set<string> names, int frequency)
	{
		m_names.insert(names.begin(),names.end());
		m_frequency += frequency;
	}
	unordered_set<string> getNames(){return m_names;}
	string getRootName() {return m_rootName;}
	int getFrequency() {return m_frequency;}
	int size() {return m_names.size();}
private:
	unordered_set<string> m_names;
	int					  m_frequency;
	string                m_rootName;
};

/* Read through (name, frequency) pairs and initialize a mapping of names to
 * NameSets (equivalence classes).*/
unordered_map<string, NameSet*> createNameSet(unordered_map<string, int> names)
{
	unordered_map<string, NameSet*> groups;
	for (auto & name :names)
	{
		NameSet * nameSet = new NameSet(name.first, name.second);
		groups.insert(make_pair(name.first, nameSet));
	}
	return groups;
}

void mergeClasses(unordered_map<string, NameSet*> & groups, vector<vector<string> > synonyms)
{
	vector<vector<string> >::iterator vvsIt;
	vector<string>::iterator vsIt;
	unordered_map<string, NameSet*>::iterator itSet1;
	unordered_map<string, NameSet*>::iterator itSet2;
	for (vvsIt = synonyms.begin(); vvsIt != synonyms.end(); vvsIt++)
	{
		vsIt = (*vvsIt).begin();
		itSet1 = groups.find(*vsIt);
		itSet2 = groups.find(*(++vsIt));

		cout << "set1="<< (itSet1->second)->getRootName() << " set2="<< (itSet2->second)->getRootName()<<endl;
		if (itSet1 == itSet2)
		{
			cout <<"same set "<<(*(vsIt))<<endl;
			continue;
		}
		else
		{
			unordered_set<string> otherNames;
			if ((itSet1->second)->size() < (itSet2->second)->size())
			{
				//set1 is smaller - copy from set1 to set2
				otherNames = (itSet1->second)->getNames();
				(itSet2->second)->copyNamesWithFrequency(otherNames, (itSet1->second)->getFrequency());
				for (auto& name : otherNames)
				{
					cout << "insert name="<<name<<" to "<< (itSet2->second)->getRootName()<<" new size "<< (itSet2->second)->size()<<endl;
					groups[name]=(itSet2->second);
				}

			}
			else
			{
				//set2 is smaller - copy from set2 to set1
				otherNames = (itSet2->second)->getNames();
				(itSet1->second)->copyNamesWithFrequency(otherNames, (itSet2->second)->getFrequency());
				for (auto& name : otherNames)
				{
					cout << "insert name="<<name << " to "<< (itSet1->second)->getRootName()<<" new size "<< (itSet1->second)->size()<<endl;
					groups[name]=(itSet1->second);
				}
			}
		}
	}
}

unordered_map<string, int> convertToMap(unordered_map<string, NameSet*> groups)
{
	unordered_map<string, int> result;
	for (auto & group : groups)
	{
		cout << "first="<<group.first<<" getRootName="<<group.second->getRootName()<< " size="<<group.second->size()<<endl;
		result.insert( make_pair(group.second->getRootName(),group.second->getFrequency()));
		delete group.second;
	}
	return result;
}
//L1 - names and occurances
//L2 - synonymous names
unordered_map<string, int> mostPopularNames(unordered_map<string, int> names, vector<vector<string> > synonyms)
{
	//step 1 create set
	unordered_map<string, NameSet*> groups = createNameSet(names);

	//step 2 merge equivalence classes together
	mergeClasses(groups, synonyms);

	return convertToMap(groups);
}

void mostPopularNames()
{
	unordered_map<string, int> names;
	vector<vector<string> > synonyms;
	vector<string> synonyms_[5];
	synonyms_[0].push_back("john");synonyms_[0].push_back("jon");
	synonyms_[1].push_back("john");synonyms_[1].push_back("johny");
	synonyms_[2].push_back("johnathan");synonyms_[2].push_back("johny");
	synonyms_[3].push_back("Carleton");synonyms_[3].push_back("Carel");
	synonyms_[4].push_back("Carleton");synonyms_[4].push_back("Careleton");
	synonyms.push_back(synonyms_[0]);
	synonyms.push_back(synonyms_[1]);
	synonyms.push_back(synonyms_[2]);
	synonyms.push_back(synonyms_[3]);
	synonyms.push_back(synonyms_[4]);

	names["john"] = 15;
	names["jon"] = 4;
	names["johny"] = 1;
	names["johnathan"] = 5;
	names["Carleton"] = 8;
	names["Careleton"] = 2;
	names["Carel"] = 5;
	unordered_map<string, int> results = mostPopularNames(names, synonyms);
	for (auto & result : results)
	{
		cout << "name="<<result.first << " freq="<<result.second <<endl;
	}

}
