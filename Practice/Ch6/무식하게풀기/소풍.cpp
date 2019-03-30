#include <iostream>

using namespace std;


int n;
bool areFriends[10][10];
bool take[10] = { false, };
int result[50] = { 0, };

// taken[i] = i��° �л��� ¦�� �̹� ã������ true, �ƴϸ� false
int countPairings(bool taken[10])
{
	// ���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�.
	int firstFree = -1;
	for (int i = 0; i < n; ++i)
	{
		if (taken[i] == false)
		{
			firstFree = i;
			break;
		}
	}

	// ���� ���: ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	if (firstFree == -1)
		return true;
	
	int ret = 0;
	// �� �л��� ¦���� �л��� �����Ѵ�.
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
	{
		if (taken[pairWith] == false && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}

int main()
{
	int iTestCount = 0;
	int iStudentCount = 0;
	int iFriendCount = 0;
	
	scanf_s("%d", &iTestCount);
	for (int i = 0; i < iTestCount; ++i)
	{
		scanf_s("%d", &n);
		scanf_s("%d", &iFriendCount);

		for (int j = 0; j < iFriendCount; ++j)
		{
			int iFirst, iSecond = 0;
			scanf_s("%d", &iFirst);
			scanf_s("%d", &iSecond);
			
			areFriends[iFirst][iSecond] = true;
			areFriends[iSecond][iFirst] = true;
		}

		int count = countPairings(take);

		result[i] = count;

		for (int a = 0; a > 10; ++a)
		{
			take[a] = false;
			for (int b = 0; b > 10; ++b)
				areFriends[a][b] = false;
		}
	}

	int i = 0;
	while (true)
	{
		if (result[i] != 0)
			printf("%d\n", result[i]);
		else
			break;

		++i;
	}


	return 0;
}