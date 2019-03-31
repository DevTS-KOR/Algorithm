#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(string first, string second)
{
	if (first > second)
		return true;
	else if (first < second)
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int iRecord = 0;
	unordered_map<string, string> oELlist_Map;
	vector<string> oRemain_Array;
	oELlist_Map.reserve(100000);
	oRemain_Array.reserve(100000);
	string sName, sEL;

	cin >> iRecord;
	for (int i = 0; i < iRecord; ++i)
	{
		cin >> sName;
		cin >> sEL;
		oELlist_Map[sName] = sEL;
	}

	unordered_map<string, string>::const_iterator Iter = oELlist_Map.cbegin();
	unordered_map<string, string>::const_iterator EndIter = oELlist_Map.cend();
	for (Iter; Iter != EndIter; ++Iter)
	{
		if (Iter->second == "enter")
			oRemain_Array.emplace_back(Iter->first);
	}

	sort(oRemain_Array.begin(), oRemain_Array.end(), Compare);

	int iRemainCount = oRemain_Array.size();
	for (int i = 0; i < iRemainCount; ++i)
		cout << oRemain_Array[i] << '\n';

	return 0;
}