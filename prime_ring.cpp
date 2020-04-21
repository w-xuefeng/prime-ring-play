
#include <iostream>
#include <math.h>
using namespace std;
int n = 0;
int a[100];			 // 对应环
int visit[100];	 // 标记数组 0表示未用 1表示已用
int check(int k)
{
	int i, n;
	n = (int)sqrt(k);
	for (i = 2; i <= n; i++)
		if (k % i == 0)
			return 0;
	return 1;
}

void dfs(int step)
{
	if (step == n && check(a[0] + a[n - 1]) == 1)
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (visit[i] == 0 && check(i + a[step - 1]) == 1)
			{
				a[step] = i;
				visit[i] = 1;
				dfs(step + 1);
				visit[i] = 0;
			}
		}
	}
}
int main(void)
{
	cin >> n;
	a[0] = 1;
	visit[1] = 1;
	dfs(1);
	return 0;
}
