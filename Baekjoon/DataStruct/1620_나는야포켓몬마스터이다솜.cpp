#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iPoketCount = 0;
	int iTestCount = 0;
	unordered_map<int, string> oNumberName_Map;
	unordered_map<string, int> oNameNumber_Map;
	vector<string> vResult_Array;
	oNumberName_Map.reserve(100000);
	oNameNumber_Map.reserve(100000);
	vResult_Array.reserve(100000);
	string sPoketName;
	sPoketName.reserve(20);

	cin >> iPoketCount;
	cin >> iTestCount;

	for (int i = 0; i < iPoketCount; ++i)
	{
		cin >> sPoketName;
		oNumberName_Map.insert(unordered_map<int, string>::value_type(i, sPoketName));
		oNameNumber_Map.insert(unordered_map<string, int>::value_type(sPoketName, i));
	}

	string sFind;
	sFind.reserve(20);
	for (int i = 0; i < iTestCount; ++i)
	{
		cin >> sFind;

		if (isdigit(sFind[0]))
		{
			int iFind = atoi(sFind.c_str());
			cout << oNumberName_Map[iFind - 1] << '\n';
		}
		else
		{
			cout << oNameNumber_Map[sFind] + 1 << '\n';
		}
	}

	return 0;
}