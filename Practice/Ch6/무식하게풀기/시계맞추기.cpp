#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
// linked[i][j] = 'x': i�� ����ġ�� j�� �ð谡 ����Ǿ� �ִ�.
// linked[i][j] = '.': i�� ����ġ�� j�� �ð谡 ����Ǿ� ���� �ʴ�.
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

// ��� �ð谡 12�ø� ����Ű�� �ִ��� Ȯ���Ѵ�.
bool areAligned(const vector<int>& clocks)
{
	for (int i = 0; i < CLOCKS; i++)
		if (clocks[i] % 4 != 0)
			return false;
	return true;
}

// switch�� ����ġ�� ������.
void push(vector<int>& clocks, int swtch)
{
	for (int clock = 0; clock < CLOCKS; ++clock)
	{
		if (linked[swtch][clock] == 'x')
		{
			clocks[clock] += 3;
			if (clocks[clock] == 15)
				clocks[clock] = 3;
		}
	}
}

// clock: ���� �ð���� ����
// swtch: �̹��� ���� ����ġ�� ��ȣ
// �� �־��� ��, ���� ����ġ���� ������ clock�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ�Ѵ�.
// ���� �Ұ����ϴٸ� INF�̻��� ū���� ��ȯ�Ѵ�.
int solve(vector<int>& clocks, int swtch)
{
	if (swtch == SWITCHES)
		return areAligned(clocks) ? 0 : INF;

	// �� ����ġ�� 0�� ������ ������ ���� ������ �������� ��� �õ��Ѵ�.
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt)
	{
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	
	return ret;
}

int main()
{
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; cc++)
	{
		vector<int> clocks(16, 0);
		for (int i = 0; i < 16; i++)
			cin >> clocks[i];

		int ret = solve(clocks, 0);
		cout << (ret >= INF ? -1 : ret) << endl;

	}

	return 0;
}