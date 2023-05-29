#include<iostream>
using namespace std;
int main()
{
	int parts, p[parts];
    cout<<" Enter the number of partitions of your number: "<<endl;
    cin>>parts;
    cout<<" Enter the partitions of your number: "<<endl;
    for(int i = 0; i < parts; i++)
        cin>>p[i];
	for( int i = 0; i < parts; i++ )       {
		for( int j = 0; j < p[i]; j++ )
		    cout<< "*";
		cout<<endl;
	}
}