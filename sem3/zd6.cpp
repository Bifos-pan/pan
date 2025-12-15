#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
	system("chcp 1251 > nul");
	vector<double>heights;
	for (int i = 0; i <= 20; i += 3)
		heights.push_back(i);
	auto new_end = remove_if(heights.begin(), heights.end(), [](double h) {return h < 10; });
	heights.erase(new_end, heights.end());
	for (int i = 0; i < heights.size(); i++)
		cout << heights[i] << endl;
}
