#include "trie.h"

int main()
{
	trie *head = new trie();

	head->insert("plop");
	head->insert("ploop");
	std::cout << head->search("ploop") << " ";
	std::cout << head->delete_key(head, "plop") << "\n";
	system("pause");
	return(0);
}