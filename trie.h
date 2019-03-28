#pragma once
#include <iostream>
#include <string>
constexpr auto alphabet = 26;

class trie
{
public:
	trie *branch[alphabet];
	bool end_of_word;

	trie();
	void insert(const std::string);
	bool search(const std::string);
	bool have_branch(trie *const);
	bool delete_key(trie*&, const std::string);

};