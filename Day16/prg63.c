#include <stdio.h>

void findPair (int nums[], int n, int target)
{
  int flag = 0;

  for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
	{
	  if (nums[i] + nums[j] == target)
	    {
	      printf ("Pair found (%d, %d) \n", nums[i], nums[j]);
	      flag = 1;
	    }
	}
    }
  if (flag == 0)
    {
      printf ("Pair not found");
    }
}

int main ()
{
  int nums[] = {5, 2, 3, 4, 1, 6, 7};
  int target = 7;

  int n = sizeof (nums) / sizeof (nums[0]);

  findPair (nums, n, target);

  return 0;
}