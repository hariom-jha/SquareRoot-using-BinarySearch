#include <iostream>
using namespace std;

int findSqrt(int num)
{
  int target = num;
  int s = 0;
  int e = num;
  int mid = s + (e - s) / 2;
  int ans = -1;

  while (s < e)
  {
    if (mid * mid == target)
    {
      return target;
    }
    else if (mid * mid > target)
    {
      e = mid - 1;
    }
    else
    {
      ans = mid;
      s = mid + 1;
    }
    mid = s + (e - s) / 2;
  }
  return mid;
}

int main()
{
  int num;
  cout << "Enter the number :\n";
  cin >> num;

  int ans = findSqrt(num);
  cout << "The square root of number is "
       << " " << ans << " " << endl;

  int precision;
  cout << "Enter the number of floating range :" << endl;
  cin >> precision;

  double step = 0.1;
  double finalAns = ans;
  for (int i = 0; i < precision; i++)
  {
    for (double j = finalAns; j * j <= num; j = j + step)
    {
      finalAns = j;
    }
    step = step / 10;
  }
  cout << "final ans is :" << finalAns << endl;

  return 0;
}