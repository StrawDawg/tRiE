#include "trie.h"

int main()
{
	trie tree;

	tree.insert("arc");
	tree.insert("plop");
	std::cout << tree.search("plop") << " ";
	tree.delete_key("plop");
	tree.testing();
	system("pause");
	return(0);
}