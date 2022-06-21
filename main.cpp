#include <iostream>
#include <omp.h>
#include <string>

using namespace std;

int
main()
{
  cout << "Number of threads: "s << omp_get_max_threads() << endl;

  long long n = 100000;

  cout << "we will form sum of numbers from 1 to " << n << endl;

  auto t0 = omp_get_wtime();

  long long s = 0LL;

#pragma omp parallel for reduction (+ : s)
  for (auto i = 1; i <=n; ++i)
  {
    s += i;
  }

  auto t1 = omp_get_wtime();

  cout << "sum: "s << s << endl;
  cout << "elapsed wall clock time: "s << t1 - t0 << " seconds"s << endl;

  return EXIT_SUCCESS;
}
