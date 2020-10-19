/*In order to improve customer experience, Amazon has developed a system to provide recommendations to the customers regarding the items they can purchase. Based on historical customer purchase information, an item association can be efined as
- if an item A is ordered by a customer, then item B is also likely to be ordered by the same customer
(e.g. Book1 is frequently ordered with Book2). All items that are linked together by an item association can be considered to be in the same group. An item without any association to any other item can be considered to be in its own item association of group size 1.
Given the list of item association relationships (i.e. group of items likely to be ordered together), write down an algorithm that outputs the largest item association group. If two groups have the same number of items then select the group which contains the item that appears first in lexicographic order.
*/
struct PairString {
	string first;
	string second;
	PairString(string first, string second): first(first), second(second) {}
};

unordered_map<string, string> parent;
unordered_map<string, int> subsetSize;

bool compare(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

string find(string x) {
	while (x != parent[x])
		x = parent[x];
	return x;
}

void unite(string a, string b)
{
	string rep1 = find(a);
	string rep2 = find(b);
	if (subsetSize[rep1] < subsetSize[rep2])
	{
		subsetSize[rep2] += subsetSize[rep1];
		parent[rep1] = rep2;
	}
	else
	{
		subsetSize[rep1] += subsetSize[rep2];
		parent[rep2] = rep1;
	}
}

vector <string> largestItemAssociation(vector<PairString> &itemassociation)
{
	vector<vector<string> > items;
	for (auto &item : itemassociation)
	{
		parent[item.first] = item.first;
		parent[item.second] = item.second;
		subsetSize[item.first] = 1;
		subsetSize[item.second] = 1;
	}
	for (auto &pairs : itemassociation)
		unite(pairs.first, pairs.second);
	vector<pair<string, int> > largest(subsetSize.begin(), subsetSize.end());
	sort(largest.begin(), largest.end(), compare);
	int max_size = largest[0].second;
	int lexicographic_index = 0;
	int count = 0;
	for (auto &item : largest)
	{
		if (item.second < max_size)
			continue;
		vector<string> subset_members;
		for (auto link : parent)
		{
			if (find(link.second) == item.first)
				subset_members.push_back(link.first);
		}
		if (subset_members.size())
		{
			sort(subset_members.begin(), subset_members.end());
			items.push_back(subset_members);
			if (items[lexicographic_index][0] > subset_members[0])
				lexicographic_index = count;
			count++;
		}
	}
	return items[lexicographic_index];
}
