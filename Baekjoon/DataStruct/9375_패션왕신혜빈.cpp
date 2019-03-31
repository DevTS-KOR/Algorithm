#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int iTestCount = 0;
	int iWearCount = 0;
	string sWear, sType;
	unordered_map<string, int> oWear_Map;
	oWear_Map.reserve(30);
	cin >> iTestCount;

	for (int i = 0; i < iTestCount; ++i)
	{
		cin >> iWearCount;
		for (int j = 0; j < iWearCount; ++j)
		{
			cin >> sWear;
			cin >> sType;
			if (oWear_Map.find(sType) == oWear_Map.end())
				oWear_Map[sType] = 1;
			else
				oWear_Map[sType] += 1;
		}

		int iResultCount = 1;
		unordered_map<string, int>::const_iterator Iter = oWear_Map.cbegin();
		unordered_map<string, int>::const_iterator EndIter = oWear_Map.cend();
		for (Iter; Iter != EndIter; ++Iter)
			iResultCount *= (Iter->second + 1);
		
		iResultCount -= 1;
		cout << iResultCount << '\n';

		oWear_Map.clear();
	}

	return 0;
}