#include<iostream>
// yaha suppose array sorted given hain toh time complexity-->n*n aati hain isliye 
// aagar array sorted hain toh phele unsort karte hain fir sort karte hain and it take(n*log*n) time complexity
#include<ctime>
using namespace std;
int partition(int *arr,int s,int e){
	int i=s-1;
	int pivot=arr[e];
	for(int j=s;j<=e-1;j++){
		if(arr[j]<=pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[e]);
	return i+1;
}
int suffle(int *arr,int s,int e){
	srand(time(0));
	int r=s+rand()%(e-s);//jo bhi range define karege usske beech hi no print honge
	swap(arr[r],arr[e]);//helps in suffling the array so as to get the ans in n log n time complexity
	return partition(arr,s,e);
}
void quick_sort(int *arr,int s,int e){
	//base case
	if(s>=e){
		return;
	}
	//recursive case
	int p=partition(arr,s,e);
	quick_sort(arr,s,p-1);
	quick_sort(arr,p+1,e);//tail recursion-->without return
// last call is of recursion agar iss recursion ke baad kuch bhi aata toh hum tail recursion nhi bolte 
// agar yeh last recursion return hora hota toh bolte non-tail recursion

}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Before"<<endl;
	for (int i = 0; i < n; ++i){
		cout<<arr[i]<<" ";
	}
	quick_sort(arr,0,n-1);
	cout<<endl;
	cout<<"after"<<endl;
	for (int i = 0; i < n; ++i){
		cout<<arr[i]<<" ";
	}
	// srand(time(0));//system ke according numbers aalag denga 

	// for(int i=0;i<n;i++){
	// 	cout<<rand()<<" ";
	// }
	return 0;
}