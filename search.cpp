#include <iostream>
#define MAX 100

using namespace std;

void InputArray (int* &a, int n)
{
    a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i]; // hay cin >> a[i]
    }
}

int *InputArray (int &n)
{
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i]; // hay *(a + i)
    }
    return a;

}

void OutputArray (int a[MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i + 1] << " ";
    }
    cout << endl;
}

int LinearSearch(int a[MAX], int n, int x){
	int i = 0; a[n] = x; 
	while(a[i] != x)
    {
		i++;
	}
	if(i == n)
    {
		return -1; 
	}
	else
    {
		return i; 
	}
}

int findbyBinarySearch (int a[MAX], int n, int x, int left, int right)
{
    while (left != right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else {
            if (a[mid] > x) // x nam ben trai
            {
                right = mid + 1;
            }
            else 
            {
                left = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int* a = NULL;
    int n;
    cin >> n;
    InputArray(a,n);
    OutputArray(a,n);
    int x;
    cout << "Input x: ";
    cin >> x;
    cout << findbyBinarySearch(a,n,x,0,n) << endl;
    cout << LinearSearch(a,n,x);
    return 0;
}