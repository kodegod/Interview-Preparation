//https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/



pair<int, int> maxy(vector<int>&v, int i, int j)
{
	if (i == j)
		return {v[i], v[i]};
	int mid = (i + j) / 2;
	pair<int, int> num1 = maxy(v, i, mid);
	pair<int, int> num2 = maxy(v, mid + 1, j);
	return {max(num1.first, num2.first), min(num1.second, num2.second)};
}
