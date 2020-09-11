#include <iostream>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,N;
	cin>>n;
	while(n--){
		cin>>N;
		int scores[N];
		int temp;
		for(int i=0;i<N;i++){
			cin>>scores[i];
			temp += scores[i];
		}
		int over;
		int avg = temp/N;
		for(int i=0;i<N;i++){
			if(scores[i] > avg){
				over ++;
			}
		}

		double percent = (double) over*100/N;
    cout << percent << "\n";
	}

	return 0;
}
