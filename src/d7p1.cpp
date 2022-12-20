#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

struct treeNode
{
	struct treeNode *parent = nullptr;
	std::string name;
	int totalSize = 0;
	std::vector<treeNode> children;

	treeNode(treeNode *_parent, const std::string& _name) : parent(_parent), name(_name) { }
};

int dfs(treeNode& node)
{
	int total = 0;
	for (auto i = node.children.begin(); i != node.children.end(); i++)
	{
		total += dfs(*i);
	}
	return total + ((node.totalSize < 100000) ? node.totalSize : 0);
}

int main()
{
	std::string line;
	struct treeNode tree(nullptr, "/");
	struct treeNode* current = &tree;

	// Initialization
	std::getline(std::cin, line);
	while (!line.empty())
	{
		if (line.rfind("$ cd", 0) == 0)
		{
			if (line == "$ cd /")
				current = &tree;
			else if (line == "$ cd ..")
				current = current->parent;
			else
			{
				std::string tmpstr = line.substr(5);
				current = &*std::find_if(current->children.begin(), current->children.end(), [tmpstr](const treeNode& tmp) -> bool { return (tmp.name == tmpstr); });
			}
			if (!std::getline(std::cin, line))
				break;
		}
		else if (line.rfind("$ ls", 0) == 0)
		{
			std::getline(std::cin, line);
			int total = 0;
			while (!line.empty()  && line[0] != '$')
			{
				if (line.rfind("dir ", 0) == 0) // if it is a directory
				{
					current->children.push_back(treeNode(current, line.substr(4)));
				}
				else
					total += strtol(line.c_str(), nullptr, 10);
				std::getline(std::cin, line);
			}
			for (treeNode *tmp = current; tmp; tmp = tmp->parent)
				tmp->totalSize += total;
		}
		else
			std::cerr << "something went wrong\n";
	}

	// Computing
	std::cout << dfs(tree) << std::endl;
}