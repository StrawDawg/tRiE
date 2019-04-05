#include "trie.h"

node::node()
{
	this->end_of_word = false;
	for (auto& i : this->branch)
		i = nullptr;
}

node* node::search(const std::string key)
{
	node *curr = this;
	for (auto i = 0; i < static_cast<int>(key.length()); i++)
	{
		auto index = key[i] - 'a';
		curr = curr->branch[index];
		if (curr == nullptr)
		{
			return(nullptr);
		}
	}
	return(curr);
}

node* node::branches(node* ptr)
{
	for (auto i = 0; i < alphabet; i++)
	{
		if (ptr->branch[i])
		{
			return(ptr->branch[i]);
		}
	}
	return(nullptr);
}
int node::num_branch_right(node* ptr)
{
	for (auto i = 0; i < alphabet; i++)
	{
		if (ptr->branch[i])
		{
			return(i);
		}
	}
}

node* branches_right(node* ptr)
{
	for (auto i = alphabet - 1; i >= 0; i--)
	{
		if (ptr->branch[i])
		{
			return(ptr->branch[i]);
		}
	}
	return(nullptr);
}

trie::trie()
{
	root = new node();
}


void trie::insert(const std::string key) const
{
	node *curr = root;
	for(auto i = 0; i < static_cast<int>(key.length()); i++)
	{
		auto index = key[i] - 'a';
		if(!curr->branch[index])
		{
			curr->branch[index] = new node();
		}
		curr = curr->branch[index];
	}
	curr->end_of_word = true;
}

bool trie::search(const std::string key) const
{
	if (root->search(key) != nullptr)
		return(root->search(key)->end_of_word);
	else
		return(false);
}

bool trie::have_branch(node* ptr) const
{
	if(root->branches(ptr) != nullptr)
		return(true);
	else
		return(false);
}

int trie::count_branches(node* ptr)
{
	auto count = 0;
	for (auto i = 0; i < alphabet; i++)
	{
		if (ptr->branch[i])
		{
			count++;
		}
	}
	return(count);
}

int trie::right_height()
{
	node* temp = root;
	int count = 0;
	while(branches_right(temp) != nullptr)
	{
		temp = branches_right(temp);
		count++;
	}
	return(count);
}


void trie::delete_key(const std::string key) const
{
	if(search(key))
	{
		root->search(key)->end_of_word = false;
	}
}

void trie::delete_nodes(node* node)
{
	if (node != nullptr)
	{
		if (root->branches(node) == nullptr)
		{
			node = nullptr;
			delete node;
			return;
		}

		for (auto i = 0; i < count_branches(node); i++)
		{
			delete_nodes(root->branches(node));
		}
	}
}

void trie::testing()
{
	insert("uefhhfhksbhifqwr");
	insert("oooiwoufjonjkbkbfqfob");
	insert("glnjglljnvjofhifqnle");
	insert("dwnwohovhuowqfbkvhb");
	insert("nbkbeebbeblq");
	insert("nkvnjqohqfhipgh");
	insert("wn nnqqfpidhaeygsvv");
	insert("bbwbkbrgukbjhhhhrrhrrsz");
	insert("zzzxzxczccipwuyrgi");
	insert("vjvjmjbvksbjkv");
	insert("bsjbjksbvdd");
	insert("aaaaaaadladkkfdshj");
	insert("ghsjnsgjojlegns");
	insert("pomegranate");
	insert("insult");
	insert("asap");
	insert("sophisticated");
	insert("abomination");
	delete_key("fhewughwughw");
	delete_key("foqgoqhogeqweg");
	bool a = search("sophisticated");
	a = search("abomination");
	a = search("insult");
	delete_key("abomination");
	delete_key("wgfigeuofgufgq");
	delete_key("asap");
}

trie::~trie()
{
	delete_nodes(root);
}