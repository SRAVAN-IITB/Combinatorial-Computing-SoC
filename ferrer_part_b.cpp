//  #### Enumerating number of partitions (with a twist)
#include<iostream>
using namespace std;
int calc_Q (int n, int k);
int calc_R (int n, int k);
int main()
{
    int n, k;
    cout<<"Let `Q(n,k)` denote the number of partitions in which the largest number is not more than `k`.\n "
          "For `n = 5, k = 3` these are `3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1` so `Q(5,3) = 5`. \n"
          "\n"
          "Let `R(n,k)` denote the number of partitions where the number of numbers is not more than `k`.\n"
          "For `n = 5, k = 3` it is `5, 4+1, 3+2, 3+1+1, 2+2+1` so `R(5,3) = 5`.\n"
          "Now, enter inputs `n', 'k' :"<<endl;
    cin>>n>>k;
    int n_input = n;
    int k_input = k;
    cout<<" Input: " <<n_input <<"\t" <<k_input <<"\n" <<"Output: " <<calc_Q(n,k) <<"\t" <<calc_R(n,k) <<endl;
}
int calc_Q(int n, int k)
{
    int total = 0;
    if (n == 0)
        return 1;
    if(n < 0)
        return 0;
    for (int i = k; i > 0; i--) {
        total += calc_Q((n-i),i);
    }
    return total;
}

  int calc_R (int n, int k)
  {
    int total = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (k == 0)
        return 0;
    for (int i = 0; i < (n+1); i++) {
        total += calc_R(n-i*k, k-1);
    }
    return total;
  }
//    -Sravan K Suresh {22B3936}
