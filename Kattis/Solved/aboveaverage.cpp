#include <iostream>
#include <iomanip>
using namespace std;

//https://open.kattis.com/problems/aboveaverage

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,N;
	cin>>n;
	while(n--){
		cin>>N;
		int scores[N];
		int temp = 0;
		for(int i=0;i<N;i++){
			cin>>scores[i];
			temp += scores[i];
		}
		int over = 0;
		int avg = temp/N;
		for(int i=0;i<N;i++){
			if(scores[i] > avg){
				over ++;
			}
		}

		double percent = (double) (int)(((double)over*100000/N) + 0.5)/1000;
		std::cout << std::fixed;
		std::cout << std::setprecision(3);
    cout << percent << "%\n";
	}

	return 0;
}
