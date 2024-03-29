#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n)
{
	vector<float> b[n];

	// Put array elements in different buckets
	for (int i = 0; i < n; i++) {
		int bi = n * arr[i]; 
		b[bi].push_back(arr[i]);
	}

	// Sort individual buckets
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	// Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main()
{
    int n;
    cin>>n;
    float arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	//float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	bucketSort(arr, n);
	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
