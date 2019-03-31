#pragma once
#include <iostream>
#include <vector>

// n���� ���� �� m���� ���� ��� ������ ã�� �˰���
// picked: ���ݱ��� �� ���ҵ��� ��ȣ
// toPickL �� �� ������ ��
// �� ��, ������ toPick���� ���Ҹ� ���� ��� ����� ����Ѵ�.
void pick(int n, std::vector<int>& picked, int toPick)
{
	// ���� ���: �� �� ���Ұ� ���� �� �� ���ҵ��� ����Ѵ�.
	if (toPick == 0)
	{
		printPicked(picked);
		return;
	}

	// �� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�.
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	// �� �ܰ迡�� ���Ҹ� �ϳ� ����.
	for (int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}