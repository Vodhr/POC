#pragma once
#include <list>

using namespace std;

class TreeEntry
{
protected:
	list<TreeEntry> subEntries;
public:
	virtual void getString() = 0;
	list<TreeEntry>& getSubEntries();
};

