#include <set>
#include <vector>

template <class T, class Compare = std::less<T> >
class DisjointSets
{
	public:
		// create a new set containing item
		void insert(T item)
		{
			std::set<T, Compare> s;
			s.insert(item);
			sets.push_back(s);
		}

		// find which set the item belongs in
		int find(T item)
		{
			for (size_t i = 0; i < sets.size(); ++i) {
				if (sets[i].find(item) != sets[i].end()) {
					return i;
				}
			}
			return -1;
		}

		// combine 2 sets
		void setUnion(int s1, int s2)
		{
			// add the contents of the seoncd set to the first set
			sets[s1].insert(sets[s2].begin(), sets[s2].end());

			// delete the second set
			sets.erase(sets.begin() + s2);
		}

	private:
		std::vector<std::set<T, Compare> > sets;
};
