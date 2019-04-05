#pragma once
#include <iostream>
#include <string>
constexpr auto alphabet = 26;

struct node
{
	node *branch[alphabet];
	bool end_of_word;

	node();
	node* search(const std::string);
	node* branches(node*);
	node* branches_right(node*);
	int num_branch_right(node*);
};

class trie
{
public:
	node *root;

	trie();
	trie(trie const&) = delete;
	trie(trie &&) = delete;
	void insert(const std::string) const;
	bool search(const std::string) const;
	bool have_branch(node*) const;
	int count_branches(node*);
	int right_height();
	void delete_key(const std::string) const;
	void delete_nodes(node*);
	void testing();
	virtual ~trie();
};