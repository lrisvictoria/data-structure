#define _CRT_SECURE_NO_WARNINGS 1 

void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);

	int minChild = parent * 2 + 1;

	while (minChild < n)
	{
		if (minChild + 1 < n && a[minChild + 1] > a[minChild])
		{
			minChild++;
		}
		if (a[minChild] > a[parent])
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}