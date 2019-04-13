#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> iFirst_Array;
	vector<int> iSecond_Array;
	vector<int> iThird_Array;
	vector<int> iFour_Array;
	vector<int> iFirstSecond_Array;
	vector<int> iThirdFour_Array;
	iFirst_Array.reserve(4000);
	iSecond_Array.reserve(4000);
	iThird_Array.reserve(4000);
	iFour_Array.reserve(4000);
	iFirstSecond_Array.reserve(16000);
	iThirdFour_Array.reserve(16000);

	int iArraySize = 0;
	int iArrayValue = 0;
	cin >> iArraySize;

	for (int i = 0; i < iArraySize; ++i)
	{
		cin >> iArrayValue;
		iFirst_Array.emplace_back(iArrayValue);
		cin >> iArrayValue;
		iSecond_Array.emplace_back(iArrayValue);
		cin >> iArrayValue;
		iThird_Array.emplace_back(iArrayValue);
		cin >> iArrayValue;
		iFour_Array.emplace_back(iArrayValue);
	}

	long long iResultCount = 0;

	for (int a = 0; a < iArraySize; ++a)
	{
		for (int b = 0; b < iArraySize; ++b)
		{
			iFirstSecond_Array.emplace_back(iFirst_Array[a] + iSecond_Array[b]);
			iThirdFour_Array.emplace_back(iThird_Array[a] + iFour_Array[b]);
		}
	}

	sort(iThirdFour_Array.begin(), iThirdFour_Array.end());

	for (int i = 0; i < iArraySize * iArraySize; i++)
	{
		int iValue = -1 * iFirstSecond_Array[i];

		iResultCount += upper_bound(iThirdFour_Array.begin(), iThirdFour_Array.begin() + iArraySize * iArraySize, iValue)
			- lower_bound(iThirdFour_Array.begin(), iThirdFour_Array.begin() + iArraySize * iArraySize, iValue);
	}

	cout << iResultCount;

	return 0;
}