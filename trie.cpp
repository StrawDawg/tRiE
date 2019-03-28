#include "trie.h"

trie::trie()
{
	this->end_of_word = false;
	for (auto& i : this->branch)
		i = nullptr;
}

void trie::insert(const std::string key)
{
	trie *curr = this;
	for(auto i = 0; i < static_cast<int>(key.length()); i++)
	{
		auto index = key[i] - 'a';
		if(!curr->branch[index])
		{
			curr->branch[index] = new trie();
		}
		curr = curr->branch[index];
	}
	curr->end_of_word = true;
}

bool trie::search(const std::string key)
{
	if(this == nullptr)
	{
		return(false);
	}
	trie *curr = this;
	for(auto i = 0; i < static_cast<int>(key.length()); i++)
	{
		auto index = key[i] - 'a';
		curr = curr->branch[index];
		if(curr == nullptr)
		{
			return(false);
		}
	}
	return(curr->end_of_word);
}

bool trie::have_branch(trie *const ptr)
{
	for (auto i = 0; i < alphabet; i++)
	{
		if(ptr->branch[i])
		{
			return(true);
		}
	}
	return(false);
}

bool trie::delete_key(trie*& ptr, const std::string key)
{
	if (ptr == nullptr)
		return(false);

	if (key.length())
	{

		if (ptr->branch[key[0] - 'a'] != nullptr && delete_key(ptr->branch[key[0] - 'a'], key.substr(1)) && ptr->end_of_word == false)
		{
			if (!have_branch(ptr))
			{
				delete ptr;
				ptr = nullptr;
				return(true);
			}
			else {
				return(false);
			}
		}
	}

	if (key.length() == 0 && ptr->end_of_word)
	{
		if (!have_branch(ptr))
		{
			delete ptr;
			ptr = nullptr;
			return(true);
		}
		else
		{
			ptr->end_of_word = false;
			return(false);
		}
	}
	return(false);
}